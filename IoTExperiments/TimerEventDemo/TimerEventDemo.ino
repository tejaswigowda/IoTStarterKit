#include "TimerEvent.h"

void toggleLED(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  return;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("begin");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long currentTime = millis();
  static TimerEvent te = TimerEvent(currentTime, 500, &toggleLED, MILLIS);
  static Event* te_ptr = &te;
  
  te_ptr->refresh();                //demonstrating polymorphism. We can have an array of Event types and call refresh() on all of them
}
