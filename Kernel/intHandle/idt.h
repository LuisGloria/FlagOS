#ifndef IDT_H
#define IDT_H

#include <stdint.h>

// IDT Entry Structure
typedef struct {
    uint16_t offset_low;  // Lower 16 bits of the ISR address
    uint16_t selector;    // Segment selector
    uint8_t  zero;        // Reserved, set to 0
    uint8_t  type_attr;   // Type and attributes
    uint16_t offset_high; // Upper 16 bits of the ISR address
} __attribute__((packed)) idt_entry_t;

// IDT Pointer Structure
typedef struct {
    uint16_t limit;       // Size of the IDT
    uint32_t base;        // Base address of the IDT
} __attribute__((packed)) idt_ptr_t;

void init_idt();

#endif // IDT_H