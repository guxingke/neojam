
#ifndef KKK_EXCEP_H
#define KKK_EXCEP_H

// #include "classlib-excep.h"
#define CLASSLIB_EXCEPTIONS_DO(action)
// end

#define EXCEPTIONS_DO(action) \
    action(java_lang_LinkageError), \
    action(java_lang_InternalError), \
    action(java_lang_ClassFormatError), \
    action(java_lang_NoSuchFieldError), \
    action(java_lang_OutOfMemoryError), \
    action(java_lang_NoSuchMethodError), \
    action(java_lang_InstantiationError), \
    action(java_lang_IllegalAccessError), \
    action(java_lang_ClassCastException), \
    action(java_lang_StackOverflowError), \
    action(java_lang_ArithmeticException), \
    action(java_lang_AbstractMethodError), \
    action(java_lang_ArrayStoreException), \
    action(java_lang_NullPointerException), \
    action(java_lang_NoClassDefFoundError), \
    action(java_lang_UnsatisfiedLinkError), \
    action(java_lang_InterruptedException), \
    action(java_lang_InstantiationException), \
    action(java_lang_ClassNotFoundException), \
    action(java_lang_IllegalAccessException), \
    action(java_lang_IllegalArgumentException), \
    action(java_lang_NegativeArraySizeException), \
    action(java_lang_IllegalThreadStateException), \
    action(java_lang_IllegalMonitorStateException), \
    action(java_lang_IncompatibleClassChangeError), \
    action(java_lang_ArrayIndexOutOfBoundsException), \
    action(java_lang_StringIndexOutOfBoundsException)

#define EXCEPTION_ENUM(name) exception_##name

enum {
    CLASSLIB_EXCEPTIONS_DO(EXCEPTION_ENUM)
    EXCEPTIONS_DO(EXCEPTION_ENUM),
    MAX_EXCEPTION_ENUM
};

#endif //KKK_EXCEP_H
