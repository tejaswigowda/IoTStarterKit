/*
This header file contains definitions used in the IoTStarterKit. These are in one place, rather than in respective folders
to more easily prevent naming conflicts


Phillip Noel
05-January-2017
*/


#if !defined(IOTSTARTERKIT_H)
#define IOTSTARTERKIT_H

/*
DO NOT use "index" as a variable (sans quotes) in sketches using the NodeMCU. "index" is used somewhere in the esp core and the compiler will return a "redefinition" error.
*/

#define IOT_SUCCESS  		0
#define IOT_FAILURE        -1
#define IOT_UNKNOWN    	   -1

#define SENSOR_ID 	   	   -1
#define CONTROLLER_ID		1

#define PUSHBUTTON_ID 		2
#define DHT11_ID 			3
#define DHT22_ID			8
#define HEARTBEAT_ID    	4
#define POTENTIOMETER_ID 	6

#define RGB_LED_ID			5
#define STEPPER_ID			7


#define DHT_HUMIDITY 	false
#define DHT_TEMPERATURE true

#define RGB_RED 	255, 0, 0
#define RGB_ORANGE  255, 150, 0
#define RGB_YELLOW 	150, 255, 0
#define RGB_GREEN 	0, 255, 0
#define RGB_BLUE 	0, 255, 0
#define RGB_INDIGO  0, 150, 255
#define RGB_VIOLET 	255, 0, 255
#define RGB_WHITE 	150, 255, 255
#define RGB_OFF		0, 0, 0

#define POT_RAW 		 0
#define POT_SYMMETRICAL  1
#define POT_ASYMMETRICAL 2

#define USESMCP true
#define NOMCP 	false

#define STEPPER_COUNTERCLOCKWISE 	false
#define STEPPER_CLOCKWISE 			true

#define MILLIS true
#define MICROS false

#endif
