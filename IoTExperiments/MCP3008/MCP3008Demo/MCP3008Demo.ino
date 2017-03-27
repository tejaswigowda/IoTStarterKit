#include "MCP3008.h"

int csPin = D8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  SPI.begin();
  
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, HIGH);
  digitalWrite(csPin, LOW);
  digitalWrite(csPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(readMCP(1, csPin));
  delay(100);
}
