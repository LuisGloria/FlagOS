#ifndef SYSCALL_TABLE_H
#define SYSCALL_TABLE_H

#include <stdint.h>

// Function pointer type for system calls
typedef int (*syscall_t)(void *);

// Array of system call functions
extern syscall_t syscall_table[];

// System call numbers
#define SYS_WRITE 0
#define SYS_READ  1

#endif // SYSCALL_TABLE_H
