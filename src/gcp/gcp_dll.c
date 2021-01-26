#include "../core/jam.h"

char *classlibDefaultBootDllPath() {
    return CLASSPATH_INSTALL_DIR"/lib/classpath";
}

void *classlibLookupLoadedDlls(char *name, Object *loader) {
    return lookupLoadedDlls0(name, loader);
}
