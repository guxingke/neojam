#include "jam.h"
#include "sig.h"
#include "frame.h"
#include "lock.h"
#include "symbol.h"
#include "excep.h"
#include "properties.h"
#include "jni-internal.h"

#define VA_DOUBLE(args, sp)                                 \
    if(*sig == 'D')                                         \
        *(double*)sp = va_arg(args, double);                \
    else                                                    \
        *(u8*)sp = va_arg(args, u8);                        \
    sp+=2

#define VA_SINGLE(args, sp)                                 \
    if(*sig == 'L' || *sig == '[')                          \
        *sp = va_arg(args, uintptr_t) & ~REF_MASK;          \
    else                                                    \
        if(*sig == 'F')                                     \
            *((float*)sp + IS_BE64) = va_arg(args, double); \
        else                                                \
            *sp = va_arg(args, u4);                         \
    sp++

#define JA_DOUBLE(args, sp)  *(u8*)sp = *args++; sp+=2
#define JA_SINGLE(args, sp)                                 \
    switch(*sig) {                                          \
        case 'L': case '[':                                 \
            *sp = *(uintptr_t*)args & ~REF_MASK;            \
            break;                                          \
        case 'F':                                           \
            *((float*)sp + IS_BE64) = *(float*)args;        \
            break;                                          \
        case 'B': case 'Z':                                 \
            *sp = *(signed char*)args;                      \
            break;                                          \
        case 'C':                                           \
            *sp = *(unsigned short*)args;                   \
            break;                                          \
        case 'S':                                           \
            *sp = *(signed short*)args;                     \
            break;                                          \
        case 'I':                                           \
            *sp = *(signed int*)args;                       \
            break;                                          \
    }                                                       \
    sp++; args++

#define ADJUST_RET_ADDR(ret_addr, ret_type) ({              \
    char *adjusted = ret_addr;                              \
    if(IS_BIG_ENDIAN) {                                     \
        int size;                                           \
        switch(ret_type) {                                  \
            case 'B': case 'Z':                             \
                size = sizeof(uintptr_t) - 1;               \
                break;                                      \
            case 'C': case 'S':                             \
                size = sizeof(uintptr_t) - 2;               \
                break;                                      \
            case 'I': case 'F':                             \
                size = sizeof(uintptr_t) - 4;               \
                break;                                      \
            default:                                        \
                size = 0;                                   \
                break;                                      \
        }                                                   \
        adjusted += size;                                   \
    }                                                       \
    adjusted;                                               \
})

void *executeMethodArgs(Object *ob, Class *class, MethodBlock *mb, ...) {
    va_list jargs;
    void *ret;

    va_start(jargs, mb);
    ret = executeMethodVaList(ob, class, mb, jargs);
    va_end(jargs);

    return ret;
}

void *executeMethodVaList(Object *ob, Class *class, MethodBlock *mb,
                          va_list jargs) {

    ExecEnv *ee = getExecEnv();
    char *sig = mb->type;
    uintptr_t *sp;
    void *ret;


//    CREATE_TOP_FRAME(ee, class, mb, sp, ret);
    // 手动宏展开
    {
        // 以 main 方法的调用为例，栈在内存的布局如下, sizeof(Frame) -> 40 -> 0x28
        // last -> mb -> max_stack = 0 , mb -> max_stack = 3 , mb -> max_locals = 3
        // | last | dummy | new |
        // | 40 B | 40 B  | 24 B locals | 40 B frame    | 24 B ostack |
        //                | <-- ret(sp)     | <-- new_frame
        Frame *last = ee->last_frame;
        Frame *dummy = (Frame *) (last->ostack + last->mb->max_stack);
        Frame *new_frame;
        uintptr_t *new_ostack;

        // ret 的地址是新栈帧的本地变量表的首地址，因此可以推测，解释器执行时的返回逻辑，需要将操作数栈上的值赋值到本地变量表
        ret = (void *) (sp = (uintptr_t *) (dummy + 1));
        new_frame = (Frame *) (sp + mb->max_locals);
        // 8 字节对齐
        new_ostack = ALIGN_OSTACK(new_frame + 1);

        if ((char *) (new_ostack + mb->max_stack) > ee->stack_end) {
            if (ee->overflow++) {
                /* Overflow when we're already throwing stack
                   overflow.  Stack extension should be enough
                   to throw exception, so something's seriously
                   gone wrong - abort the VM! */
                printf("Fatal stack overflow!  Aborting VM.\n");
                exitVM(1);
            }
            ee->stack_end += STACK_RED_ZONE_SIZE;
            signalException(java_lang_StackOverflowError, NULL);
            return NULL;
        }

        dummy->mb = NULL;
        // 这个 dummy -> ostack = sp 赋值了，但似乎没啥用
        dummy->ostack = sp;
        dummy->prev = last;

        new_frame->mb = mb;
        new_frame->lvars = sp;
        new_frame->ostack = new_ostack;

        new_frame->prev = dummy;
        ee->last_frame = new_frame;
    }
    // END

    /* copy args onto stack */

    if (ob)
        *sp++ = (uintptr_t) ob; /* push receiver first */

    // 准备参数
//    SCAN_SIG(sig, VA_DOUBLE(jargs, sp), VA_SINGLE(jargs, sp))
    // 准备参数 demacro
    // 往本地变量表里写参数
    sig++;               /* skip start ( */
    while (*sig != ')') {
        if ((*sig == 'J') || (*sig == 'D')) {
            if (*sig == 'D')
                *(double *) sp = va_arg(jargs, double);
            else
                *(u8 *) sp = va_arg(jargs, u8);
            sp += 2;
            sig++;
        } else {
            if (*sig == 'L' || *sig == '[')
                *sp = va_arg(jargs, uintptr_t) & ~REF_MASK;
            else if (*sig == 'F')
                *((float *) sp + IS_BE64) = va_arg(jargs, double);
            else
                *sp = va_arg(jargs, u4);
            sp++;
            if (*sig == '[')
                for (sig++; *sig == '['; sig++);
            if (*sig == 'L')
                while (*sig++ != ';');
            else
                sig++;
        }
    }
    sig++;               /* skip end ) */
    // END

    if (mb->access_flags & ACC_SYNCHRONIZED)
        objectLock(ob ? ob : mb->class);

    if (mb->access_flags & ACC_NATIVE) {
        ClassBlock *cb = CLASS_CB(class);
//        jam_printf("native call %s.%s%s\n", cb->name, mb->name, mb->type);
        (*mb->native_invoker)(class, mb, ret);
    } else {
        ClassBlock *cb = CLASS_CB(class);
//        jam_printf("java call %s.%s%s\n", cb->name, mb->name, mb->type);
        executeJava();
    }

    if (mb->access_flags & ACC_SYNCHRONIZED)
        objectUnlock(ob ? ob : mb->class);

//    POP_TOP_FRAME(ee);
    // demacro
    ee->last_frame = ee->last_frame->prev->prev;
    // END

    return ADJUST_RET_ADDR(ret, *sig);
}

void *executeMethodList(Object *ob, Class *class, MethodBlock *mb, u8 *jargs) {
    char *sig = mb->type;

    ExecEnv *ee = getExecEnv();
    uintptr_t *sp;
    void *ret;

    // 强制内联
    CREATE_TOP_FRAME(ee, class, mb, sp, ret);

    /* copy args onto stack */

    if (ob)
        *sp++ = (uintptr_t) ob; /* push receiver first */

    SCAN_SIG(sig, JA_DOUBLE(jargs, sp), JA_SINGLE(jargs, sp))

    if (mb->access_flags & ACC_SYNCHRONIZED)
        objectLock(ob ? ob : mb->class);

    if (mb->access_flags & ACC_NATIVE)
        (*mb->native_invoker)(class, mb, ret);
    else
        executeJava();

    if (mb->access_flags & ACC_SYNCHRONIZED)
        objectUnlock(ob ? ob : mb->class);

    POP_TOP_FRAME(ee);

    return ADJUST_RET_ADDR(ret, *sig);
}

