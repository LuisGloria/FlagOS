#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

#define MAX_PROCESSES 256  // Maximum number of processes

typedef enum {
    PROCESS_RUNNING,
    PROCESS_READY,
    PROCESS_WAITING,
    PROCESS_TERMINATED
} process_state_t;

typedef struct {
    uint32_t *stack;            // Pointer to the process's stack
    uint32_t *program_counter;  // Pointer to the process's instruction
    uint32_t *base_pointer;     // Base pointer for stack frames
    uint32_t id;                // Process ID
    process_state_t state;      // Current state of the process
    // Additional fields as needed
} process_t;

void process_init();
void process_create(void (*entry_point)(), uint32_t *stack, uint32_t stack_size);
void process_switch();
void process_terminate(uint32_t process_id);

#endif // PROCESS_H
