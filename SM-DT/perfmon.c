#include "perfmon.h"
#include "cpu.h" // For CPU statistics
#include "memman.h" // For memory management

void init_perfmon() {

}

void report_cpu_usage() {
    uint32_t cpu_usage = get_cpu_usage(); // Implement this function in `cpu.c`
    char buffer[64];                      // I'll create cpu.c later.
    snprintf(buffer, sizeof(buffer), "CPU Usage: %u%%\n", cpu_usage);
    log_message(buffer);
}

void report_memory_usage() {
    uint32_t free_memory = get_free_memory(); // Implement these functions in `memman.c`
    uint32_t total_memory = get_total_memory(); //meh, too lazy, later.
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Memory Usage: %u/%u bytes\n", total_memory - free_memory, total_memory);
    log_message(buffer);
}
