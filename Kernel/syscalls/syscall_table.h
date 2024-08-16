#ifndef SYSCALL_TABLE_H
#define SYSCALL_TABLE_H

#include <stdint.h>

typedef int (*syscall_t)(void *);

extern syscall_t syscall_table[];

#define SYS_WRITE 0
#define SYS_READ  1

#endif
