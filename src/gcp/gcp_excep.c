#include "../core/jam.h"
#include "../core/symbol.h"

static Class *vmthrow_class;
static int backtrace_offset;

int classlibInitialiseException(Class *throw_class) {
    FieldBlock *backtrace = NULL;

    // java/lang/VMThrowable
    vmthrow_class = findSystemClass0(SYMBOL(java_lang_VMThrowable));
    if(vmthrow_class != NULL)
        backtrace = findField(vmthrow_class, SYMBOL(backtrace),
                              SYMBOL(sig_java_lang_Object));

    if(backtrace == NULL) {
        jam_fprintf(stderr, "Expected \"backtrace\" field missing in "
                            "java.lang.VMThrowable\n");
        return FALSE;
    }

    CLASS_CB(vmthrow_class)->flags |= VMTHROWABLE;
    backtrace_offset = backtrace->u.offset;

    registerStaticClassRef(&vmthrow_class);
    return TRUE;
}

Object *setStackTrace0(ExecEnv *ee, int max_depth) {
    Object *array = stackTrace(ee, max_depth);
    Object *vmthrwble = allocObject(vmthrow_class);

    if(vmthrwble != NULL)
        INST_DATA(vmthrwble, Object*, backtrace_offset) = array;

    return vmthrwble;
}

Object *convertStackTrace(Object *vmthrwble) {
    Object *array = INST_DATA(vmthrwble, Object*, backtrace_offset);

    if(array == NULL)
        return NULL;

    return stackTraceElements(array);
}

/* GC support for marking classes referenced by a VMThrowable.
   In rare circumstances a stack backtrace may hold the only
   reference to a class */

void markVMThrowable(Object *vmthrwble, int mark) {
    Object *array;

    if((array = INST_DATA(vmthrwble, Object*, backtrace_offset)) != NULL) {
        uintptr_t *src = ARRAY_DATA(array, uintptr_t);
        int i, depth = ARRAY_LEN(array);

        for(i = 0; i < depth; i += 2) {
            MethodBlock *mb = (MethodBlock*)src[i];
            markObject(mb->class, mark);
        }
    }
}
