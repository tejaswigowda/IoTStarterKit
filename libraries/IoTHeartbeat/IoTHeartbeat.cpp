#include "IoTHeartbeat.h"

IoTHeartbeat::IoTHeartbeat(){
	objectID = HEARTBEAT_ID;
	usesMCP = false;
}

IoTHeartbeat::IoTHeartbeat(bool enableMCP, int newChannel){
	objectID = HEARTBEAT_ID;
	usesMCP = enableMCP;
	channel = newChannel;
}

IoTHeartbeat::IoTHeartbeat(MCP3008* newMCP, int newChannel){
	objectID = HEARTBEAT_ID;
	usesMCP = true;
	mcpPtr = newMCP;
	channel = newChannel;
}

int IoTHeartbeat::setupSensor(){
	return IOT_UNKNOWN;
}

int IoTHeartbeat::setupSensor(int newChannel){
	if(channel > 0){
		channel = newChannel;
		return IOT_SUCCESS;	
	}
	return IOT_FAILURE;
}

int IoTHeartbeat::setupSensor(MCP3008* newMCP, int newChannel){
	mcpPtr = newMCP;
	channel = newChannel;
	return IOT_SUCCESS;
}

int IoTHeartbeat::readSensor(int newChannel){
	if(usesMCP == true){
		return readADC(channel);
	}
	return analogRead(channel);

	//return ((IoTHeartbeat*)this->*funcptrs[usesMCP])(newChannel);
}