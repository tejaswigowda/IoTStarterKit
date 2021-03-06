/*
This file contains the implementations of the functions inside "MCP3008.h"

Phillip Noel
27-MAR-2017
*/

#include "MCP3008.h"

int setupMCP3008(int newCS){
  if(newCS < 0)
    return IOT_FAILURE;

  pinMode(newCS, OUTPUT);                                         //if the cs is low when the mcp3008 is powered on then it must be cycled
  digitalWrite(newCS, HIGH);
  digitalWrite(newCS, LOW);
  digitalWrite(newCS, HIGH);

  SPI.begin();                                                    //always setFrequency() after SPI.begin()

#if defined(ESP8266)
 SPI.setFrequency(1350000);                                      //1.35mhz when mcp3008 is powered by 2.7V, 3.6mhz when powered by 5V. Arduino Uno default SPI speed is compatible.
#endif
  

  return IOT_UNKNOWN;
}

uint16_t readMCP3008(uint8_t channel, int cs){
  byte one   = 0b00000001;                                        //start bit is separate from configuration bit in order to simplify output bits
  byte two   = 0b10000000 | (channel << 4);                       //differential bit and 3 bits for the channel. Next two bits received are not used, last 2 are
  byte three = 0b00000000;                                        //these 8 bits are part of the output

  byte bytesBack1, bytesBack2;


  digitalWrite(cs, LOW);                                          //bring cs low to communicate with device

                 SPI.transfer(one);                               //don't need bytes read back
  bytesBack1   = SPI.transfer(two);                               //will only need last 2 bytes of response
  bytesBack2   = SPI.transfer(three);                             //need all 8 bytes of response

  digitalWrite(cs, HIGH);                                         //bring cs high when done communicating

  return ( ((uint16_t)(bytesBack1 % 4) << 8) | bytesBack2 );  //output of MCP3008 is Most Significant Bit first (MSB). Need last 2 bits of bytesBack[1] and all 8 bits of bytesBack[2]

}