/*
 * A demonstration of the DHT11 breakout
 */

#include "IoTDHT11.h"

IoTDHT11 dht(8);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.setupSensor();
  Serial.print("IoTDHT11 object id: ");
  Serial.println(dht.getObjectID());

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Temperature (Celsius): ");
  Serial.println(dht.readSensor(TEMPERATURE));
  delay(1000);
  Serial.print("Humidity (% humidity): ");
  Serial.println(dht.readSensor(HUMIDITY));
  delay(1000);

}