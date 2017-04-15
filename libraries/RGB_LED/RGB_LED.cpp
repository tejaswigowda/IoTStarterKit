#include "RGB_LED.h"

RGB_LED::RGB_LED(){
	//objectID = RGB_LED_ID;
}

int RGB_LED::setPins(int red, int green, int blue){
	if(red < 0 || green < 0 || blue < 0)
		return IOT_FAILURE;

	redPin = red;
	greenPin = green;
	bluePin = blue;

	return IOT_SUCCESS;
}

void RGB_LED::writeLED(int red, int green, int blue){
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

	analogWrite(redPin, red);
	analogWrite(greenPin, green);
	analogWrite(bluePin, blue);
}