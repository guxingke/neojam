
#include <stdlib.h>

#include "jam.h"
#include "symbol.h"

#define SYMBOL_VALUE(name, value) value
char *symbol_values[] = {
    CLASSLIB_SYMBOLS_DO(SYMBOL_VALUE),
    SYMBOLS_DO(SYMBOL_VALUE)
};

int initialiseSymbol() {
    int i;

    for(i = 0; i < MAX_SYMBOL_ENUM; i++)
        if(symbol_values[i] != newUtf8(symbol_values[i])) {
            jam_fprintf(stderr, "Error when initialising VM symbols."
                                "  Aborting VM.\n");
            return FALSE;
        }

    return TRUE;
}
