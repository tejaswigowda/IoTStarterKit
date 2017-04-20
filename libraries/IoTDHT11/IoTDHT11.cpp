#include "IoTDHT11.h"


IoTDHT11::IoTDHT11() : dhtSensor(0,0,0){
	objectID = DHT11_ID;
}


int IoTDHT11::setupSensor(){
	if(readPin >= 0){
		dhtSensor = DHT(readPin, DHT11);
		dhtSensor.begin();
		return IOT_SUCCESS;
	}
	
	return IOT_UNKNOWN;
}

int IoTDHT11::setupSensor(int newReadPin){
	if(newReadPin < 0)
		return IOT_FAILURE;

	dhtSensor = DHT(newReadPin, DHT11);
	dhtSensor.begin();

	return IOT_SUCCESS;

}

float IoTDHT11::readSensor(){
	return dhtSensor.readTemperature(false);
}

float IoTDHT11::readSensor(bool val){
	if(readPin < 0){
		return NAN;
	}
	
	if(val == DHT_HUMIDITY){
		return dhtSensor.readHumidity();
	}
	
	return dhtSensor.readTemperature(false);
}