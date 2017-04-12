#include "IoTDHT11.h"
#include "IoTDHT22.h"

IoTDHT11 dht11;
IoTDHT22 dht22;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  dht11 = IoTDHT11(2);
  dht22 = IoTDHT22(3);

  dht11.setupSensor();
  dht22.setupSensor();
}

void loop() {
  static float t11, h11, t22, h22;

  t11 = dht11.readSensor(DHT_TEMPERATURE);
  h11 = dht11.readSensor(DHT_HUMIDITY);
  t22 = dht22.readSensor(DHT_TEMPERATURE);
  h22 = dht22.readSensor(DHT_HUMIDITY);

  Serial.print(t11);
  Serial.print(",");
  Serial.print(t22);
  Serial.print(",");
  Serial.print(h11);
  Serial.print(",");
  Serial.println(h22);
  
  
  delay(2000);

}
