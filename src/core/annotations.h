
#ifndef KKK_ANNOTATIONS_H
#define KKK_ANNOTATIONS_H

#define getClassAnnotationData(class) \
    CLASS_EXTRA_ATTRIBUTES(class, class_annos)

#define getClassTypeAnnotationData(class) \
    CLASS_EXTRA_ATTRIBUTES(class, class_type_annos)

#define getMethodAnnotationData(mb) \
    METHOD_EXTRA_ATTRIBUTES(mb, method_annos)

#define getMethodTypeAnnotationData(mb) \
    METHOD_EXTRA_ATTRIBUTES(mb, method_type_annos)

#define getMethodParameterAnnotationData(mb) \
    METHOD_EXTRA_ATTRIBUTES(mb, method_parameter_annos)

#define getMethodDefaultValueAnnotationData(mb) \
    METHOD_EXTRA_ATTRIBUTES(mb, method_anno_default_val)

#define getFieldAnnotationData(fb) \
    FIELD_EXTRA_ATTRIBUTES(fb, field_annos)

#define getFieldTypeAnnotationData(fb) \
    FIELD_EXTRA_ATTRIBUTES(fb, field_type_annos)

#endif //KKK_ANNOTATIONS_H
