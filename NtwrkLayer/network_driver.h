#ifndef NETWORK_DRIVER_H
#define NETWORK_DRIVER_H

#include <stdint.h>
#include <stddef.h>


#define MAX_PACKET_SIZE 1500
#define NETWORK_INTERFACE_NAME "eth0"


typedef struct {
    uint8_t data[MAX_PACKET_SIZE];
    size_t length;
} network_packet_t;


void network_init(const char *interface_name);

int network_send(const network_packet_t *packet);

int network_receive(network_packet_t *packet);

int network_configure(const char *ip_address, const char *subnet_mask);

void network_shutdown();

#endif
