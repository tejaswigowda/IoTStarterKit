#include "TimeEvent.h"

void toggleLED(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); //bitwse XOR will toggle output
  return;
}

TimeEvent te;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("begin");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  unsigned long currentTime = millis();
  te.setupEvent(currentTime, 500, &toggleLED, MILLIS);
  te.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  te.update();                //demonstrating polymorphism. We can have an array of Event types and call refresh() on all of them
}
