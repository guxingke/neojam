
#ifndef KKK_NATIVES_H
#define KKK_NATIVES_H

#include "jam.h"

typedef struct vm_method {
    char *methodname;
    char *methodtype;
    NativeMethod method;
} VMMethod;

typedef struct vm_class {
    char *classname;
    VMMethod *methods;
} VMClass;

extern VMClass native_methods[];

#endif //KKK_NATIVES_H
