#include "IoTDHT22.h"


IoTDHT22::IoTDHT22() : dhtsensor(readPin, DHT22) {
	objectID = DHT22_ID;
}

IoTDHT22::IoTDHT22(int newReadPin) : dhtsensor(newReadPin, DHT22) {
	objectID = DHT22_ID;

	if(newReadPin <= 0)
		IoTDHT22();

}

int IoTDHT22::setReadPin(int newReadPin){
	if(newReadPin < 0){
		return IOT_FAILURE;
	}

	readPin = newReadPin;

	return IOT_SUCCESS;
}


int IoTDHT22::setupSensor(){
	if(readPin >= 0){
		dhtsensor.begin();
		return IOT_SUCCESS;
	}
	
	return IOT_UNKNOWN;
}

int IoTDHT22::setupSensor(int newReadPin){

	if(setReadPin(newReadPin) == IOT_UNKNOWN){
		return IOT_FAILURE;
	}

	IoTDHT22::setupSensor();

	return IOT_SUCCESS;

}

float IoTDHT22::readSensor(){
	if(readPin < 0){
		return NAN;
	}

	return dhtsensor.readTemperature(false);
}

float IoTDHT22::readSensor(bool val){
	if(val == DHT_HUMIDITY){
		return dhtsensor.readHumidity();
	}
	
	return dhtsensor.readTemperature(false);
}