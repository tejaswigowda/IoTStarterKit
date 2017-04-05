/*
The stepper motor in the IoTStarterKit is a 4-phase, 5-wire stepper motor. It comes with a ULN2003 stepper mtor sriver on a breakout board, which accepts 5-12V input.
The class defined here will allow a user to either 1.Set the speed and desired number of steps to travel and then wait for the motor to complete its rotation, or 2.Set the speed and desired number of
steps, then invoke a update() function which will move the stepper by 1/2 step. This object will handle timing in case the rate update() is invoked is faster than the desired step rate, BUT, the stepper can ONLY
move as fast as update() is invoked. i.e. if update() is not invoked, the motor will not step.

Phillip Noel
05-APR-2017
*/

#if !defined(IOT_STEPPER_H)
#define IOT_STEPPER_H

#include "Controller.h"

class IoTStepper : public Controller{
private:
	int A, B, C, D, direction;
	unsigned long waitInterval, currentTime, nextStepTime, currentPos; 
	float desiredPos;

	const uint8_t phases[8] = {0b00001000, 0b00001100, 0b00000100, 0b00000110, 0b00000010, 0b00000011, 0b00000001, 0b00001001};
	uint16_t currentPhase;
	int pins[9] = {0};

public:
	IoTStepper();

	int 	setupController(int, int, int, int);
	
	int 	rotate(float, bool, int);

	int 	setMotion(float, bool, int);
	int 	update();

	unsigned long getCurrentPos();
};

#endif