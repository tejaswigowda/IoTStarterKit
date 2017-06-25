/*
*  This sketch reads from PushButton IoTDHT11 objects. If the PushButton is pressed then the program reads from the IoTDHT11 object
*  and sends the reading to a remote host using the ESP8266WiFi object.
*/

#include <ESP8266WiFi.h>

const char* ssid        = "Cartel";           //Wifi network info
const char* password    = "Espresso";

const char* host        = "52.33.201.84";   //IP address of host

unsigned long wait      = 30000;              //Time period to connect to host
unsigned long timeout   = 5000;               //Timeout interval for connection to host
unsigned long readDelay = 1000;               //Do not send data more than once every 1 second



void setup() {
  Serial.begin(115200);
  delay(10);                                  //delay(10) so the Serial monitor does not prinbt garble
  Serial.println();
  
  pinMode(D2, INPUT);                           //Setup Sensor objects

  Serial.print(F("\nConnecting to "));        //Begin by connecting to wifi network
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {     //Print dots while waiting to connect so users know program is not hanging
    delay(500);
    Serial.print(".");
  }

  Serial.println(F("WiFi connected"));
}



unsigned long readSchedule = millis();        //time of last sensor read (used with readDelay)
unsigned long timeoutSchedule;                //This is a nested schedule for responses from the host. (If the host does not respon in timeout millis from time of sending then move on).
int readPin = D2;
int smp = 0;

void loop() {
  Serial.println(digitalRead(D2));
  
  if (digitalRead(D2) == LOW && smp == 1) {  //Pass through if the button is not pressed or readDelay has not elapsed
    smp = 0;
    WiFiClient client;                        // Use WiFiClient class to create TCP connections
    const int httpPort = 8080;
    if (!client.connect(host, httpPort)) {
      Serial.println(F("connection failed"));
      return;
    }
    String url = "/sendEvent";                 // We now create a URL for the request
    url += "?e=";
    url += "zellerfamilyhome@gmail.com";
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

    while (client.available()) {              // Read all the lines of the response from server and print them to Serial
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }//while
    
    Serial.println();
    Serial.println(F("closing connection"));
  }//if
  else{
    smp = 1;
  }
}//loop
