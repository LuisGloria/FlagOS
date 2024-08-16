#include "idt.h"
#include <stdint.h>
#include <string.h>
#include <stdint.h>

void timer_isr() {

}

#define IDT_ENTRIES 256

idt_entry_t idt[IDT_ENTRIES];
idt_ptr_t idt_ptr;

// Function to set an IDT entry
void set_idt_entry(uint8_t vector, uint32_t base, uint16_t selector, uint8_t type_attr) {
    idt[vector].offset_low = base & 0xFFFF;
    idt[vector].offset_high = (base >> 16) & 0xFFFF;
    idt[vector].selector = selector;
    idt[vector].zero = 0;
    idt[vector].type_attr = type_attr;
}

// Load the IDT
void load_idt(idt_ptr_t *idt_ptr) {
    asm volatile("lidtl (%0)" : : "r"(idt_ptr));
}

void init_idt() {
    memset(idt, 0, sizeof(idt));
    idt_ptr.limit = sizeof(idt) - 1;
    idt_ptr.base = (uint32_t)idt;

    // Set up some IDT entries (example only, real entries should be set up with actual IRSs)
    // Vector 0x20 is typically IRQ0 (Timer), for example:
    set_idt_entry(0x20, (uint32_t)timer_isr, 0x08, 0x8E); // Present, Ring 0, 32-bit interrupt gate

    load_idt(&idt_ptr);
}

//I mean ISRs in line 34 sorry for reminding you to file your taxes.