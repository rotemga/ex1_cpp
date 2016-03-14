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
using namespace std;

class Simulator {
	House* house;
	AbstractAlgorithm* algorithm;
	map<string, int> config;
	vector<Score> results;
	void updateBattery(int x, int y, int& batteryState);
	void updateHouse(int x, int y);
	void updatePointByDirection(Point& point, Direction direction);
public:
	void getInfo(int x, int y, SensorInformation& info) const;
	void run();
	void fillHouses(const string& location);
	Simulator();
	virtual ~Simulator();
};

#endif /* SIMULATOR_H_ */
