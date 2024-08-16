#include "timer_interrupt.h"
#include "scheduler.h"

void timer_interrupt_handler() {
    scheduler();
}
