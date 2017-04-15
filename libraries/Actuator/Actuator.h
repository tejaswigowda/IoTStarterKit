/*
Phillip Noel
30-MAR-2017
*/


#if !defined(ACTUATOR_H)
#define ACTUATOR_H

#include "IoTStarterKit.h"


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif




class Actuator{
protected:
	  		int   objectID;

public:
		    	  Actuator(	void);
			int   getObjectID(  void); //This does not need to be overridden
};

#endif
