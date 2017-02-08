/*
 * A demonstration of the DHT11 breakout
 */

#include "IoTDHT11.h"

IoTDHT11 dht(8);                                  //Create the object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  dht.setupSensor();                              //Setup the objects
  
  Serial.print(F("IoTDHT11 object id: "));
  Serial.println(dht.getObjectID());

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(F("Temperature (Celsius): \t"));       //Read from the objects
  Serial.println(dht.readSensor(TEMPERATURE));
  
  Serial.print(F("Humidity (% humidity): \t"));
  Serial.println(dht.readSensor(HUMIDITY));
  delay(1000);

}
