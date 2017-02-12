#include "IoTDHT11.h"


IoTDHT11::IoTDHT11() : sensor(readPin, DHT11) {
	objectID = DHT11_ID;
}

IoTDHT11::IoTDHT11(int newReadPin) : sensor(newReadPin, DHT11) {
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
		sensor.begin();
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

	return sensor.readTemperature(false);
}

float IoTDHT11::readSensor(bool val){
	if(val == HUMIDITY){
		return sensor.readHumidity();
	}
	
	return sensor.readTemperature(false);
}