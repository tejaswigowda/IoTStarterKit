#if !defined(TIMER_EVENT_H)
#define TIMER_EVENT_H

#include "Event.h"

class TimerEvent : public Event{
protected:
	unsigned long scheduledTime, timeInterval;								//used to compare current time to scheduled time of callback
	unsigned long (*getTime)(void);											//set a pointer to address of micro() or millis() so we don't have to check a condition each pass through loop

public:
	TimerEvent(unsigned long, unsigned long, void (*)(void), bool);			//starting time, time interval, callback function, and uses millis/micros

	int refresh();															//check if time event has occurred and invoke callback

};

#endif