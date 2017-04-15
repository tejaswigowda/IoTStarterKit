/*
 * In this sketch, the loop function quickly reads the state of the PushButton object
 * and outputs the state to pin 13.
 * 
 * A user could simply read the state of the GPIO pin to which the PushButton is connected,
 * but the purpose of this sketch is to demonstrate the Sensor interface of the the Sensors
 * included in the IoTStarterKit
 */

#include "PushButton.h"

PushButton button;                                                //Create object
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  button.setupSensor(7);                                          //Setup object
  
  Serial.println(F("setupSensor complete."));
  Serial.print(F("Sensor object id = "));
  Serial.println(button.getObjectID());
  
  Serial.println(F("Setup complete. Entering infinite loop."));
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, button.readSensor());                      //Read from object
}
