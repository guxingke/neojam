
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/sysctl.h>
#include <pthread.h>

#include "../core/jam.h"

void *nativeStackBase() {
    return pthread_get_stackaddr_np(pthread_self());
}

int nativeAvailableProcessors() {
    int processors, mib[2];
    size_t len = sizeof(processors);

    mib[0] = CTL_HW;
    mib[1] = HW_AVAILCPU;

    if(sysctl(mib, 2, &processors, &len, NULL, 0) == -1)
        return 1;
    else
        return processors;
}

char *nativeLibError() {
    return dlerror();
}

char *nativeLibPath() {
    return getenv("LD_LIBRARY_PATH");
}

/* GNU Classpath's libraries end in .dylib because it
   uses libtool, but JNI libraries normally end in
   .jnilib under Mac OS X.  We try both.

   On Mac OS X/Intel libtool seems to use a .so ending.
   This is wrong, but a workaround for now is to _also_
   try .so! 
*/

void *nativeLibOpen(char *path) {
    void *handle;

    if((handle = dlopen(path, RTLD_LAZY)) == NULL) {
        int len = strlen(path);
        char buff[len + sizeof(".jnilib") + 1];
     
        strcpy(buff, path);
        strcpy(buff + len, ".dylib");

        if((handle = dlopen(buff, RTLD_LAZY)) == NULL) {
            strcpy(buff + len, ".jnilib");

            if((handle = dlopen(buff, RTLD_LAZY)) == NULL) {
                strcpy(buff + len, ".so");

                handle = dlopen(buff, RTLD_LAZY);
            }
        }
    }
    return handle;
}

void nativeLibClose(void *handle) {
    dlclose(handle);
}

void *nativeLibSym(void *handle, char *symbol) {
    return dlsym(handle, symbol);
}

char *nativeLibMapName(char *name) {
   char *buff = sysMalloc(strlen(name) + sizeof("lib") + 1);

   sprintf(buff, "lib%s", name);
   return buff;
}

char *nativeJVMPath() {
    Dl_info info;
    char *path;

    if(dladdr(nativeJVMPath, &info) == 0) {
        printf("Error: dladdr failed.  Aborting VM\n");
        exitVM(1);
    }

    path = sysMalloc(strlen(info.dli_fname) + 1);
    strcpy(path, info.dli_fname);

    return path;
}

long long nativePhysicalMemory() {
    return 0; /* TBD */
}
