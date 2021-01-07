
#ifndef KKK_FRAME_H
#define KKK_FRAME_H
#define ALIGN_OSTACK(pntr) (uintptr_t*)(((uintptr_t)(pntr) + 7) & ~7)

#define CREATE_TOP_FRAME(ee, class, mb, sp, ret)                \
{                                                               \
    Frame *last = ee->last_frame;                               \
    Frame *dummy = (Frame *)(last->ostack+last->mb->max_stack); \
    Frame *new_frame;                                           \
    uintptr_t *new_ostack;                                      \
                                                                \
    ret = (void*) (sp = (uintptr_t*)(dummy+1));                 \
    new_frame = (Frame *)(sp + mb->max_locals);                 \
    new_ostack = ALIGN_OSTACK(new_frame + 1);                   \
                                                                \
    if((char*)(new_ostack + mb->max_stack) > ee->stack_end) {   \
        if(ee->overflow++) {                                    \
            /* Overflow when we're already throwing stack       \
               overflow.  Stack extension should be enough      \
               to throw exception, so something's seriously     \
               gone wrong - abort the VM! */                    \
            printf("Fatal stack overflow!  Aborting VM.\n");    \
            exitVM(1);                                          \
        }                                                       \
        ee->stack_end += STACK_RED_ZONE_SIZE;                   \
        signalException(java_lang_StackOverflowError, NULL);    \
        return NULL;                                            \
    }                                                           \
                                                                \
    dummy->mb = NULL;                                           \
    dummy->ostack = sp;                                         \
    dummy->prev = last;                                         \
                                                                \
    new_frame->mb = mb;                                         \
    new_frame->lvars = sp;                                      \
    new_frame->ostack = new_ostack;                             \
                                                                \
    new_frame->prev = dummy;                                    \
    ee->last_frame = new_frame;                                 \
}

#define POP_TOP_FRAME(ee)                                       \
    ee->last_frame = ee->last_frame->prev->prev;

#endif //KKK_FRAME_H
