#include "MCP3008.h"

int setupMCP3008(int newCS){
  if(newCS < 0)
    return IOT_FAILURE;

  pinMode(newCS, OUTPUT);
  digitalWrite(newCS, HIGH);
  digitalWrite(newCS, LOW);
  digitalWrite(newCS, HIGH);

  SPI.begin();
  SPI.setFrequency(1350000);

  return IOT_UNKNOWN;
}

uint16_t readMCP(uint8_t channel, int cs){
  byte one = 0b00000001;
  byte two = 0b10000000 | (channel << 4);
  byte three = 0b00000000;
  byte bytesBack[3];

  digitalWrite(cs, LOW);

                 SPI.transfer(one);
  bytesBack[1] = SPI.transfer(two);
  bytesBack[2] = SPI.transfer(three);

  digitalWrite(cs, HIGH);

  return ( ((uint16_t)(bytesBack[1] % 4) << 8) | bytesBack[2] );

}