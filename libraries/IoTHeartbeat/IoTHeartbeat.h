#if !defined(IOT_HEARTBEAT_H)
#define IOT_HEARTBEAT_H


#include "Sensor.h"
#include "MCP3008.h"


class IoTHeartbeat : public Sensor{
private:
	MCP3008		mcp;
	int			channel;
	bool 		usesMCP;
	uint16_t 	buffer[30];
	int (IoTHeartbeat::*funcptrs[2])(int) = {&IoTHeartbeat::readADC, &IoTHeartbeat::readAnalogPin};

public:
				IoTHeartbeat();
				IoTHeartbeat(bool, int);	
	int 		setupSensor();
	int 		setupSensor(MCP3008*, int);
	float 		readSensor();
	//float 		readSensor(int);

	int 		readADC(int);
	int 		readAnalogPin(int);
};

#endif