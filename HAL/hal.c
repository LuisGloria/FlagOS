#include "hal.h"
#include <stddef.h>

// I/O Port Operations
void hal_outb(uint16_t port, uint8_t value) {
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

uint8_t hal_inb(uint16_t port) {
    uint8_t value;
    asm volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

// Memory Operations
void hal_memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    while (n--) {
        *d++ = *s++;
    }
}

void hal_memset(void *s, int c, size_t n) {
    char *p = (char *)s;
    while (n--) {
        *p++ = (char)c;
    }
}

// Timer Operations
void hal_init_timer(uint32_t frequency) {

}

void hal_sleep(uint32_t milliseconds) {

}

void hal_enable_interrupts() {
    asm volatile ("sti");
}

void hal_disable_interrupts() {
    asm volatile ("cli");
}
