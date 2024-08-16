#include "hypervisor.h"

void kernel_main(void) {
    const char *str = "Kernel is running!";
    char *vidptr = (char*)0xb8000; // Video memory begins here.
    unsigned int i = 0;
    unsigned int j = 0;

    while (j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07; // Light grey on black text.
        j = j + 2;
    }

    j = 0;
    while (str[j] != '\0') {
        vidptr[i] = str[j];
        vidptr[i+1] = 0x07;
        ++j;
        i = i + 2;
    }
    return;
}

void kernel_main() {
    init_hypervisor();
    create_vm();
    run_vm();

 
    while (1) {
        // Kernel tasks
    }
}