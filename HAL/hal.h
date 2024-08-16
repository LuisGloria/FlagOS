#ifndef HAL_H
#define HAL_H

#include <stdint.h>

// I/O Port Operations
void hal_outb(uint16_t port, uint8_t value);
uint8_t hal_inb(uint16_t port);

// Memory Operations
void hal_memcpy(void *dest, const void *src, size_t n);
void hal_memset(void *s, int c, size_t n);

// Timer Operations
void hal_init_timer(uint32_t frequency);
void hal_sleep(uint32_t milliseconds);

// Additional Hardware Abstraction Functions
void hal_enable_interrupts();
void hal_disable_interrupts();

#endif
