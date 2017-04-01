#include "B10k_Pot.h"

B10k_Pot::B10k_Pot(){
	objectID = POTENTIOMETER_ID;

}

int B10k_Pot::setupSensor(){ 		//when no parameters supplied, assume user is using NodeMCU without the MCP3008 (meaning they will use the only ADC channel on the board, A0)			
	usesMCP = false;
	channel = A0;
	return IOT_FAILURE;
}

int B10k_Pot::setupSensor(bool newUsesMCP, int newChannel, int newCSPin = -1){
	if(newChannel < 0 || newChannel > 7 || newCSPin < 0){
		return IOT_FAILURE;
	}

	usesMCP = newUsesMCP;
	channel = newChannel;
	csPin 	= newCSPin;

	if(usesMCP == true){
		setupMCP3008(csPin);
	}

	return IOT_SUCCESS;
}

float B10k_Pot::readSensor(){
	return readSensorInt();
}

float B10k_Pot::readSensor(int mode){
	int reading;
	if(usesMCP == true){
		reading = readMCP3008(channel, csPin);
	}
	else{
		reading = analogRead(channel);
	}

	if(mode == POT_RAW){
		return reading;
	}
	if(mode == POT_SYMMETRICAL){
		return IoTKitUtils::mapIntToFloat(reading, 0, 1023, -150, 150);
	}
	if(mode == POT_ASYMMETRICAL){
		return IoTKitUtils::mapIntToFloat(reading, 0, 1023, 0, 300);
	}

	return NAN;
}

int B10k_Pot::readSensorInt(){
	int reading;

	if(usesMCP == true){
		return readMCP3008(channel, csPin);
	}
	else{
		return analogRead(A0);
	}

	return NAN;
}