[BITS 16]
[ORG 0x7C00]

start:
    mov ax, 0x07C0
    add ax, 288
    mov ss, ax
    mov sp, 4096

    ; Load the kernel
    mov si, hello_msg
    call print_string

    cli
    hlt

hello_msg db 'Hello, Kernel!', 0

print_string:
    mov ah, 0x0E
.print_loop:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .print_loop
.done:
    ret

times 510-($-$$) db 0
dw 0xAA55