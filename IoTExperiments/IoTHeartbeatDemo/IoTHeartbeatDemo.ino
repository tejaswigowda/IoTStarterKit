#include "IoTHeartbeat.h"

IoTHeartbeat hr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println(hr.getObjectID());
  
  hr.setupSensor(true, A0, -1);

  unsigned long tick = micros();
  for(uint16_t i = 0; i < 65000; i++){
    hr.readSensor();
  }
  unsigned long tock = micros();
  Serial.println(tock - tick);
  delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(hr.readSensor());
  delay(100);
}
