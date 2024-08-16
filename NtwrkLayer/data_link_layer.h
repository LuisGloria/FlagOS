// data_link_layer.h
#ifndef DATA_LINK_LAYER_H
#define DATA_LINK_LAYER_H
#include "heap.h"

void process_incoming_frame(const uint8_t *frame, uint32_t length);
void build_ethernet_frame(const uint8_t *payload, uint32_t payload_len);

#endif // DATA_LINK_LAYER_H
