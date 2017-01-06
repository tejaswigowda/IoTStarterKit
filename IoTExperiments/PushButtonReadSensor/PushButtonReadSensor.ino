#include "IoTDHT11.h"
#include "PushButton.h"

PushButton pb(7);
IoTDHT11 dht(8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pb.setupSensor();
  dht.setupSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pb.readSensor() == HIGH){
    Serial.print("The temperature is: ");
    Serial.print(dht.readSensor(TEMPERATURE));
    Serial.println(" degrees celsius.");
  }
  delay(100);
}
