#include "IoTStepper.h"

IoTStepper::IoTStepper(){
	objectID = STEPPER_ID;
}

int IoTStepper::setupActuator(uint8_t newA, uint8_t newB, uint8_t newC, uint8_t newD){ //set pin modes, define pins in "pins" array (using bitwise ops), and digitWrite into starting position
	if(A < 0 || B < 0 | C < 0 || D < 0){
		return IOT_FAILURE;
	}

	A = newA;
	B = newB;
	C = newC;
	D = newD;

	pinMode(A, OUTPUT);
	pinMode(B, OUTPUT);
	pinMode(C, OUTPUT);
	pinMode(D, OUTPUT);

	digitalWrite(A, HIGH);																//The initial state must be 0b1000!
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);

	return IOT_SUCCESS;
}


int IoTStepper::setMotion(bool newStepForever, bool newDirection, long steps = 0){		//negative number of steps is counterclockwise. -2,147,483,648 .. 2,147,483,647 steps

	stepForever = newStepForever;

	direction = newDirection;

	desiredChange = steps;
	if(newDirection == STEPPER_CLOCKWISE && desiredChange > 0)
		desiredChange *= -1;
	if(newDirection == STEPPER_COUNTERCLOCKWISE && desiredChange < 0)
		desiredChange *= -1;	

	currentPos = 0;
	
	return IOT_SUCCESS;
}

int IoTStepper::update(){																//must be invoked for every 1/2-step the motor moves!
	static uint8_t currentPhase;

  	if(stepForever == false){
	  	if(currentPos == desiredChange){												//return success if stepper is at desired position
			return IOT_SUCCESS;
		}
  	}
	
	currentPhase = currentPos % 8;														//the stepper has 8 different states
	currentPos += (direction ==  STEPPER_COUNTERCLOCKWISE) ? 1 : -1;					//increment or decrement position according to direction
  	
  	digitalWrite(*pinToggle[currentPhase], !digitalRead(*pinToggle[currentPhase]));
  	
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

	desiredChange = 0;

	return IOT_SUCCESS;
}