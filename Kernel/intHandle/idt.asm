BITS 32

global _start
extern init_idt

_start:

    call init_idt

    sti

    ; Halt CPU (for demonstration purposes)
    hlt
