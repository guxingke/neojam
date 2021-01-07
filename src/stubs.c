
#ifndef GEN_STUBS_INC
#include "jam.h"
#endif

#if defined(GEN_STUBS_INC) || !defined(USE_MD_STUBS)
#include <string.h>

static char mapSigElement2Simple(char element) {
    switch(element) {
        case 'J':
        case 'D':
        case 'F':
            return element;

        default:
            return 'I';
    }
}

static char mapRet2Simple(char element) {
    switch(element) {
        case 'Z':
            return 'B';

        case '[':
            return 'L';

        default:
            return element;
    }
}

char *convertSig2Simple(char *sig) {
    char *simple_sig = sysMalloc(strlen(sig) + 1);
    char *simple_pntr = simple_sig;
    char *sig_pntr = sig;

    *simple_pntr++ = '(';
    while(*++sig_pntr != ')') {
        *simple_pntr++ = mapSigElement2Simple(*sig_pntr);

        if(*sig_pntr == '[')
            while(*++sig_pntr == '[');
        if(*sig_pntr == 'L')
            while(*++sig_pntr != ';');
    }

    *simple_pntr++ = ')';
    *simple_pntr++ = mapRet2Simple(*++sig_pntr);
    *simple_pntr++ = '\0';

    return sysRealloc(simple_sig, simple_pntr - simple_sig);
}
#endif

