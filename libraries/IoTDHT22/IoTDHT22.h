/*
This class is a wrapper class for the DHT.h library made by Adafruit Industries.
The original library can be found here: https://learn.adafruit.com/dht

Phillip Noel
06-January-2017
*/

#if !defined(IOT_DHT22_H)
#define IOT_DHT22_H


#include "Sensor.h"
#include "DHT.h"

class IoTDHT22 : public Sensor{
protected:
	uint8_t   	readPin = -1; 		//-1 by default to force user to specify the readPin
	DHT   		dhtsensor;

public:
          		IoTDHT22( void);
      	  		IoTDHT22(  int);
	int   		setReadPin(int);

	//inherited from Sensor.h
	int   		setupSensor(void);
	int   		setupSensor( int);
	float 		readSensor( void);
	float 		readSensor( bool);
};


#endif