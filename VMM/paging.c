#include "paging.h"
#include <string.h>
#include "memman.h"

static page_directory_t *kernel_page_directory;
static page_table_t *kernel_page_table;

// Set up paging
void init_paging() {
    kernel_page_directory = (page_directory_t*)find_free_page();
    memset(kernel_page_directory, 0, sizeof(page_directory_t));

    kernel_page_table = (page_table_t*)find_free_page();
    memset(kernel_page_table, 0, sizeof(page_table_t));

    // Set up page tables
    for (uint32_t i = 0; i < 1024; i++) {
        kernel_page_table->entries[i] = (i * 0x1000) | PAGE_PRESENT | PAGE_WRITE;
    }

    kernel_page_directory->entries[0] = ((uint32_t)kernel_page_table) | PAGE_PRESENT | PAGE_WRITE;

    switch_page_directory(kernel_page_directory);
    enable_paging();
}

void switch_page_directory(page_directory_t *new_directory) {
    asm volatile("mov %0, %%cr3" : : "r"(new_directory));
}

// Enable paging by setting the paging bit in CR0
void enable_paging() {
    uint32_t cr0;
    asm volatile("mov %%cr0, %0" : "=r"(cr0));
    cr0 |= 0x80000000; // Set paging bit in CR0
    asm volatile("mov %0, %%cr0" : : "r"(cr0));
}
