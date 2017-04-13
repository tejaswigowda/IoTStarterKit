#include "TimerEvent.h"

TimerEvent::TimerEvent(unsigned long start, unsigned long newTimeInterval, void (*newCallbackFunction)(void), bool usesMillis = true){
	if(usesMillis == true)														//use either millis() or micros() to get current system time
		getTime = &millis;
	else
		getTime = &micros;
	
	if(start < 0)
		scheduledTime = 0;
	else
		scheduledTime = start;													//set the start time for TimerEvent (in case user wants to wait to start timer, or synchronize all TimerEvent instances)
	
	if(newTimeInterval < 0)
		timeInterval = 0;
	else
		timeInterval = newTimeInterval;											//set the "delay"	

	callbackFunction = newCallbackFunction;										//every callback function must take no parameters and return nothing!
}

void TimerEvent::setTimeInterval(unsigned long newTimeInterval){
	if(newTimeInterval < 0)
		return;
	else
		timeInterval = newTimeInterval;											//set the "delay"
}

void TimerEvent::setScheduledTime(unsigned long start){
	if(start < 0)
		scheduledTime = 0;
	else
		scheduledTime = start;													//set the start time for TimerEvent (in case user wants to wait to start timer, or synchronize all TimerEvent instances)
}

int TimerEvent::update(){

	if((unsigned long)(getTime() - scheduledTime) > timeInterval){				//getTime() is the function pointer to millis()/micros(). THIS CONDITION STATEMENT WILL HANDLE ROLLOVER (overflow)
		scheduledTime += timeInterval;											//update schedule
		(*callbackFunction)();													//perform callback
		return IOT_SUCCESS;														//return success if event occurred
	}

	return IOT_UNKNOWN;															//return unknown if no event occurred
}