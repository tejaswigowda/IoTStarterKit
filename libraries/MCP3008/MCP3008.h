#if !defined(MCP3008_H)
#define MCP3008_H

#include "Sensor.h"

#define CH0 0
#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
#define CH5 5
#define CH6 6
#define CH7 7

#define DEFAULT_CLK 	14
#define DEFAULT_MOSI 	13
#define DEFAULT_MISO 	12
#define DEFAULT_CS 		15

class MCP3008 : public Sensor{
  private:
  int _clockpin, _mosipin, _misopin, _cspin;
	
  public:
  	MCP3008();
    MCP3008(int clockpin, int mosipin, int misopin, int cspin);
    int 	setupSensor();
    float 	readSensor();
    float 	readSensor(int);
    int		readSensorInt(int);
};


#endif