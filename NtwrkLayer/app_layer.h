// app_layer.h
#ifndef APP_LAYER_H
#define APP_LAYER_H
#include "heap.h"

void send_data(const char *address, const char *data, uint32_t length);
void receive_data(char *buffer, uint32_t *length);

#endif // APP_LAYER_H