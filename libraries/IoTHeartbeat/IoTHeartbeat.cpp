#include "IoTHeartbeat.h"

IoTHeartbeat::IoTHeartbeat(){
	objectID = HEARTBEAT_ID;
	usesMCP = false;
}

int IoTHeartbeat::setupSensor(){
	return IOT_UNKNOWN;
}

int IoTHeartbeat::setupSensor(bool enableMCP, int newChannel, int newcsPin = -1){
	usesMCP = enableMCP;
	if(usesMCP == true){
		setupMCP3008(csPin);
	}
	if(channel > 0){
		channel = newChannel;
	}
	if(newcsPin > 0){
		csPin = newcsPin;
	}
	return IOT_SUCCESS;
}

float IoTHeartbeat::readSensor(){
	if(usesMCP == true){
		return readMCP3008(channel, csPin);
	}
	return analogRead(channel);
}