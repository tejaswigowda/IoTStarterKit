/*
 * In this sketch, loop() repeatedly calls the push button's readSensor() function and 
 * controls an led according to the state of the PB.
 * 
 * A user could simply read the state of the GPIO pin to which the PushButton is connected,
 * but the purpose of this sketch is to demonstrate the Sensor interface of the the Sensors
 * included in the IoTStarterKit
 */

#include "PushButton.h"

PushButton button = PushButton(7); //PB is attached to GPIO at pin 7
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  button.setupSensor();   //this implicitly sets the GPIO to INPUT mode
  
  Serial.println("setupSensor complete.");
  Serial.print("Sensor object id = ");
  Serial.println(button.getObjectID());
  
  Serial.println("Setup complete. Entering infinite loop.");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, button.readSensor());
}
