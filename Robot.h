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
	Point* position;
	Battery* battery;
	Score score;
	bool canRun;

public:

	Robot(House *house, AbstractAlgorithm *algo, Point* docking, Battery* battery);
	~Robot();

	void updateBattery(Point& point, Battery& battery);
	bool updateHouse(const Point& point);
	void updatePositionDirt(Point& point);
	//	void updatePointByDirection(Point& point, Direction direction);
	void runRobot();
	bool isHouseClean() const;
	bool areWeInDocking() const;
	int DirtCollected();
	void printHouse();

	bool isCanRun() const {
		return canRun;
	}

	void setCanRun(bool canRun) {
		this->canRun = canRun;
	}

	const Score& getScore() const {
		return score;
	}

	void setScore(const Score& score) {
		this->score = score;
	}
	bool crashedToWall(const Point& point) {
		return house->findPointState(point) == WALL;
	}
};
#endif ROBOT_H_