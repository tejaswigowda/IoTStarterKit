/*
    This sketch sends data via HTTP GET requests to data.sparkfun.com service.

    You need to get streamId and privateKey at data.sparkfun.com and paste them
    below. Or just customize this script to talk to other HTTP servers.

*/

#include <ESP8266WiFi.h>
#include "IoTDHT11.h"

const char* ssid     = "Cartel";
const char* password = "Espresso";

const char* host = "34.196.139.141";
const char* streamId   = "....................";
const char* privateKey = "....................";

IoTDHT11 dht(D3);

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.setupSensor();

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


//== == == == == == == == == == == == == == == == == == == == == ==

int value = 0;
long lastRead = millis();

void loop() {
  if (millis() > lastRead) {
    lastRead += millis() + 60000;
    ++value;

    Serial.print("connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 8080;
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
    }

    Serial.println(dht.readSensor(TEMPERATURE));
    Serial.println(dht.readSensor(HUMIDITY));
    // We now create a URI for the request
    String url = "/sendData";
    url += "?t=";
    url += String(dht.readSensor(TEMPERATURE));
    url += "&h=";
    url += String(dht.readSensor(HUMIDITY));
    url += "&key=";
    url += "15974c1d771020e5";
    

    Serial.print("Requesting URL: ");
    Serial.println(url);

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }

    // Read all the lines of the reply from server and print them to Serial
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
    
    Serial.println();
    Serial.println("closing connection");
  }
}

