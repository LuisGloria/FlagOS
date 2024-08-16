#include "syscalls.h"
#include <sys/types.h>

int write(const char *buf, size_t len) {
    return sys_write(buf, len);
}

int read(char *buf, size_t len) {
    return sys_read(buf, len);
}

//This is Chugin.
//No.