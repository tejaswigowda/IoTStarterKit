#include "IoTDHT22.h"


IoTDHT22::IoTDHT22() : dhtSensor(0,0,0){
	objectID = DHT22_ID;
}


int IoTDHT22::setupSensor(){
	if(readPin >= 0){
		dhtSensor = DHT(readPin, DHT22);
		dhtSensor.begin();
		return IOT_SUCCESS;
	}
	
	return IOT_UNKNOWN;
}

int IoTDHT22::setupSensor(int newReadPin){
	if(newReadPin < 0)
		return IOT_FAILURE;

	dhtSensor = DHT(newReadPin, DHT22);
	dhtSensor.begin();

	return IOT_SUCCESS;

}

float IoTDHT22::readSensor(){
	if(readPin < 0){
		return NAN;
	}

	return dhtSensor.readTemperature(false);
}

float IoTDHT22::readSensor(bool val){
	if(val == DHT_HUMIDITY){
		return dhtSensor.readHumidity();
	}
	
	return dhtSensor.readTemperature(false);
}