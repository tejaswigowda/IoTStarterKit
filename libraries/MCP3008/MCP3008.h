/*
This header file contains functions used to control the MCP3008 8-channel, 10-bit analog to digital converter.
The setupMCP3008 function sets speed of the SPI hardware.
The read MCP3008 function interfaces with the device and gets a reading from one channel at a time.
This code is not encapsulated in an object for the sake of speed. Since there is no object containing variables to which these functions can refer,
the functions must be supplied channel and chip select parameters.

Phillip Noel
27-MAR-2017
*/

#if !defined(MCP3008_H)
#define MCP3008_H

#include "IoTStarterKit.h"
#include <SPI.h>

int 	 setupMCP3008(int);

uint16_t readMCP3008(uint8_t, int);

#endif