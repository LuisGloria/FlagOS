#include "process.h"

void timer_isr() {
    // Handle the timer interrupt
    process_switch();
}
