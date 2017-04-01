/*
This header contains functions and possibly objects that are used by objects in the IoTStarterKit. These functions and objects are under a namespace and can be used users in their sketches as well.

Phillip Noel
01-APR-2017
*/

namespace IoTKitUtils{

	float mapFloatToFloat(float var, float fromStart, float fromEnd, float toStart, float toEnd);	//i.e on a scale of 0-1023, the number 512 maps to 50 on a scale of 0-100.
	float mapIntToFloat(int var, int fromStart, int fromEnd, int toStart, int toEnd);

}