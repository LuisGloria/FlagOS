#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include "memory.h"
#include "process.h"
#include "idt.h"
#include "fs.h"
#include "syscalls.h"
#include "gui.h"

void kernel_main(void);

void init_memory(void);
void *kmalloc(size_t size);
void kfree(void *ptr);

void init_processes(void);
void create_process(void (*entry_point)(), uint32_t *stack, uint32_t stack_size);
void terminate_process(uint32_t process_id);
void switch_process(void);

void init_interrupts(void);
void register_interrupt_handler(uint8_t vector, void (*handler)());

void init_filesystem(void);
int create_file(const char *filename);
int delete_file(const char *filename);
void list_files(void);

void init_syscalls(void);
void register_syscall_handler(uint32_t syscall_number, void (*handler)());

void init_gui(void);
void draw_window(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t color);
void draw_button(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t color);

// Shutdown function
void shutdown(void);

#endif