#include "process.h"

void timer_isr() {
    process_switch();
}
