#include "IoTStepper.h"

IoTStepper::IoTStepper(){
	objectID = STEPPER_ID;
}

int IoTStepper::setupController(uint8_t newA, uint8_t newB, uint8_t newC, uint8_t newD){			//set pin modes, define pins in "pins" array (using bitwise ops), and digitWrite into starting position
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

	digitalWrite(A, HIGH);																			//The initial state must be 1000!
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);

	return IOT_SUCCESS;
}

int IoTStepper::rotate(float steps, bool newDirection, uint32_t newWaitInterval){
	if(setMotion(steps, newDirection, newWaitInterval) != IOT_SUCCESS){
		return IOT_FAILURE;
	}

	while(update() != IOT_SUCCESS){
		//do nothing. wait for rotation to complete
		delayMicroseconds(20);
	}

	return IOT_SUCCESS;
}

int IoTStepper::setMotion(float steps, bool newDirection, uint32_t newWaitInterval){ //negative number of steps is counterclockwise. If steps == INFINITY then rotate indefinitely
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
		desiredPos = (steps < 0) ? (-1 * steps) : steps;							//desiredPos is negative if the stepper should rotate CCW
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
	

	currentTime = micros();																//check the time and break if it is not time to move the stepper
	if((unsigned long)(currentTime - nextStepTime) < waitInterval)
		return IOT_UNKNOWN;
	nextStepTime += waitInterval;														//update the schedule for the next step
	
	currentPhase = currentPos % 8;														//the stepper has 8 different states
	currentPos += (direction == true) ? 1 : -1;											//increment or decrement position according to direction
  	nextPhase = currentPos % 8;
  
  	currentPin = phases[currentPhase]^phases[nextPhase];

  	digitalWrite(pins[currentPin], !digitalRead(pins[currentPin]));						//only one pin changes between each consecutive state

  	//if(nextStepTime < 4294967295 && nextStepTime > (4294967295 - waitInterval))			//this handles program counter overflow
	//	nextStepTime += waitInterval;

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