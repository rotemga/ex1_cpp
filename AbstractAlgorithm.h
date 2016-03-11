#pragma once

#include "AbstractSensor.h"
#include "OurSensor.h"
#include "House.h"
#include <string>
#include <map>
#include <stdlib.h> 

using namespace std;

class AbstractAlgorithm
{
	OurSensor* thisSensor;
	map<string, int> thisConfig;


public:
	AbstractAlgorithm();
	~AbstractAlgorithm();

	// setSensor is called once when the Algorithm is initialized
	virtual void setSensor(const AbstractSensor& sensor) = 0;
	// setConfiguration is called once when the Algorithm is initialized - see below
	virtual void setConfiguration(map<string, int> config) = 0;
	// step is called by the simulation for each time unit
	virtual Direction step() = 0;
	// this method is called by the simulation either when there is a winner or
	// when steps == MaxSteps - MaxStepsAfterWinner
	// parameter stepsTillFinishing == MaxStepsAfterWinner
	virtual void aboutToFinish(int stepsTillFinishing) = 0;
};

