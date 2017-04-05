#include "IoTHeartbeat.h"

IoTHeartbeat hr(true, 0, D8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println(hr.getObjectID());
  
  SPI.begin();
  SPI.setFrequency(1350000L);
  
  pinMode(D8, OUTPUT);
  digitalWrite(D8, HIGH);
  digitalWrite(D8, LOW);
  digitalWrite(D8, HIGH);
  
  hr.setupSensor();

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
