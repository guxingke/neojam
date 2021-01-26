
#ifndef KKK_MYCLIB_H
#define KKK_MYCLIB_H

// gun classpath

#include "../core/jam.h"
#include "../core/thread.h"

#define IS_VMTHREAD(cb)    (cb->flags & VMTHREAD)
#define IS_VMTHROWABLE(cb) (cb->flags & VMTHROWABLE)

extern Object *getVMConsParamTypes(Object *vm_cons_obj);

extern Object *getVMMethodParamTypes(Object *vm_method_obj);

extern Class *getVMMethodReturnType(Object *vm_method_obj);

extern Class *getVMFieldType(Object *vm_field_obj);

extern MethodBlock *getVMConsMethodBlock(Object *cons_ref_obj);

extern int getVMConsAccessFlag(Object *cons_ref_obj);

extern MethodBlock *getVMMethodMethodBlock(Object *mthd_ref_obj);

extern int getVMMethodAccessFlag(Object *mthd_ref_obj);

extern FieldBlock *getVMFieldFieldBlock(Object *fld_ref_obj);

extern int getVMFieldAccessFlag(Object *fld_ref_obj);

extern Object *getClassAnnotations(Class *class);

extern Object *getFieldAnnotations(FieldBlock *fb);

extern Object *getMethodAnnotations(MethodBlock *mb);

extern Object *getMethodParameterAnnotations(MethodBlock *mb);

extern Object *getMethodDefaultValue(MethodBlock *mb);

extern Class *getReflectMethodClass();

extern Thread *vmThread2Thread(Object *vmThread);

extern void markVMThrowable(Object *vmthrwble, int mark);

#endif //KKK_MYCLIB_H
