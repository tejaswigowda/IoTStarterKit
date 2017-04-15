#if !defined(IOT_HEARTBEAT_H)
#define IOT_HEARTBEAT_H


#include "Sensor.h"
#include "MCP3008.h"


class IoTHeartbeat : public Sensor{
private:
	int			channel;
	uint8_t		csPin;
	bool 		usesMCP;
	uint16_t 	buffer[30];

public:
				IoTHeartbeat();

	int 		setupSensor();
	int 		setupSensor(bool, int, int);

	float 		readSensor();
};

#endif