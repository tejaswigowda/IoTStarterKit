/*
This class is a wrapper class for the DHT.h library made by Adafruit Industries.
The original library can be found here: https://learn.adafruit.com/dht

Phillip Noel
06-January-2017
*/

#if !defined(IOT_DHT11_H)
#define IOT_DHT11_H


#include "Sensor.h"
#include "DHT.h"

class IoTDHT11 : public Sensor{
protected:
	uint8_t   	readPin = -1; 		//-1 by default to force user to specify the readPin
	DHT   		dhtSensor;

public:
          		IoTDHT11( void);

	//inherited from Sensor.h
    int 		setupSensor(void);
	int   		setupSensor( int);
	float 		readSensor( void);
	float 		readSensor( bool);
};


#endif