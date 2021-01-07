
#ifndef KKK_STUBS_H
#define KKK_STUBS_H

typedef struct jni_stub {
    char *signature;
    NativeMethod func;
#ifdef HAVE_PROFILE_STUBS
    unsigned int profile_count;
#endif
} JNIStub;

extern JNIStub jni_stubs[];
extern JNIStub jni_static_stubs[];

#endif