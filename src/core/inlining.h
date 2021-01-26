
#ifndef KKK_INLINING_H
#define KKK_INLINING_H

#define LABELS_SIZE  256
#define GOTO_START   230
#define GOTO_END     255

#ifdef USE_CACHE
#define HANDLERS      3
#define ENTRY_LABELS  0
#define START_LABELS  3
#define END_LABELS    6
#define BRANCH_LABELS 9
#else
#define HANDLERS      1
#define ENTRY_LABELS  0
#define START_LABELS  1
#define END_LABELS    2
#define BRANCH_LABELS 3
#endif

/* Number of entries in the branch patch table */
#define BRANCH_NUM    16

#define MEMCMP_FAILED    -1
#define END_REORDERED    -2
#define END_BEFORE_ENTRY -3

#define FALLTHROUGH 1
#define HANDLER     2
#define TARGET      4
#define END         8

#ifdef INLINING
extern uintptr_t *executeJava2();
extern int calculateRelocatability(int handler_sizes[HANDLERS][LABELS_SIZE]);
#endif

#endif //KKK_INLINING_H
