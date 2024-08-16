#include "timer.h"
#include <stdint.h>

#define TIMER_BASE_ADDR 0x10000000 // Example base address
#define TIMER_FREQUENCY 1000

void init_timer() {

    *(volatile uint32_t *)(TIMER_BASE_ADDR) = TIMER_FREQUENCY;

}

void timer_isr() {

}
