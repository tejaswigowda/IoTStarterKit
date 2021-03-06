/*
*   This sketch reads from the IoTDHT11 sensors at constant intervals and sends the data to a remote host using the ESP8266WiFi object
*/

#include <ESP8266WiFi.h>
#include "IoTDHT11.h"

const char* ssid      = "Cartel";             //Wifi network info
const char* password  = "Espresso";

const char* host      = "34.196.139.141";     //IP address of host

unsigned long wait    = 10000;                //Time period to connect to host
unsigned long timeout = 5000;                 //Timeout interval for connection to host

float temperature;                            //Store readings from IoTDHT11 in variables so you only read from sensor once in a loop
uint8_t humidity;
IoTDHT11 dht(2);

void setup() {
  Serial.begin(115200);
  delay(10);                                  //delay(10) so the Serial monitor does not prinbt garble


  dht.setupSensor();                          //Setup DHT11 Sensor object

  Serial.print(F("Connecting to "));          //Begin by connecting to wifi network
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {     //Print dots while waiting to connect so users know program is not hanging
    delay(500);
    Serial.print(".");
  }

  Serial.println(F("WiFi connected"));
}



unsigned long schedule = millis();            //Use a loop on a schedule. Do not use delay()! (delay() will cause your program to "drift").
unsigned long timeoutSchedule;                //This is a nested schedule for responses from the host. (If the host does not respon in timeout millis from time of sending then move on).

void loop() {
  if (millis() > schedule) {                  //Pass through if the current time is not greater than the schedule time.
    schedule += wait;

    Serial.print(F("The temperature is:\t")); //Read from sensors (and save data) immedately
    Serial.print(temperature = dht.readSensor(DHT_TEMPERATURE));
    Serial.println(F(" C."));
    
    Serial.print(F("The humidity is:\t"));  
    Serial.print(humidity = dht.readSensor(DHT_HUMIDITY));
    Serial.println(F("%."));  
     
    WiFiClient client;                        // Use WiFiClient class to create TCP connections
    const int httpPort = 8080;
    if (!client.connect(host, httpPort)) {
      Serial.println(F("connection failed"));
      return;
    }
    
    String url = "/sendData";                 // We now create a URL for the request
    url += "?t=";
    url += String(temperature);
    url += "&h=";
    url += String(humidity);
    url += "&key=";
    url += "15974c1d771020e5";
    

    Serial.print(F("Requesting URL: "));
    Serial.println(url + "\n\n");

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +   // This will send the request to the server
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    Serial.println(F("waiting for response"));
    timeoutSchedule = millis();             
    while (client.available() == 0) {
      if (millis() - timeoutSchedule > timeout) {
        Serial.println(F(">>> Client Timeout !"));
        client.stop();
        return;
      }//if
    
    }//while

    while (client.available()) {               // Read all the lines of the response from server and print them to Serial
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }//while
    
    Serial.println();
    Serial.println(F("closing connection"));
  }//if
}//loop

