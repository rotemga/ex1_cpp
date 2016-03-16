#pragma once
#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <iostream>
#include <vector>
#include <map>
#include "House.h"
#include "Score.h"
#include "AbstractAlgorithm.h"
#include "AbstractSensor.h"
#include "OurSensor.h"
#include "Robot.h"
#include "Battery.h"
using namespace std;

class Simulator {
	vector <House*> houses;
	vector <AbstractAlgorithm*> algorithms;
	map<string, int> config;
	vector<Score> results;

	//void updatePointByDirection(Point& point, Direction direction);
public:
	void run();
	void fillHouses(const string& location);
	void Simulator::setInputHouses(vector<House*> input);
	void Simulator::setInputConfig(map<string, int> input_config);
	void Simulator::setInputAlgo(vector <AbstractAlgorithm*> input_algorithms);
	Simulator();
	virtual ~Simulator();

};

#endif /* SIMULATOR_H_ */

