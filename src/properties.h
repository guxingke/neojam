
#ifndef KKK_PROPERTIES_H
#define KKK_PROPERTIES_H
#ifdef HAVE_ENDIAN_H
#include <endian.h>
#elif HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#if defined BYTE_ORDER
#if BYTE_ORDER == BIG_ENDIAN
#define IS_BIG_ENDIAN TRUE
#else
#define IS_BIG_ENDIAN FALSE
#endif
#elif defined _BIG_ENDIAN
#define IS_BIG_ENDIAN TRUE
#elif defined _LITTLE_ENDIAN
#define IS_BIG_ENDIAN FALSE
#else
#define IS_BIG_ENDIAN ({                                           \
    /* No byte-order macro -- work it out ourselves at runtime */  \
    union {                                                        \
        int i;                                                     \
        char c[sizeof(int)];                                       \
    } u;                                                           \
    u.i = 1;                                                       \
    u.c[sizeof(int)-1] == 1;                                       \
})
#endif

#define IS_BE64 (sizeof(uintptr_t) == 8 && IS_BIG_ENDIAN)

#endif //KKK_PROPERTIES_H
