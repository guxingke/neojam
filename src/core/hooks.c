#include "jam.h"

static int (*vfprintf_hook)(FILE *stream, const char *fmt, va_list ap);
static void (*exit_hook)(int status);

void jam_fprintf(FILE *stream, const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    (*vfprintf_hook)(stream, fmt, ap);

    va_end(ap);
}

void jamvm_exit(int status) {
    (*exit_hook)(status);
}

int initialiseHooks(InitArgs *args) {
    vfprintf_hook = args->vfprintf;
    exit_hook = args->exit;
    return TRUE;
}

