#include "IoTStepper.h"

IoTStepper s1;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.print("IoTStepper objectID: \t");
  Serial.println(s1.getObjectID());

  Serial.println("Setting up controller on pins 2, 3, 4 & 5...");
  s1.setupController(2, 3, 4, 5);
  Serial.println("Setup complete.");

  Serial.println("Now rotating stepper counterclockwise then clockwise at different speed...");
  delay(1000);
  s1.rotate(1000, STEPPER_COUNTERCLOCKWISE, 5000);
  s1.rotate(1000, STEPPER_CLOCKWISE, 1000);

  s1.setMotion(INFINITY, STEPPER_COUNTERCLOCKWISE, 800);

}

unsigned long currentTime;
unsigned long next;
unsigned long randomdelay = millis() + 30000;
void loop() {
  currentTime = millis();
  if(currentTime > next){
    digitalWrite(13, !digitalRead(13));
    next += 500;
    Serial.println(millis());    
  }
  if(millis() > randomdelay){
    delay(3000);
    randomdelay = 5000000;
  }
  s1.update();
  delayMicroseconds(100);

}
