#include "jam.h"

void shutdownVM() {
    shutdownInterpreter();
    shutdownDll();
}

