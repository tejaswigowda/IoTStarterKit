#include "Sensor.h"

Sensor::Sensor(){
	  objectID = SENSOR_ID;
}

int	Sensor::setupSensor(){
	  return IOT_UNKNOWN;
}

float Sensor::readSensor(){
	  return NAN;
}

int	Sensor::getObjectID(){
	  return objectID;
}
