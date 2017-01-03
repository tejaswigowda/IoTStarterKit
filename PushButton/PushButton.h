#if !defined(PUSH_BUTTON_H)
#define PUSH_BUTTON_H

#include "Sensor.h"

class PushButton : public Sensor{
protected:
	const 	int pushButtonObjectID = PUSHBUTTON_ID;
		int readPin 	       = -1; //-1 by default to force user to specify the readPin

public:
	            PushButton(	void);
		    PushButton(	 int);
		int setReadPin(  int);

		//inherited from Sensor.h
		int setupSensor(void);
		int setupSensor( int);
		int readSensor( void);
};

#endif
