#include "jam.h"
#include "hash.h"
#include "class.h"
#include "thread.h"
#include "classlib.h"

int initialiseFrame() {
    if (!classlibInitialiseFrame()) {
        jam_fprintf(stderr, "Error initialising VM (initialiseFrame)\n");
        return FALSE;
    }

    return TRUE;
}

Class *getCallerClass(int depth) {
    Frame *last = getExecEnv()->last_frame;

    if (last->prev == NULL)
        return NULL;

    if ((last = classlibGetCallerFrame(last, depth)) == NULL)
        return NULL;

    return last->mb->class;
}

Object *getClassContext() {
    Class *class_class = findArrayClass("[Ljava/lang/Class;");
    Frame *last = getExecEnv()->last_frame;
    Frame *bottom = last;
    Object *array;
    int depth = 0;

    if (class_class == NULL)
        return NULL;

    if (last->prev == NULL)
        return allocArray(class_class, 0, sizeof(Class *));

    for (; last != NULL; last = classlibGetCallerFrame(last, 1))
        if (!(last->mb->access_flags & ACC_NATIVE))
            depth++;

    array = allocArray(class_class, depth, sizeof(Class *));

    if (array != NULL) {
        Class **data = ARRAY_DATA(array, Class*);

        for (; bottom != NULL; bottom = classlibGetCallerFrame(bottom, 1))
            if (!(bottom->mb->access_flags & ACC_NATIVE))
                *data++ = bottom->mb->class;
    }

    return array;
}

Object *firstNonNullClassLoader() {
    Frame *last = getExecEnv()->last_frame;

    if (last->prev != NULL)
        do {
            for (; last->mb != NULL; last = last->prev)
                if (!classlibIsSkippedReflectFrame(last)) {
                    Object *loader = CLASS_CB(last->mb->class)->class_loader;
                    if (loader != NULL)
                        return loader;
                }
        } while ((last = last->prev)->prev != NULL);

    return NULL;
}

