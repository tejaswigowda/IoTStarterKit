#include "TimeEvent.h"
#include "IoTStepper.h"

IoTStepper stepper;
TimeEvent te;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  stepper.setupActuator(2, 3, 4, 5);
  stepper.setMotion(STEP_FINITELY, STEPPER_COUNTERCLOCKWISE, 4096);

  te.setupEvent(millis(), 1000, [](){stepper.update(); return;}, MICROS); //uses a lambda because the stepper update() function does not return void
  te.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  te.update();
}
