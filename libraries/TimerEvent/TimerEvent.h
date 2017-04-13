/*
This header defines a a TimerEvent. TimerEvents inherit from the Event.h object. When updated they check
the system time and compare it to a scheduled time. If some time interval has elapsed then the task schedule
is updated and a callback function is invoked.

Phillip Noel
12-APR-2017
*/

#if !defined(TIMER_EVENT_H)
#define TIMER_EVENT_H

#include "Event.h"

class TimerEvent : public Event{
protected:
	unsigned long scheduledTime, timeInterval;								//used to compare current time to scheduled time of callback
	unsigned long (*getTime)(void);											//set a pointer to address of micro() or millis() so we don't have to check a condition each pass through loop

public:
	TimerEvent(unsigned long, unsigned long, void (*)(void), bool);			//starting time, time interval, callback function, and uses millis()/micros()

	void setTimeInterval(unsigned long);									//reset the time interval
	void setScheduledTime(unsigned long);									//explicitly set next schedule time (can be used for synchronizing TimerEvents)

	int update();															//check if time event has occurred and invoke callback

};

#endif