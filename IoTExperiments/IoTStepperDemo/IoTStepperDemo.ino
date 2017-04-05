#include "IoTStepper.h"

IoTStepper s1;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("IoTStepper objectID: \t");
  Serial.println(s1.getObjectID());

  Serial.println("Setting up controller on pins 2, 3, 4 & 5...");
  s1.setupController(2, 3, 4, 5);
  Serial.println("Setup complete.");

  Serial.println("Now rotating stepper counterclockwise by 360 degrees...");
  delay(1000);
  s1.rotate(4096, STEPPER_CLOCKWISE, 5);
  Serial.println("Complete. Now setting paramters for motor to run indefinitely. It will be \"updated\" in loop()...");
  s1.setMotion(INFINITY, STEPPER_CLOCKWISE, 2);
  Serial.println("Complete. Now entering loop.");

}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long nextPrint;
  static unsigned long currentTime;

  currentTime = millis();
  if(currentTime > nextPrint){
    nextPrint += 500;
    Serial.println("task switching is awesome!");
  }

  s1.update();

}
