#include "RGB_LED.h"

	RGB_LED::RGB_LED(){	
}

	RGB_LED::RGB_LED(int red, int green, int blue){
	redPin = red;
	greenPin = green;
	bluePin = blue;
}

void RGB_LED::setPins(int red, int green, int blue){
	redPin = red;
	greenPin = green;
	bluePin = blue;
}

void RGB_LED::writeLED(int red, int green, int blue){
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

	analogWrite(redPin, red);
	analogWrite(greenPin, green);
	analogWrite(bluePin, blue);
}