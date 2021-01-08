
#include "../jam.h"
#include "../thread.h"
#include "../reflect.h"
#include "gcp.h"

/* The function classlibGetCallerFrame() is used in code that does
   security related stack-walking.  It guards against invocation
   via reflection.  These frames must be skipped, else it will
   appear that the caller was loaded by the boot loader. */

Frame *classlibGetCallerFrame(Frame *last, int depth) {
    for (;;) {
        /* Loop until the required number of frames have been skipped
           or we hit a dummy frame (top of this invocation) */
        for (; last->mb != NULL; last = last->prev)
            if (depth-- <= 0)
                return last;

        /* Skip the dummy frame, and check if we're
           at the top of the stack */
        if ((last = last->prev)->prev == NULL)
            return NULL;

        /* Check if we were invoked via reflection */
        if (last->mb->class == getReflectMethodClass()) {
            /* There will be two frames for invoke */
            last = last->prev->prev;
        }
    }
}
