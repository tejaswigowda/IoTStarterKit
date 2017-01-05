#if !defined(PUSH_BUTTON_H)
#define PUSH_BUTTON_H

#include "Sensor.h"

class PushButton : public Sensor{
protected:
			int    readPin      = -1; //-1 by default to force user to specify the readPin

public:
	              	       PushButton( void);
		      	       PushButton(  int);
			int    setReadPin(  int);

			int    setupSensor( int);	
		        //The functions below are inherited from Sensor.h
			int    setupSensor(void);
			float  readSensor( void);
};

#endif
