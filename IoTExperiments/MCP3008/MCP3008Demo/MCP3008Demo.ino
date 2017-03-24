#include "MCP3008.h"

#define clk D5
#define mosi D7
#define miso D6
#define cs D8

MCP3008 adc;//(clk, mosi, miso, cs);

void setup() {
  Serial.begin(115200);
  adc.setupSensor();
  
  for (int i = 0; i < 10; i++) {
    float val = adc.readSensor(CH0); // read Chanel 0 from MCP3008 ADC
    Serial.println(val);
    delay(100);
  }

}


void loop() {
  Serial.println(adc.readSensor(CH0));
  delay(100);

}
