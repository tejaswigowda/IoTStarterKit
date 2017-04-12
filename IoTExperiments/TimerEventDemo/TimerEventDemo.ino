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
  static TimerEvent te = TimerEvent(millis(), 500, &toggleLED, MILLIS);
  static Event* te_ptr = &te;
  te_ptr->refresh();
  //Serial.println(te.refresh());
  //delay(100);
}
