using namespace std;

#pragma once
#include <string>


enum class Direction { East, West, South, North, Stay };
struct SensorInformation {
	int dirtLevel;
	bool isWall[4];//index 0 is east, 1 is west, 2 is south, 3 is north
};
class AbstractSensor {

public:
	AbstractSensor();
	~AbstractSensor();
	// returns the sensor's information of the current location of the robot
	virtual SensorInformation sense() const = 0;
};
