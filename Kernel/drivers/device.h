#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

void init_device();

uint8_t read_device(uint32_t address);

void write_device(uint32_t address, uint8_t data);

#endif
