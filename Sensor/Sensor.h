#if !defined(SENSOR_H)
#define SENSOR_H

#include "Peripheral.h"
#include <Arduino.h>

class Sensor{
protected:
	const 	int sensorObjectID = SENSOR_ID;
	  	int objectID;

public:
		    Sensor(		    );
		int getObjectID(	void); //This does not need to be overridden

	//These functions must be overridden
	virtual int setupSensor(	void) = 0;
	virtual int readSensor(		void) = 0;
};

#endif
