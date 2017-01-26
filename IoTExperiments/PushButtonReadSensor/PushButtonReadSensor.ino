#include "IoTDHT11.h"
#include "PushButton.h"

PushButton pb(D2);
IoTDHT11 dht(D3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  digitalWrite(D0, HIGH);
  
  pinMode(D1, OUTPUT);
  digitalWrite(D1, HIGH);

  pb.setupSensor();
  dht.setupSensor();
  
  Serial.print(F("Pushbutton sensor id: \t"));
  Serial.println(pb.getObjectID());
  Serial.print(F("DHT11 sensor id: \t"));
  Serial.println(dht.getObjectID());

  Serial.println(F("setup() end. Entering loop() \n"));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pb.readSensor() == HIGH){
    
    Serial.print(F("The temperature is: \t"));
    Serial.print(dht.readSensor(TEMPERATURE));
    Serial.println(F(" degrees celsius."));
    
    Serial.print(F("The humidity is: \t"));
    Serial.print(dht.readSensor(HUMIDITY));
    Serial.println(F("%\n"));
  }//if
  delay(100);
}
