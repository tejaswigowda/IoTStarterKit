#include "IoTStepper.h"

IoTStepper::IoTStepper(){
	objectID = STEPPER_ID;
}

int IoTStepper::setupController(int newA, int newB, int newC, int newD){			//set pin modes, define pins in "pins" array (using bitwise ops), and digitWrite into starting position
	if(A < 0 || B < 0 | C < 0 || D < 0){
		return IOT_FAILURE;
	}

	A = newA;
	B = newB;
	C = newC;
	D = newD;

	pins[8] = A;
  	pins[4] = B;
  	pins[2] = C;
  	pins[1] = D;

	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);

	digitalWrite(A, HIGH);
	digitalWrite(B, HIGH);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);

	return IOT_SUCCESS;
}

int IoTStepper::rotate(float steps, bool newDirection, int newWaitInterval){		//negative number of steps is counterclockwise.
	if(setMotion(steps, direction, newWaitInterval) != IOT_SUCCESS){
		return IOT_FAILURE;
	}

	while(update() != IOT_SUCCESS){
		//do nothing. wait for rotation to complete
		delayMicroseconds(100);
	}

	return IOT_SUCCESS;																//return unknown here because the stepper returns no feedback
}

int IoTStepper::setMotion(float steps, bool newDirection, int newWaitInterval){		//negative number of steps is counterclockwise. If steps == INFINITY then rotate indefinitely
	if(newWaitInterval < 0)
		return IOT_FAILURE;
	waitInterval = newWaitInterval;

	direction = newDirection;

	if(steps == NAN){
		desiredPos = 0;
	}

	if(steps == INFINITY){
		desiredPos = INFINITY;
	}
	else{
		desiredPos = (steps < 0) ? (-1 * steps) : steps;	
	}

	currentPos = 0;
	
	return IOT_SUCCESS;
}

int IoTStepper::update(){
	if(currentPos == desiredPos){													//return success if stepper is at desired position
		return IOT_SUCCESS;
	}

	currentTime = millis();															//check the time and break if it is not time to move the stepper
	if(currentTime < nextStepTime)
		return IOT_UNKNOWN;

	nextStepTime += waitInterval;													//update the schedule for the next step

	/*
	static uint32_t currentPhase;													//decide which pins to toggle to step the motor and update current pos
  	static uint32_t nextPhase;
  	static int currentPin;
  
  	currentPhase++;
  	nextPhase = currentPhase + 1;

  	Serial.println(phases[currentPhase%8]^phases[nextPhase%8]);
  
  	currentPin = pins[phases[currentPhase%8]^phases[nextPhase%8]];
  	digitalWrite(currentPin, !digitalRead(currentPin));

  	*/

	return IOT_UNKNOWN;																//return success when desired number of step (signals) have been made (we get no feedback from motor)
}

unsigned long IoTStepper::getCurrentPos(){
	return currentPos;
}