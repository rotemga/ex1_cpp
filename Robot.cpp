#include "Robot.h"


Robot::Robot(House *house, AbstractAlgorithm *algo, Point* docking, Battery* battery) : house(house), algo(algo), docking(docking), battery(battery)
{
	sensor = new OurSensor(house, docking);
	score = new Score();
	canRun = true;
}


Robot::~Robot()
{
	//sensor = delete;
}


void Robot::runRobot(){
	while (canRun){

	}
}

void Robot::updateHouse(int xlocation, int ylocation) {
	if (house->currentValue(xlocation, ylocation) != '0')
		house->getMatrix()[xlocation][ylocation]--;
}
void Robot::updateBattery(int x, int y, int& batteryState) {
	/*if (house->getMatrix()[x][y] != 'D')
		batteryState -= config.at("BatteryConsumptionRate");
	else {
		int newLevel = batteryState + config.at("BatteryRachargeRate");
		batteryState =
			(newLevel > config.at("BatteryCapacity")) ?
			config.at("BatteryCapacity") : newLevel;
	}*/
}
void Robot::updatePointByDirection(Point& point, Direction direction) {
	switch (direction) {
	case Direction::East:
		point.x++;
		break;
	case Direction::West:
		point.x--;
		break;
	case Direction::North:
		point.y++;
		break;
	case Direction::South:
		point.y--;
		break;
	case Direction::Stay:
		break;
	default:;
	}
}