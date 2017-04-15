#include "Event.h"

Event::Event(){}

int setupEvent(){
	return IOT_UNKNOWN;
}

int Event::start(){
	enable = true;

	return IOT_SUCCESS;
}

int Event::stop(){
	enable = false;

	return IOT_SUCCESS;
}

int Event::update(){
	if(enable == false)
		return IOT_FAILURE;
	return IOT_SUCCESS;
}