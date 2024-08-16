#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init();

void uart_write_char(char c);

void uart_write(const char *str);

char uart_read_char();

int uart_data_available();

#endif

//pretty self explainatory I hope I don't need to explain this too.