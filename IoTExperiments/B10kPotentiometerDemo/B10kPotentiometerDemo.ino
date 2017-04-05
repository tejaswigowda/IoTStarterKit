#include "IoTPot.h"

IoTPot pot;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  pot.setupSensor(true, 0, D8);

  Serial.println(pot.getObjectID());
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(pot.readSensor());
  Serial.print(", ");
  Serial.print(pot.readSensorInt());
  Serial.print(", ");
  Serial.print(pot.readSensor(POT_RAW));
  Serial.print(", ");
  Serial.print(pot.readSensor(POT_SYMMETRICAL));
  Serial.print(", ");
  Serial.print(pot.readSensor(POT_ASYMMETRICAL));
  Serial.println();

  delay(500);
}
