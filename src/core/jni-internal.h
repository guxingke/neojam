
#ifndef KKK_JNI_INTERNAL_H
#define  KKK_JNI_INTERNAL_H

#define REF_MASK         0x3
#define GLOBAL_REF       0x2
#define WEAK_GLOBAL_REF  0x1
#define LOCAL_REF        0x0

/* The tag is also used as the index into the list of
   global ref tables.  As local refs are instead stored
   in the JNI frame, we use idx 0 for cleared weak refs,
   even though no object is ever tagged as such */
#define CLEARED_WEAK_REF 0x0

#define REF_TO_OBJ_WEAK_NULL_CHECK(ref) ({           \
    Object *_obj = REF_TO_OBJ(ref);                  \
    if(REF_TYPE(ref) == WEAK_GLOBAL_REF)             \
        _obj = isPlaceholderObj(_obj) ? NULL : _obj; \
    _obj;                                            \
})

#define REF_TYPE(ref)   (((uintptr_t)(ref))&REF_MASK)
#define REF_TO_OBJ(ref) ((Object*)(((uintptr_t)(ref))&~REF_MASK))
#define OBJ_TO_REF(ref, ref_type) ((jobject)(((uintptr_t)(ref))|ref_type))

#endif