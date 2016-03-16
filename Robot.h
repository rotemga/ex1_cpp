#pragma once

#ifndef ROBOT_H_
#define ROBOT_H_

#include "House.h"
#include "AbstractAlgorithm.h"
#include "AbstractSensor.h"
#include "OurSensor.h"
#include "Battery.h"
#include "Score.h"
class Robot
{
	House *house;
	AbstractAlgorithm *algo;
	OurSensor *sensor;
	Point* docking;
	Battery* battery;
	Score* score;
	bool canRun;

public:

	Robot(House *house, AbstractAlgorithm *algo, Point* docking, Battery* battery); 
	~Robot();

	void updateBattery(int x, int y, int& batteryState);
	void updateHouse(int x, int y);
	void updatePointByDirection(Point& point, Direction direction);
	void Robot::runRobot();
};

#endif /* ROBOT_H_ */