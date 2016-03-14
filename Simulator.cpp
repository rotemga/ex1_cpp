


#include "Simulator.h"

Simulator::Simulator() :
config({ { "MaxSteps", 1200 }, { "MaxStepsAfterWinner", 200 }, {
	"BatteryCapacity", 400 }, { "BatterConsumptionRate", 1 }, {
		"BatteryRachargeRate", 20 } }) {

}

Simulator::~Simulator() {
}

void Simulator::updateHouse(int xlocation, int ylocation) {
	if (house->currentValue(xlocation, ylocation) != '0')
		house->getMatrix()[xlocation][ylocation]--;
}
void Simulator::updateBattery(int x, int y, int& batteryState) {
	if (house->getMatrix()[x][y] != 'D')
		batteryState -= config.at("BatteryConsumptionRate");
	else {
		int newLevel = batteryState + config.at("BatteryRachargeRate");
		batteryState =
			(newLevel > config.at("BatteryCapacity")) ?
			config.at("BatteryCapacity") : newLevel;
	}
}
void Simulator::updatePointByDirection(Point& point, Direction direction) {
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

//index 0 is east, 1 is west, 2 is south, 3 is north
void Simulator::getInfo(int x, int y, SensorInformation& info) const {
	info.dirtLevel = house->getMatrix()[x][y];
	info.isWall[0] =
		(y == house->getR() - 1) ?
		true : house->getMatrix()[x][y + 1] == 'W';
	info.isWall[1] = (y == 0) ? true : house->getMatrix()[x][y - 1] == 'W';
	info.isWall[2] = (x == 0) ? true : house->getMatrix()[x - 1][y] == 'W';
	info.isWall[3] =
		(x == house->getC() - 1) ?
		true : house->getMatrix()[x + 1][y] == 'W';
}

void Simulator::run() {
	int time = 0;
	algorithm->setConfiguration(config);
	Point point;
	if (!house->findDockingStation(point)){
		cout << "there is no docking station!" << endl;
		exit(1);
	}
	house->putWallsOnSides();
	if (!house->findDockingStation(point)){
		cout << "there is no docking station: it overrided" << endl;
		exit(1);
	}
	SensorInformation dockInfo;
	getInfo(point.x, point.y, dockInfo);
	OurSensor sensor(&dockInfo);
	int batteryState = config.at("BatteryCapacity");
	while (time < config.at("MaxSteps")) {
		updateHouse(point.x, point.y);
		updateBattery(point.x, point.y, batteryState);
		Direction direction = algorithm->step();
		updatePointByDirection(point, direction);
		time++;
		getInfo(point.x, point.y, dockInfo);
		sensor.setInfo(dockInfo);

	}
}

