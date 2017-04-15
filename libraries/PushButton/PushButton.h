/*
Phillip Noel
05-January-2017
*/


#if !defined(PUSH_BUTTON_H)
#define PUSH_BUTTON_H

#include "Sensor.h"

class PushButton : public Sensor{
protected:
			int   readPin = -1; //-1 by default to force user to specify the readPin

public:
	              PushButton( void);
			int   setReadPin(  int);

			//inherited from Sensor.h
			int   setupSensor(void);
			int   setupSensor( int);
			float readSensor( void);
};

#endif
