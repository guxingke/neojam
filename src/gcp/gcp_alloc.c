#include "../core/jam.h"
#include "../core/thread.h"
#include "gcp.h"

#ifdef TRACEGC
#define TRACE(fmt, ...) jam_printf(fmt, ## __VA_ARGS__)
#else
#define TRACE(fmt, ...)
#endif

void classlibMarkSpecial(Object *ob, int mark) {
    if (IS_VMTHROWABLE(CLASS_CB(ob->class))) {
        TRACE("Mark found VMThrowable object @%p\n", ob);
        markVMThrowable(ob, mark);
    }
}

void classlibHandleUnmarkedSpecial(Object *ob) {
    if (IS_VMTHREAD(CLASS_CB(ob->class))) {
        /* Free the native thread structure (see comment
           in detachThread (thread.c) */
        TRACE("FREE: Freeing native thread for VMThread object %p\n", ob);
        gcPendingFree(vmThread2Thread(ob));
    }
}
