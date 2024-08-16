#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

#define SYS_WRITE 0
#define SYS_READ  1

int sys_write(const char *buf, uint32_t len);
int sys_read(char *buf, uint32_t len);

#endif
