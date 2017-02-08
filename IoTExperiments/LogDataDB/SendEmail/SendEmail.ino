#include <ESP8266WiFi.h>
#include "IoTDHT11.h"

const char* ssid     = "Cartel";              //wifi network info
const char* password = "Espresso";

const char* host = "34.196.139.141";          //ip address of host

unsigned long wait    = 30000;                //Time period to connect to host
unsigned long timeout = 5000;                 //Timeout interval for connection to host

float temperature;
uint8_t humidity;
IoTDHT11 dht(D3);

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.setupSensor();                          //Setup DHT11 Sensor object

  Serial.print("Connecting to ");             //Begin by connecting to wifi network
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {     //Print dots while waiting to connect so users know program is not hanging
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
}



unsigned long schedule = millis();            //Use a loop on a schedule. Do not use delay()! (delay() will cause your program to "drift").
unsigned long timeoutSchedule;                //This schedule is for responses from the host. (If the host does not respon in timeout millis from time of sending then move on).

void loop() {
  if (millis() > schedule) {
    schedule += wait;

    Serial.print("The temperature is:\t");    //Read from sensors (and save data) immedately
    Serial.print(temperature = dht.readSensor(TEMPERATURE));
    Serial.println(" C.");
    
    Serial.print("The humidity is:\t");  
    Serial.print(humidity = dht.readSensor(HUMIDITY));
    Serial.println("%.");  
     
    WiFiClient client;                        // Use WiFiClient class to create TCP connections
    const int httpPort = 8080;
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }
    
    String url = "/sendData";                 // We now create a URL for the request
    url += "?t=";
    url += String(temperature);
    url += "&h=";
    url += String(humidity);
    url += "&key=";
    url += "15974c1d771020e5";
    

    Serial.print("Requesting URL: ");
    Serial.println(url + "\n\n");

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +   // This will send the request to the server
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    Serial.println("waiting for response");
    timeoutSchedule = millis();             
    while (client.available() == 0) {
      if (millis() - timeoutSchedule > timeout) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }

    while (client.available()) {              // Read all the lines of the response from server and print them to Serial
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
    
    Serial.println();
    Serial.println("closing connection");
  }
}

