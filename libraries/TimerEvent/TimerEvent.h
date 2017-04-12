#if !defined(TIMER_EVENT_H)
#define TIMER_EVENT_H

#include "IoTStarterKit.h"

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class TimerEvent{
private:
	unsigned long scheduledTime, timeInterval;								//used to compare current time to scheduled time of callback
	unsigned long (*getTime)(void);											//set a pointer to address of micro() or millis() so we don't have to check a condition each pass through loop
	void (*callbackFunction)(void);											//all callback functions must take no parameters and return nothng

public:
	TimerEvent(unsigned long, unsigned long, void (*)(void), bool);			//starting time, time interval, callback function, and uses millis/micros

	int refresh();															//check if time event has occurred and invoke callback

};

#endif