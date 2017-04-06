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
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);

	return IOT_SUCCESS;
}

int IoTStepper::rotate(float steps, bool newDirection, int newWaitInterval){		//negative number of steps is counterclockwise.
	if(setMotion(steps, newDirection, newWaitInterval) != IOT_SUCCESS){
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
		if(newDirection == false){
			desiredPos *= -1;
		}	
	}

	currentPos = 0;
	
	return IOT_SUCCESS;
}

int IoTStepper::update(){
	static unsigned long currentTime, nextStepTime;
	static uint8_t currentPhase, nextPhase;
  	static int currentPin;

  	if(desiredPos != INFINITY){
	  	if(currentPos == (unsigned long)desiredPos){									//return success if stepper is at desired position
			return IOT_SUCCESS;
		}
  	}
	

	currentTime = millis();																//check the time and break if it is not time to move the stepper
	if(currentTime < nextStepTime)
		return IOT_UNKNOWN;
	nextStepTime += waitInterval;														//update the schedule for the next step

	
	currentPhase = currentPos % 8;
	currentPos += (direction == true) ? 1 : -1;
  	nextPhase = currentPos % 8;
  
  	currentPin = phases[currentPhase]^phases[nextPhase];

  	digitalWrite(pins[currentPin], !digitalRead(pins[currentPin]));

	return IOT_UNKNOWN;																	//return success when desired number of step (signals) have been made (we get no feedback from motor)
}

unsigned long IoTStepper::getCurrentPos(){
	return currentPos;
}

int IoTStepper::end(){																	//if this function is invoked then setupController must be invoked again!
	digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);

	desiredPos = 0;

	return IOT_SUCCESS;
}