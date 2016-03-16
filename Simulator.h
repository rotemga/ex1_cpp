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
#include "Point.h"
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
	void setInputHouses(vector<House*> input);
	void setInputConfig(map<string, int> input_config);
	void setInputAlgo(vector <AbstractAlgorithm*> input_algorithms);
	void createScore(int num_steps, int pos_in_comeptition, bool is_back_docking, int dirt_collected, Score *score);
	Simulator();
	virtual ~Simulator();

};

#endif /* SIMULATOR_H_ */
