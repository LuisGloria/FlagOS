#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

void init_physical_memory(void);
void set_page_used(uint32_t page);
void set_page_free(uint32_t page);
int is_page_free(uint32_t page);
uint32_t find_free_page(void);

#endif // MEMORY_H