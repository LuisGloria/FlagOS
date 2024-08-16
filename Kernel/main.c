#include "include/kernel.h"
#include "memman/memman.h"
#include "memman/paging.h"
#include "memman/heap.h"

void kernel_main(void) {
    // Initialize memory management
    init_physical_memory();
    init_paging();
    init_heap(HEAP_START, HEAP_SIZE);

    // Your kernel code here...
}