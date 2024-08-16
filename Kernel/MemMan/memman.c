#include "memman.h"
#include <string.h>
#include <stdint.h> // For uint32_t, uint8_t

#define PAGE_SIZE 4096  // Define PAGE_SIZE here
#define BITMAP_SIZE 32768

static uint8_t memory_bitmap[BITMAP_SIZE] = {0};

#define BITMAP_SIZE 32768
static uint8_t memory_bitmap[BITMAP_SIZE] = {0};

void init_physical_memory() {
    // Initialize physical memory management, e.g., set up the bitmap
    memset(memory_bitmap, 0, sizeof(memory_bitmap));
}

void set_page_used(uint32_t page) {
    memory_bitmap[page / 8] |= (1 << (page % 8));
}

void set_page_free(uint32_t page) {
    memory_bitmap[page / 8] &= ~(1 << (page % 8));
}

int is_page_free(uint32_t page) {
    return !(memory_bitmap[page / 8] & (1 << (page % 8)));
}

uint32_t find_free_page(void) {
    for (uint32_t i = 0; i < BITMAP_SIZE * 8; i++) {
        if (is_page_free(i)) {
            set_page_used(i);
            return i * PAGE_SIZE;
        }
    }
    return 0; // Out of memory
}