#include <stdint.h>
#include "paging.h"
#include "memman.h"

page_directory_t *kernel_page_directory;
page_table_t *kernel_page_table;

void init_paging() {
    kernel_page_directory = (page_directory_t*)find_free_page();
    memset(kernel_page_directory, 0, sizeof(page_directory_t));

    kernel_page_table = (page_table_t*)find_free_page();
    memset(kernel_page_table, 0, sizeof(page_table_t));

    for (uint32_t i = 0; i < 1024; i++) {
        kernel_page_table->entries[i].entry = (i * PAGE_SIZE) | PAGE_PRESENT | PAGE_WRITE;
    }

    kernel_page_directory->entries[0].entry = ((uint32_t)kernel_page_table) | PAGE_PRESENT | PAGE_WRITE;

    load_page_directory(kernel_page_directory);
    enable_paging();
}

void load_page_directory(page_directory_t *pd) {
    asm volatile("mov %0, %%cr3" : : "r"(pd));
}

void enable_paging() {
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r"(cr0));
    cr0 |= 0x80000000; // Set paging bit in CR0
    asm volatile("mov %0, %%cr0" : : "r"(cr0));
}