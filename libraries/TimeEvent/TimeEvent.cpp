#include "TimeEvent.h"

TimeEvent::TimeEvent(unsigned long start, unsigned long newTimeInterval, void (*newCallbackFunction)(void), bool usesMillis = true){
	if(usesMillis == true)														//use either millis() or micros() to get current system time
		getTime = &millis;
	else
		getTime = &micros;
	
	if(start < 0)
		scheduledTime = 0;
	else
		scheduledTime = start;													//set the start time for TimeEvent (in case user wants to wait to start Time, or synchronize all TimeEvent instances)
	
	if(newTimeInterval < 0)
		timeInterval = 0;
	else
		timeInterval = newTimeInterval;											//set the "delay"	

	callbackFunction = newCallbackFunction;										//every callback function must take no parameters and return nothing!
}

void TimeEvent::setTimeInterval(unsigned long newTimeInterval){
	if(newTimeInterval < 0)
		return;
	else
		timeInterval = newTimeInterval;											//set the "delay"
}

void TimeEvent::setScheduledTime(unsigned long start){
	if(start < 0)
		scheduledTime = 0;
	else
		scheduledTime = start;													//set the start time for TimeEvent (in case user wants to wait to start Time, or synchronize all TimeEvent instances)
}

int TimeEvent::update(){

	if((unsigned long)(getTime() - scheduledTime) > timeInterval){				//getTime() is the function pointer to millis()/micros(). THIS CONDITION STATEMENT WILL HANDLE ROLLOVER (overflow)
		scheduledTime += timeInterval;											//update schedule
		(*callbackFunction)();													//perform callback
		return IOT_SUCCESS;														//return success if event occurred
	}

	return IOT_UNKNOWN;															//return unknown if no event occurred
}