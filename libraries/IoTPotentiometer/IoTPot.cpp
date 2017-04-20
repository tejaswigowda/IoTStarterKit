#include "IoTPot.h"

IoTPot::IoTPot(){
	objectID = POTENTIOMETER_ID;

}

int IoTPot::setupSensor(){ 						//when no parameters supplied, assume user is using NodeMCU without the MCP3008 (meaning they will use the only ADC channel on the board, A0)			
	usesMCP = false;
	channel = 0;
	return IOT_FAILURE;
}

int IoTPot::setupSensor(bool newUsesMCP, int newChannel, int newCSPin = -1){
	if(newChannel < 0 || newChannel > 7 || newCSPin < 0){		//make sure valid pin is supplied
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

float IoTPot::readSensor(){
	return readSensorInt();
}

float IoTPot::readSensor(int mode = POT_RAW){					//return symmetric or assymetric angle; or raw ADC output (10 bits)
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

	return reading;
}

int IoTPot::readSensorInt(){
	int reading;

	if(usesMCP == true){
		return readMCP3008(channel, csPin);
	}
	else{
		return analogRead(A0);
	}

	return IOT_FAILURE;
}