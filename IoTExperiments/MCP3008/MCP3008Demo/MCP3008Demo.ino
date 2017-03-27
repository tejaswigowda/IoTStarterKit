#include "MCP3008.h"

#define CSPIN D8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  setupMCP3008(CSPIN);

  unsigned long tick = micros();
  for(int i = 0; i < 65000; i++){
    readMCP(0, CSPIN);
  }
  unsigned long tock = micros();

  Serial.println( tock - tick );

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(readMCP(0, CSPIN));
  delay(100);

}
