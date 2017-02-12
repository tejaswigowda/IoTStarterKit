/*
This class is a wrapper class for the DHT.h library made by Adafruit Industries.
The original library can be found here: https://learn.adafruit.com/dht

Phillip Noel
06-January-2017
*/

#if !defined(IOT_DHT_H)
#define IOT_DHT_H


#include "Sensor.h"
#include "DHT.h"

#define HUMIDITY false
#define TEMPERATURE true

class IoTDHT11 : public Sensor{
protected:
			int   readPin = -1; //-1 by default to force user to specify the readPin
			DHT   sensor;

public:
	              IoTDHT11( void);
		      	  IoTDHT11(  int);
			int   setReadPin(int);

			//inherited from Sensor.h
			int   setupSensor(void);
			int   setupSensor( int);
			float readSensor( void);
			float readSensor( bool);
};


#endif