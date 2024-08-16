#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>

#define PAGE_PRESENT    0x1
#define PAGE_WRITE      0x2
#define PAGE_USER       0x4
#define PAGE_WRITE_THROUGH 0x8
#define PAGE_CACHE_DISABLE 0x10
#define PAGE_SIZE       0x80
#define PAGE_GLOBAL     0x100
#define PAGE_UNUSED     0x200

typedef struct {
    uint32_t entries[1024];
} page_table_t;

typedef struct {
    uint32_t entries[1024];
} page_directory_t;

// Prototypes I guess.
void init_paging();
void switch_page_directory(page_directory_t *new_directory);
void enable_paging();

#endif
