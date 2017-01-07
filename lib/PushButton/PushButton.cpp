#include "PushButton.h"


PushButton::PushButton(){
	objectID = PUSHBUTTON_ID;
}

PushButton::PushButton(int newReadPin){
	objectID = PUSHBUTTON_ID;
	if(newReadPin >= 0)
		readPin = newReadPin;
}

int PushButton::setReadPin(int newReadPin){
	if(newReadPin < 0){
		return FAILURE;
	}

	readPin = newReadPin;

	return SUCCESS;
}


int PushButton::setupSensor(){
	if(readPin >= 0){
		digitalWrite(readPin, LOW);
		pinMode(readPin, INPUT);
		return SUCCESS;
	}
	
	return FAILURE;
}

int PushButton::setupSensor(int newReadPin){
	if(newReadPin >= 0){
		readPin = newReadPin;
		PushButton::setupSensor();

		return SUCCESS;
	}

	return FAILURE;
}

float PushButton::readSensor(){
	if(readPin < 0){
		return FAILURE;
	}

	digitalWrite(readPin, LOW);
	pinMode(readPin, INPUT);
	
	return digitalRead(readPin);

}
