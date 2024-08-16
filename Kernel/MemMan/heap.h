#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

typedef struct heap_block {
    uint32_t size;
    struct heap_block *next;
    uint8_t free;
} heap_block_t;

void init_heap(uint32_t start, uint32_t size);
void *malloc(uint32_t size);
void free(void *ptr);

#define HEAP_H

#define HEAP_START 0x100000 // Example address

#define HEAP_SIZE 0x1000000 // Example size (16 MB this time)

void init_heap(uint32_t start, uint32_t size);

#endif
