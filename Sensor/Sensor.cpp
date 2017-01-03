#include "Sensor.h"

	Sensor::Sensor(){
	  objectID = sensorObjectID;
}

int	Sensor::setupSensor(){
	  return UNKNOWN;
}

float	Sensor::readSensor(){
	  return UNKNOWN;
}

int	Sensor::getObjectID(){
	  return objectID;
}
