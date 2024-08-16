#include "proccess.h"
#include <string.h>
#include "heap.h"

// Definition of static variables
static process_t processes[MAX_PROCESSES];
static uint32_t current_process = 0;

void process_init() {
    memset(processes, 0, sizeof(processes));
    // Initialize other necessary data structures or smth
}

void process_create(void (*entry_point)(), uint32_t *stack, uint32_t stack_size) {
    for (uint32_t i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].state == PROCESS_TERMINATED || processes[i].state == PROCESS_READY) {
            processes[i].stack = stack;
            processes[i].program_counter = (uint32_t *)entry_point;
            processes[i].base_pointer = stack + stack_size - 1; // Example setup
            processes[i].state = PROCESS_READY;
            processes[i].id = i;
            return;
        }
    }
}

void process_switch() {
    // Save the current process state
    // Load the next process state
    // IDK what this does, I pulled out another all nighter
    uint32_t next_process = (current_process + 1) % MAX_PROCESSES;
    while (processes[next_process].state != PROCESS_READY) {
        next_process = (next_process + 1) % MAX_PROCESSES;
    }

    // Example placeholder
    current_process = next_process;

}

void process_terminate(uint32_t process_id) {
    if (process_id < MAX_PROCESSES) {
        processes[process_id].state = PROCESS_TERMINATED;
        // Free resources associated with the process if needed
    }
}

void process_create(void (*entry_point)(), uint32_t *stack, uint32_t stack_size) {
    // Process created
}

void process_terminate(uint32_t process_id) {
    // process terminated. 
    //I'm sorry to interrupt you, Elizabeth, 
    //if you still even remember that name, 
    //But I'm afraid you've been misinformed.
}