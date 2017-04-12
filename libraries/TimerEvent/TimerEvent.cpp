#include "TimerEvent.h"

TimerEvent::TimerEvent(unsigned long start, unsigned long newTimeInterval, void (*newCallbackFunction)(void), bool usesMillis = true){
	if(usesMillis == true){														//use either millis() or micros() to get current system time
		getTime = &millis;
	}
	else{
		getTime = &micros;
	}
	scheduledTime = start;														//set the start time for TimerEvent (in case user wants to wait to start timer, or synchronize all TimerEvent instances)
	timeInterval = newTimeInterval;						
	callbackFunction = newCallbackFunction;										//every callback function must take no parameters and return nothing!
}

int TimerEvent::refresh(){

	if((unsigned long)(getTime() - scheduledTime) > timeInterval){				//getTime() is the function pointer to millis()/micros(). THIS CONDITION STATEMENT WILL HANDLE ROLLOVER (overflow)
		scheduledTime += timeInterval;											//update schedule
		(*callbackFunction)();													//perform callback
		return IOT_SUCCESS;														//return success if event occurred
	}

	return IOT_UNKNOWN;															//return unknown if no event occurred
}