#include "IoTKitUtils.h"

float IoTKitUtils::mapFloatToFloat(float var, float fromStart, float fromEnd, float toStart, float toEnd){
	return ( ( (var - fromStart) / (fromEnd - fromStart) ) * (toEnd - toStart) ) + toStart;
}

float IoTKitUtils::mapIntToFloat(int var, int fromStart, int fromEnd, int toStart, int toEnd){
	return ( ( (float)(var - fromStart) / (float)(fromEnd - fromStart) ) * (float)(toEnd - toStart) ) + toStart;	
}