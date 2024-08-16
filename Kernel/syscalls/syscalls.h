#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stdint.h>

// Define the system call numbers
#define SYS_WRITE 0
#define SYS_READ  1

// System call function prototypes
int sys_write(const char *buf, uint32_t len);
int sys_read(char *buf, uint32_t len);

#endif // SYSCALLS_H
