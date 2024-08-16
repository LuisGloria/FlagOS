#include "syscalls.h"

// Array of system call functions
typedef int (*syscall_t)(void *);

syscall_t syscall_table[] = {
    [SYS_WRITE] = (syscall_t)sys_write,
    [SYS_READ]  = (syscall_t)sys_read
};
