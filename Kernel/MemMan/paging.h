#ifndef PAGING_H
#define PAGING_H

#include <stdint.h>

#define PAGE_PRESENT 0x1
#define PAGE_WRITE   0x2
#define PAGE_SIZE    4096

typedef struct page_table_entry {
    uint32_t entry;
} page_table_entry_t;

typedef struct page_table {
    page_table_entry_t entries[1024];
} page_table_t;

typedef struct page_directory_entry {
    uint32_t entry;
} page_directory_entry_t;

typedef struct page_directory {
    page_directory_entry_t entries[1024];
} page_directory_t;

void init_paging(void);
void load_page_directory(page_directory_t *pd);
void enable_paging(void);

#endif