#if !defined(MCP3008_H)
#define MCP3008_H

#include "IoTStarterKit.h"
#include <SPI.h>

int 	 setupMCP3008(int);
uint16_t readMCP(uint8_t, int);

#endif