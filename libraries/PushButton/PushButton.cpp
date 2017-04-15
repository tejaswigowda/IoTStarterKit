#include "PushButton.h"


PushButton::PushButton(){
	objectID = PUSHBUTTON_ID;
}

int PushButton::setReadPin(int newReadPin){
	if(newReadPin < 0){
		return IOT_FAILURE;
	}

	readPin = newReadPin;

	return IOT_SUCCESS;
}


int PushButton::setupSensor(){
	if(readPin >= 0){
		pinMode(readPin, INPUT);
		return IOT_SUCCESS;
	}
	
	return IOT_FAILURE;
}

int PushButton::setupSensor(int newReadPin){
	if(newReadPin >= 0){
		readPin = newReadPin;
		setupSensor();

		return IOT_SUCCESS;
	}

	return IOT_FAILURE;
}

float PushButton::readSensor(){
	if(readPin < 0){
		return NAN;
	}

	pinMode(readPin, INPUT);
	
	return digitalRead(readPin);

}
