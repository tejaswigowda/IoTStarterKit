/*
Phillip Noel
05-January-2017
*/


#if !defined(SENSOR_H)
#define SENSOR_H

#include "IoTStarterKit.h"


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif




class Sensor{
protected:
	  		int   objectID;

public:
		    	  Sensor(		void);
			int   getObjectID(  void); //This does not need to be overridden

	//These functions must be overridden
	virtual int   setupSensor(	void) = 0;
	virtual float readSensor(	void) = 0;
};

#endif
