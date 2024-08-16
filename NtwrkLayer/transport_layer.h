// transport_layer.h
#ifndef TRANSPORT_LAYER_H
#define TRANSPORT_LAYER_H
#include "heap.h"

void process_tcp_segment(const uint8_t *segment, uint32_t length);
void process_udp_datagram(const uint8_t *datagram, uint32_t length);
void send_tcp_segment(const uint8_t *data, uint32_t length);
void send_udp_datagram(const uint8_t *data, uint32_t length);

#endif // TRANSPORT_LAYER_H