#if !defined(EVENT_H)
#define EVENT_H

#include "IoTStarterKit.h"

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class Event{
public:
				Event();
	virtual int refresh();
};


#endif