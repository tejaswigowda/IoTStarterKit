#include "TimeEvent.h"
#include "IoTStepper.h"

IoTStepper stepper;
TimeEvent te;
TimeEvent te2;

bool sd = STEPPER_COUNTERCLOCKWISE;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  stepper.setupActuator(2, 3, 4, 5);
  stepper.setMotion(STEP_FINITELY, sd, 4096);

  unsigned long ct = millis();
  te.setupEvent(ct, 1000, [](){stepper.update(); return;}, MICROS); //uses a lambda because the stepper update() function does not return void
  te2.setupEvent(ct, 6000, [](){sd = !sd; stepper.setMotion(STEP_FINITELY, sd, 4096);}, MILLIS);
  
  te.start();
  te2.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  te.update();
  te2.update();
}
