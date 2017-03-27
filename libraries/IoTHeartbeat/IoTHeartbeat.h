#if !defined(IOT_HEARTBEAT_H)
#define IOT_HEARTBEAT_H


#include "Sensor.h"
#include "MCP3008.h"


class IoTHeartbeat : public Sensor{
private:
	MCP3008		mcp;
	MCP3008*	mcpPtr = &mcp;
	int			channel;
	bool 		usesMCP;
	uint16_t 	buffer[30];

	//int (IoTHeartbeat::*funcptrs[2])(int) = {&IoTHeartbeat::readAnalogPin, &IoTHeartbeat::readADC};

public:
				IoTHeartbeat();
				IoTHeartbeat(bool, int);
				IoTHeartbeat(MCP3008*, int);

	int 		setupSensor();
	int 		setupSensor(int);
	int 		setupSensor(MCP3008*, int);

	float 		readSensor();
	int 		readSensor(int);
};

#endif