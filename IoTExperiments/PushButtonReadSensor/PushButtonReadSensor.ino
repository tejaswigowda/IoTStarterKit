#include "IoTDHT11.h"
#include "PushButton.h"

PushButton pb(D2);                                       //Create sensor objects
IoTDHT11 dht(D3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);

  pb.setupSensor();                                       //Setup Sensor objects
  dht.setupSensor();
  
  Serial.print(F("\nPushbutton sensor id: \t"));          //Print sensor IDs
  Serial.println(pb.getObjectID());
  Serial.print(F("DHT11 sensor id: \t"));
  Serial.println(dht.getObjectID());

  Serial.println(F("setup() end. Entering loop() \n"));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pb.readSensor() == HIGH){                            //If the PushButton is pressed then read the IoTDHT11
    
    Serial.print(F("The temperature is: \t"));
    Serial.print(dht.readSensor(TEMPERATURE));
    Serial.println(F(" C."));
    
    Serial.print(F("The humidity is: \t"));
    Serial.print(dht.readSensor(HUMIDITY));
    Serial.println(F("%\n"));
  }//if
  delay(100);
}
