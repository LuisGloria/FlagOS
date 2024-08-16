#ifndef GUI_H
#define GUI_H

#include <stdint.h>

typedef struct {
    uint32_t x, y;
    uint32_t width, height;
    uint32_t color;
} gui_window_t;

typedef struct {
    uint32_t x, y;
    uint32_t width, height;
    uint32_t color;
    void (*on_click)();
} gui_button_t;

void gui_init();
void gui_draw_window(gui_window_t *window);
void gui_draw_button(gui_button_t *button);
void gui_handle_events(); // click handler?

#endif
