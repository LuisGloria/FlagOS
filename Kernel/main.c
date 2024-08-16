#include "kernel.h"
#include "config.h"
#include "memman/memman.h"
#include "memman/paging.h"
#include "memman/heap.h"

void kernel_main(void) {
    init_physical_memory();
    init_paging();
    init_heap(HEAP_START, HEAP_SIZE);

    // Your kernel code here.
}

#include "gui.h"

void button_click_handler() {
    printf("Button clicked!\n");
}

int main() {
    gui_init();

    gui_window_t main_window = {10, 10, 300, 200, 0xFFFFFF}; // Example values
    gui_draw_window(&main_window);

    gui_button_t my_button = {50, 50, 100, 30, 0x00FF00, button_click_handler}; // More example values
    gui_draw_button(&my_button);

    while (1) {
        gui_handle_events();
    }

    return 0;
}