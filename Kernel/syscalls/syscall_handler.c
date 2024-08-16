#include "syscall_table.h"
#include <stdint.h>

// System call handler
void syscall_handler(uint32_t syscall_number, void *args) {
    if (syscall_number < sizeof(syscall_table) / sizeof(syscall_t)) {
        syscall_table[syscall_number](args);
    } else {
        // Handle invalid system call number
    }
}
