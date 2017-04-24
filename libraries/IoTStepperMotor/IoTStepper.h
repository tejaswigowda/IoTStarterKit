/*
The stepper motor in the IoTStarterKit is a 4-phase, 5-wire stepper motor. It comes with a ULN2003 stepper mtor sriver on a breakout board, which accepts 5-12V input.
The class defined here will allow a user to specify drection and number of steps to rotate and invoke a update() function which will move the stepper by 1/2 step increments.
The stepper can ONLY move as fast as update() is invoked and appears to become unstable when invoked at a period less than 800 microseconds. In other words, the stepper will
not step if update() is not invoked.

Phillip Noel
23-APR-2017
*/

#if !defined(IOT_STEPPER_H)
#define IOT_STEPPER_H

#include "Actuator.h"

class IoTStepper : public Actuator{
private:
	uint8_t A, B, C, D, direction;
	unsigned long currentPos, desiredChange;
	bool stepForever = false;
	
	const uint8_t states[8] = {0b1000, 0b1100, 0b0100, 0b0110, 0b0010, 0b0011, 0b0001, 0b1001};
	int8_t pinTransitions[9] = {-1};
	
public:
	IoTStepper();

	int 	setupActuator(uint8_t, uint8_t, uint8_t, uint8_t);			//tell the object which pins to use to control stepper and set pin mode and starting pin state.
	
	int 	setMotion(bool, bool, long);								//rotate indefinitely or not, CW or CCW, number of steps (defaults to 0)
	
	int 	update();													//this must be invoked for stepper to rotate each 1/2 step increment

	unsigned long getCurrentPos();										//return the current number of steps made since setting motion and invoking update.

	int 	end();														//if this is invoked then setupController() must be called again!!
};

#endif