#ifndef DEBUG_H
#define DEBUG_H

#include <stdint.h>

void init_debug();
void dump_memory(uint32_t start, uint32_t length);
void list_processes();

#endif
