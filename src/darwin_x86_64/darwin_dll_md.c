#include "../core/jam.h"

#ifndef USE_FFI
#include <stdio.h>

int nativeExtraArg(MethodBlock *mb) {
    char *sig = mb->type;
    int stack_space;
    int iargs = 0;
    int fargs = 0;

    while(*++sig != ')')
        switch(*sig) {
            case 'D':
            case 'F':
                fargs++;
                break;

            default:
                iargs++;

                if(*sig == '[')
                    while(*++sig == '[');
                if(*sig == 'L')
                    while(*++sig != ';');
                break;
        }

    stack_space = ((iargs > 4 ? iargs - 4 : 0) +
                   (fargs > 8 ? fargs - 8 : 0)) << 3;

    /* Ensure the stack remains 16 byte aligned.  As
       callJNIMethod pushes an even number of registers
       the extra space must also be even. */
    return (stack_space + 15) & ~15;
}

#endif
