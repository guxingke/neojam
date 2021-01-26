
#ifndef KKK_ARCH_H
#define KKK_ARCH_H

#define OS_ARCH "amd64"

/* On x86_64 prior to gcc 4.3, return types less than 4 bytes in size
   were zero or sign extended.  This no longer happens, and so when
   calling a method through FFI, we need to do the extension.  This
   is unnecessary on most architectures */
#define FFI_RET_EXTEND

/* The idivl instruction generates an exception on integer divide
   overflow (INT_MIN/-1 can't be represented as a positive number) */
#define CHECK_INTDIV_OVERFLOW

/* Similarly, the idivq instruction generates an exception on long
   divide overflow (LLONG_MIN/-1) */
#define CHECK_LONGDIV_OVERFLOW

#define HANDLER_TABLE_T static const void
#define DOUBLE_1_BITS 0x3ff0000000000000LL

#define READ_DBL(v, p, l)    v = ((u8)p[0]<<56)|((u8)p[1]<<48)|((u8)p[2]<<40)  \
                            |((u8)p[3]<<32)|((u8)p[4]<<24)|((u8)p[5]<<16) \
                            |((u8)p[6]<<8)|(u8)p[7]; p+=8

extern void setDoublePrecision();

#define FPU_HACK setDoublePrecision()

#define COMPARE_AND_SWAP_64(addr, old_val, new_val) \
({                                                  \
    char result;                                    \
    __asm__ __volatile__ ("                         \
        lock;                                       \
        cmpxchgq %4, %1;                            \
        sete %0"                                    \
    : "=q" (result), "=m" (*addr)                   \
    : "m" (*addr), "a" ((uintptr_t)old_val),        \
      "r" ((uintptr_t)new_val)                      \
    : "memory");                                    \
    result;                                         \
})

#define COMPARE_AND_SWAP_32(addr, old_val, new_val) \
({                                                  \
    char result;                                    \
    __asm__ __volatile__ ("                         \
        lock;                                       \
        cmpxchgl %4, %1;                            \
        sete %0"                                    \
    : "=q" (result), "=m" (*addr)                   \
    : "m" (*addr), "a" (old_val), "r" (new_val)     \
    : "memory");                                    \
    result;                                         \
})

#define COMPARE_AND_SWAP(addr, old_val, new_val)             \
        COMPARE_AND_SWAP_64(addr, old_val, new_val)

#define LOCKWORD_READ(addr) *addr
#define LOCKWORD_WRITE(addr, value) *addr = value
#define LOCKWORD_COMPARE_AND_SWAP(addr, old_val, new_val)    \
        COMPARE_AND_SWAP_64(addr, old_val, new_val)

#define __GEN_REL_JMP(target_addr, patch_addr, opcode, \
                      type, patch_size)                      \
({                                                           \
    int patched = FALSE;                                     \
                                                             \
    if(patch_size >= 1 + sizeof(type)) {                     \
        char *nxt_ins_ptr = (patch_addr) + 1 + sizeof(type); \
        uintptr_t limit = 1ULL<<((sizeof(type) * 8) - 1);    \
                                                             \
        /* The check is done in two parts to ensure the      \
           result is always positive, to guard against       \
           the pointer difference being larger than the      \
           signed range */                                   \
        if(target_addr > nxt_ins_ptr) {                      \
            uintptr_t disp = (target_addr) - (nxt_ins_ptr);  \
                                                             \
            if(disp < limit) {                               \
                *(patch_addr) = opcode;                      \
                *(type*)&(patch_addr)[1] = disp;             \
                patched = TRUE;                              \
            }                                                \
        } else {                                             \
            uintptr_t disp = (nxt_ins_ptr) - (target_addr);  \
                                                             \
            if(disp <= limit) {                              \
                *(patch_addr) = opcode;                      \
                *(type*)&(patch_addr)[1] = -disp;            \
                patched = TRUE;                              \
            }                                                \
        }                                                    \
    }                                                        \
    patched;                                                 \
})

#define GEN_REL_JMP(target_addr, patch_addr, patch_size) \
({                                                       \
    __GEN_REL_JMP(target_addr, patch_addr, 0xeb,         \
                  signed char, patch_size) ||            \
    __GEN_REL_JMP(target_addr, patch_addr, 0xe9,         \
                  signed int, patch_size);               \
})

#define FLUSH_CACHE(addr, length)

// ---
// 聊聊原子变量、锁、内存屏障那点事 https://www.0xffffff.org/2017/02/21/40-atomic-variable-mutex-and-memory-barrier/

// 内存屏障
// 防止指令之间的重排序
// 保证数据的可见性

// 保证了mfence前后的Store和Load指令的顺序，防止Store和Load重排序
// 保证了mfence之后的Store指令全局可见之前，mfence之前的Store指令要先全局可见
#define MBARRIER()  __asm__ __volatile__ ("mfence" ::: "memory")
// 保证了lfence前后的Load指令的顺序，防止Load重排序
// 刷新Load Buffer
#define RMBARRIER() __asm__ __volatile__ ("lfence" ::: "memory")
// 保证了sfence前后Store指令的顺序，防止Store重排序
// 通过刷新Store Buffer保证sfence之前的Store要指令对全局可见
#define WMBARRIER() __asm__ __volatile__ ("sfence" ::: "memory")

// 优化屏障 避免编译器的重排序优化操作，保证编译程序时在优化屏障之前的指令不会在优化屏障之后执行。这就保证了编译时期的优化不会影响到实际代码逻辑顺序

// 内存信息已经修改，屏障后的寄存器的值必须从内存中重新获取
// 必须按照代码顺序产生汇编代码，不得越过屏障
#define JMM_LOCK_MBARRIER()   __asm__ __volatile__ ("" ::: "memory")
#define JMM_UNLOCK_MBARRIER() __asm__ __volatile__ ("" ::: "memory")

// END---

#endif //KKK_ARCH_H
