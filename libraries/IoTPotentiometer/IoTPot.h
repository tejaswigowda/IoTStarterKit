/*
This code contains an object to represent the B10k potentiometer included in the FoxDen IoTStarterKit.
This object takes an analog input voltage from the potentiometer, using either an MCP3008 or a chip's onboard ADC, and returns
either the raw voltage, the symmetrical position of the potentiometer (-150-150 degrees), or the asymmetrical potision (0-300 degrees)
For faster reads, the readSennsorInt() function can return the raw voltage as an integer.

Phillip Noel
01-APR-2017
*/

#if !defined (IOT_POT_H)
#define IOT_POT_H

#include "Sensor.h"
#include "MCP3008.h"
#include "IoTKitUtils.h"

class IoTPot : public Sensor{
private:
	bool usesMCP;
	int  csPin;
	int  channel;

public:
	IoTPot();								//default setup

	int setupSensor();						//default setupSensor (can be invoked more than once)
	int setupSensor(bool, int, int);		//supply usesMCP (which ADC to use) and analog input channel used in either case

	float readSensor();						//default readSensor (must be implement since it is virtual and inherited from Sensor)
	float readSensor(int);					//get RAW voltage, symmetricaL position (-150 to 150 degrees), or asymmetrical position (0 to 300 degrees)
	int   readSensorInt();					//get raw voltage as an integer

};

#endif