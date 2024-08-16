#include "debug.h"
#include "memman.h"
#include "proccess.h"
#include "uart.h"

void init_debug() {
    uart_init();
}

void dump_memory(uint32_t start, uint32_t length) {
    char buffer[64];
    for (uint32_t addr = start; addr < start + length; addr += 16) {
        snprintf(buffer, sizeof(buffer), "0x%08X: ", addr);
        uart_write(buffer);
        for (uint32_t i = 0; i < 16; i++) {
            if (addr + i < start + length) {
                snprintf(buffer, sizeof(buffer), "%02X ", *(volatile uint8_t*)(addr + i));
                uart_write(buffer);
            }
        }
        uart_write("\n");
    }
}

void list_processes() {
    extern process_t processes[MAX_PROCESSES];
    for (uint32_t i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].state != PROCESS_TERMINATED) {
            char buffer[64];
            snprintf(buffer, sizeof(buffer), "Process ID: %u, State: %d\n", processes[i].id, processes[i].state);
            uart_write(buffer);
        }
    }
}

//somone else please fix this, updated proccess.h and now I'm screwed.
//forget it, I did a typo in include.

//and yes I know it's process with one c but fuck it!
//I ain't renaming all includes from every file!
