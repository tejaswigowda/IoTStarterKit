#include "PushButton.h"


PushButton::PushButton(){
	objectID = pushButtonObjectID;
}

PushButton::PushButton(int newReadPin){
	objectID = pushButtonObjectID;
	if(newReadPin >= 0)
		readPin = newReadPin;
}

int PushButton::setReadPin(int newReadPin){
	if(newReadPin < 0){
		return FAIL;
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
	
	return FAIL;
}

int PushButton::readSensor(){
	if(readPin < 0){
		return FAIL;
	}

	pinMode(readPin, INPUT);
	digitalWrite(readPin, LOW);

	return digitalRead(readPin);

}
