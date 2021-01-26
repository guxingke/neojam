#include "jam.h"
#include "sig.h"

int sigElement2Size(char element) {
    switch(element) {
        case 'B':
        case 'Z':
            return 1;

        case 'C':
        case 'S':
            return 2;

        case 'I':
        case 'F':
           return 4;

        case 'L':
        case '[':
            return sizeof(Object*);

        default:
            return 8;
    }
}

int sigArgsCount(char *sig) {
    int count = 0;

    SCAN_SIG(sig, count+=2, count++);

    return count;
}
