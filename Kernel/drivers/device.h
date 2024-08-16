#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

// Initialize the device
void init_device();

// Read data from the device
uint8_t read_device(uint32_t address);

// Write data to the device
void write_device(uint32_t address, uint8_t data);

#endif // DEVICE_H
