#include "IoTDHT11.h"

IoTDHT11::IoTDHT11(){
	objectID = DHT11_ID;

	sensor = new DHT(readPin, DHT11);
}

IoTDHT11::IoTDHT11(int newReadPin){
	objectID = DHT11_ID;

	if(newReadPin >= 0)
		readPin = newReadPin;

	sensor = new DHT(readPin, DHT11);
}

int IoTDHT11::setReadPin(int newReadPin){
	if(newReadPin < 0){
		return FAILURE;
	}

	readPin = newReadPin;

	return SUCCESS;
}


int IoTDHT11::setupSensor(){
	if(readPin >= 0){
		sensor->begin();
		return SUCCESS;
	}
	
	return FAILURE;
}

int IoTDHT11::setupSensor(int newReadPin){
	if(newReadPin >= 0){
		readPin = newReadPin;
		IoTDHT11::setupSensor();

		return SUCCESS;
	}

	return FAILURE;
}

float IoTDHT11::readSensor(){
	if(readPin < 0){
		return FAILURE;
	}

	return sensor->readTemperature(false);
}

float IoTDHT11::readSensor(bool val){
	if(val == HUMIDITY){
		return sensor->readHumidity();
	}
	
	return sensor->readTemperature(false);
}