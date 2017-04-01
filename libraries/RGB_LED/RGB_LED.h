#if !defined(RGB_LED_H)
#define RGB_LED_H

#include "IoTStarterKit.h"
#include "Controller.h"


class RGB_LED : public Controller{
private:
	int redPin, greenPin, bluePin;

public:
			RGB_LED();
		 	RGB_LED(int, int, int);

    void 	setPins(int, int, int);
	void 	writeLED(int, int, int);
};


#endif