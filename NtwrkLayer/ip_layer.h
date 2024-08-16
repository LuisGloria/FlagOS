#ifndef IP_LAYER_H
#define IP_LAYER_H
#include "heap.h"

void process_ip_packet(const uint8_t *packet, uint32_t length);
void send_ip_packet(const uint8_t *data, uint32_t length);

#endif