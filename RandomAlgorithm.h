#pragma once


#ifndef RANDOMALGORITHM_H_
#define RANDOMALGORITHM_H_
using namespace std;

#include "AbstractAlgorithm.h"

class RandomAlgorithm : public  AbstractAlgorithm {

	OurSensor thisSensor;
	map<string, int> thisConfig;

public:
	RandomAlgorithm();
	virtual ~RandomAlgorithm();

	//Blocking Copy and Assignment
	RandomAlgorithm(const RandomAlgorithm&) = delete;
	RandomAlgorithm& operator=(const RandomAlgorithm&) = delete;

	virtual void setSensor(const AbstractSensor& sensor);
	virtual void setConfiguration(map<string, int> config);
	virtual Direction step();
	virtual void aboutToFinish(int stepsTillFinishing);

};

#endif /* RANDOMALGORITHM_H_ */

