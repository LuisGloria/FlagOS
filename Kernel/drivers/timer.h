#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void init_timer();
void timer_isr(); // Interrupt Service Routine for the timer

#endif // TIMER_H
