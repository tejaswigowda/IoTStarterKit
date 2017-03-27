#include "IoTHeartbeat.h"

IoTHeartbeat hr(true, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(hr.getObjectID());
  hr.setupSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(hr.readSensor());
  delay(100);
}
