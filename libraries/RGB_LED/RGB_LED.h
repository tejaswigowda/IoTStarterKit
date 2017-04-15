#if !defined(RGB_LED_H)
#define RGB_LED_H

#include "IoTStarterKit.h"
#include "Actuator.h"


class RGB_LED : public Actuator{
private:
	int redPin, greenPin, bluePin;

public:
			RGB_LED();

    int 	setPins(int, int, int);
	void 	writeLED(int, int, int);
};


#endif