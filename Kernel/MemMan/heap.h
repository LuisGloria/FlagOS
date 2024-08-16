#ifndef HEAP_H
#define HEAP_H

#include <stdint.h> // For uint32_t, uint8_t

typedef struct heap_block {
    uint32_t size;            // Size of the block
    struct heap_block *next;  // Pointer to the next block
    uint8_t free;             // Whether the block is free or not
} heap_block_t;

void init_heap(uint32_t start, uint32_t size);
void *malloc(uint32_t size);
void free(void *ptr);

#endif // HEAP_H