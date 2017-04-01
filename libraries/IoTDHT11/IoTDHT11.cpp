#include "IoTDHT11.h"


IoTDHT11::IoTDHT11() : dhtsensor(readPin, DHT11, 30) {						//use 30 for esp8266?
	objectID = DHT11_ID;
}

IoTDHT11::IoTDHT11(int newReadPin) : dhtsensor(newReadPin, DHT11, 30) {
	objectID = DHT11_ID;

	if(newReadPin <= 0)
		IoTDHT11();

}

int IoTDHT11::setReadPin(int newReadPin){
	if(newReadPin < 0){
		return IOT_FAILURE;
	}

	readPin = newReadPin;

	return IOT_SUCCESS;
}


int IoTDHT11::setupSensor(){
	if(readPin >= 0){
		dhtsensor.begin();
		return IOT_SUCCESS;
	}
	
	return IOT_UNKNOWN;
}

int IoTDHT11::setupSensor(int newReadPin){

	if(setReadPin(newReadPin) == IOT_UNKNOWN){
		return IOT_FAILURE;
	}

	IoTDHT11::setupSensor();

	return IOT_SUCCESS;

}

float IoTDHT11::readSensor(){
	if(readPin < 0){
		return NAN;
	}

	return dhtsensor.readTemperature(false);
}

float IoTDHT11::readSensor(bool val){
	if(val == HUMIDITY){
		return dhtsensor.readHumidity();
	}
	
	return dhtsensor.readTemperature(false);
}