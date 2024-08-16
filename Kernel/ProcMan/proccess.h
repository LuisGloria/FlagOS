#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESSES 256

typedef enum {
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_BLOCKED,
    PROCESS_TERMINATED
} process_state_t;

typedef struct process {
    uint32_t id;
    process_state_t state;
    uint32_t priority;
    uint32_t *stack;
    uint32_t *program_counter;
    uint32_t *base_pointer;
    // Additional fields as needed
} process_t;

void process_create(void (*entry_point)(), uint32_t *stack, uint32_t stack_size);
void process_terminate(uint32_t process_id);

#endif
