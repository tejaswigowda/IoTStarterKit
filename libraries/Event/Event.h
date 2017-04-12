/*
This header file defines the interface for Event type objects. All Events must be able to refresh and invoke a callback function
when a specified event occurs.

Phillip Noel
12-APR-2017
*/

#if !defined(EVENT_H)
#define EVENT_H

#include "IoTStarterKit.h"

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class Event{
protected:
	void (*callbackFunction)(void);	//every callback function must take no paramteres and return nothing!
public:
				Event();			//constructor
	virtual int refresh();			//Every Event should be able to refresh (and invoke a callback)
};


#endif