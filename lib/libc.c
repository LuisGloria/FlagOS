#include "libc.h"
#include <stdarg.h>

int printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    va_end(args);
    return 0;
}

int scanf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    va_end(args);
    return 0; //returns 0
}
