#ifndef MEMMAN_H
#define MEMMAN_H
#define PAGE_SIZE 0x1000
#define BITMAP_SIZE 32768

void init_physical_memory();
void set_page_used(uint32_t page);
void set_page_free(uint32_t page);
int is_page_free(uint32_t page);
uint32_t find_free_page(void);

#endif