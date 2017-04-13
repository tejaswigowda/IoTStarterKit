#include "TimerEvent.h"
#include "IoTStepper.h"

IoTStepper stepper;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  stepper.setupController(2, 3, 4, 5);
  stepper.setMotion(INFINITY, STEPPER_CLOCKWISE);
}

void loop() {
  // put your main code here, to run repeatedly:
  static TimerEvent te = TimerEvent(millis(), 1000, [](){stepper.update(); return;}, MICROS); //uses a lambda because the stepper update() function does not return void

  te.update();

}
