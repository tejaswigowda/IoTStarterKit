/*
The stepper motor in the IoTStarterKit is a 4-phase, 5-wire stepper motor. It comes with a ULN2003 stepper mtor sriver on a breakout board, which accepts 5-12V input.
The class defined here will allow a user to specify drection and number of steps to rotate and invoke a update() function which will move the stepper by 1/2 step increments.
The stepper can ONLY move as fast as update() is invoked and appears to become unstable when invoked at a period less than 800 microseconds. In other words, the stepper will
not step if update() is not invoked.

Phillip Noel
05-APR-2017
*/

#if !defined(IOT_STEPPER_H)
#define IOT_STEPPER_H

#include "Controller.h"

class IoTStepper : public Controller{
private:
	uint8_t A, B, C, D, direction;
	unsigned long currentPos; 
	float desiredPos = 0;

	const uint8_t phases[8] = {0b00001000, 0b00001100, 0b00000100, 0b00000110, 0b00000010, 0b00000011, 0b00000001, 0b00001001};
	int pins[9] = {0};

public:
	IoTStepper();

	int 	setupController(uint8_t, uint8_t, uint8_t, uint8_t);		//tell the object which pins to use to control stepper and set pin mode and starting pin state.
	
	int 	setMotion(float, bool);										//tells the stepper motor how many steps to make, in which direction (false is ccw) and the time interval between steps (in micros)
	
	int 	update();													//this must be invoked for stepper to rotate each 1/2 step increment

	unsigned long getCurrentPos();										//return the current number of steps made since setting motion and invoking update.

	int 	end();														//if this is invoked then setupController() must be called again!!
};

#endif