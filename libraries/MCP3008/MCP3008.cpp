#include "MCP3008.h"

uint16_t readMCP(uint8_t channel, int cs){
  if(channel < 0 || channel > 7){
    return IOT_FAILURE;
  }

  byte one = 0b00000001;
  byte two = 0b10000000 | (channel << 4);
  byte three = 0b00000000;
  byte bytesBack[3];

  digitalWrite(cs, LOW);

  SPI.transfer(one);
  bytesBack[1] = SPI.transfer(two);
  bytesBack[2] = SPI.transfer(three);

  digitalWrite(cs, HIGH);

  uint16_t output = ((uint16_t)(bytesBack[1] % 4) << 8) | (uint16_t)bytesBack[2];

  return output;

}