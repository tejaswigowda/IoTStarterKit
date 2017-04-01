/*
Phillip Noel
30-MAR-2017
*/


#if !defined(CONTROLLER_H)
#define CONTROLLER_H

#include "IoTStarterKit.h"


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif




class Controller{
protected:
	  		int   objectID;

public:
		    	  Controller(	void);
			int   getObjectID(  void); //This does not need to be overridden
};

#endif
