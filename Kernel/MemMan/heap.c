#include <stdint.h> // For uint32_t, uint8_t, this took me like 4 hours.
#include "heap.h"
#include "memman.h"

heap_block_t *heap_start = NULL;

void init_heap(uint32_t start, uint32_t size) {
    heap_start = (heap_block_t*)start;
    heap_start->size = size - sizeof(heap_block_t);
    heap_start->next = NULL;
    heap_start->free = 1;
}

void *malloc(uint32_t size) {
    heap_block_t *current = heap_start;

    while (current != NULL) {
        if (current->free && current->size >= size) {
            if (current->size > size + sizeof(heap_block_t)) {
                heap_block_t *new_block = (heap_block_t*)((uint32_t)current + sizeof(heap_block_t) + size);
                new_block->size = current->size - size - sizeof(heap_block_t);
                new_block->free = 1;
                new_block->next = current->next;

                current->size = size;
                current->next = new_block;
            }

            current->free = 0;
            return (void*)((uint32_t)current + sizeof(heap_block_t));
        }

        current = current->next;
    }

    return NULL; // Out of memory lol
}

void free(void *ptr) {
    if (ptr == NULL) return;

    heap_block_t *block = (heap_block_t*)((uint32_t)ptr - sizeof(heap_block_t));
    block->free = 1;

    heap_block_t *current = heap_start;
    while (current != NULL) {
        if (current->free && current->next != NULL && current->next->free) {
            current->size += current->next->size + sizeof(heap_block_t);
            current->next = current->next->next;
        }

        current = current->next;
    }
}