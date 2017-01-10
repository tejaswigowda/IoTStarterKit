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
  
  Serial.print("Pushbutton sensor id: \t");
  Serial.println(pb.getObjectID());
  Serial.print("DHT11 sensor id: \t");
  Serial.println(dht.getObjectID());

  Serial.println("setup() end. Entering loop() \n");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(pb.readSensor() == HIGH){
    
    Serial.print("The temperature is: \t");
    Serial.print(dht.readSensor(TEMPERATURE));
    Serial.println(" degrees celsius.");
    
    Serial.print("The humidity is: \t");
    Serial.print(dht.readSensor(HUMIDITY));
    Serial.println("%\n");
  }//if
  delay(100);
}
