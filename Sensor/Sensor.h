#if !defined(SENSOR_H)
#define SENSOR_H

#include "Peripheral.h"
#include <Arduino.h>

class Sensor{
protected:
	  		int objectID;

public:
		    	Sensor(		  void);
			int getObjectID(  void); //This does not need to be overridden

	//These functions must be overridden
	virtual int   setupSensor(	void) = 0;
	virtual float readSensor(	void) = 0;
};

#endif
