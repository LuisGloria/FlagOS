#ifndef NETWORK_DRIVER_H
#define NETWORK_DRIVER_H
#include "heap.h"

void network_init();
void send_packet(const uint8_t *data, uint32_t length);
void receive_packet(uint8_t *buffer, uint32_t *length);

#endif
