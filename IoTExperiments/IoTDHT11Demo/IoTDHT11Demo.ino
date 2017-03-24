/*
 * A demonstration of the DHT11 breakout
 * 
 * This creates the object, invokes the setup function, then reads from the object
 */

#include "IoTDHT11.h"

IoTDHT11 dht(2);                                 //Create the object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Serial.println();
  
  dht.setupSensor();                              //Setup the object
  
  Serial.print(F("IoTDHT11 object id: "));
  Serial.println(dht.getObjectID());

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(F("Temperature (Celsius): \t"));   //Read from the object
  Serial.println(dht.readSensor(TEMPERATURE));
  
  Serial.print(F("Humidity (% humidity): \t"));
  Serial.println(dht.readSensor(HUMIDITY));
  delay(1000);

}
