#include "log.h"
#include <string.h> // For strlen
#include "uart.h"

#define LOG_BUFFER_SIZE 256
static char log_buffer[LOG_BUFFER_SIZE];

void init_log() {
    uart_init();
}

void log_message(const char *message) {
    size_t length = strlen(message);
    if (length < LOG_BUFFER_SIZE) {
        strcpy(log_buffer, message);
        uart_write(log_buffer); // Send log message to UART
    }
}

void log_error(const char *error_message) {
    log_message("ERROR: ");
    log_message(error_message);
}
