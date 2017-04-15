#include "RGB_LED.h"

RGB_LED led;

void setup() {
  // put your setup code here, to run once:
  led.setPins(2, 3, 4);
}

void loop() {
  // put your main code here, to run repeatedly:
  led.writeLED(RGB_RED);
  delay(1000);
  led.writeLED(RGB_ORANGE);
  delay(1000);
  led.writeLED(RGB_YELLOW);
  delay(1000);
  led.writeLED(RGB_GREEN);
  delay(1000);
  led.writeLED(RGB_BLUE);
  delay(1000);
  led.writeLED(RGB_INDIGO);
  delay(1000);
  led.writeLED(RGB_VIOLET);
  delay(1000);
  led.writeLED(RGB_WHITE);
  delay(1000);
  led.writeLED(RGB_OFF);
  delay(1000);
}
