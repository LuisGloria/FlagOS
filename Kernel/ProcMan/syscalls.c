#include "process.h"
#include "heap.h"

void sys_create_process(void (*entry_point)(), uint32_t *stack, uint32_t stack_size) {
    process_create(entry_point, stack, stack_size);
}

void sys_terminate_process(uint32_t process_id) {
    process_terminate(process_id);
}
