#ifndef LOG_H
#define LOG_H

#include <stdint.h>

void init_log();
void log_message(const char *message);
void log_error(const char *error_message);

#endif