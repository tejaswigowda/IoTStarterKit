#include "IoTHeartbeat.h"

IoTHeartbeat::IoTHeartbeat(){
	objectID = HEARTBEAT_ID;
	usesMCP = false;
}

IoTHeartbeat::IoTHeartbeat(bool enableMCP, int newChannel){
	objectID = HEARTBEAT_ID;
	usesMCP = enableMCP;
}

int IoTHeartbeat::setupSensor(){
	return IOT_UNKNOWN;
}

int IoTHeartbeat::setupSensor(MCP3008* adc, int newChannel){
	mcp = *adc;
	return IOT_SUCCESS;
}

float IoTHeartbeat::readSensor(){
	return ((IoTHeartbeat*)this->*funcptrs[0])(0);
}

int IoTHeartbeat::readADC(int channel){
	return mcp.readSensorInt(channel);
}

int IoTHeartbeat::readAnalogPin(int pin){
	return analogRead(pin);
}