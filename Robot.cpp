#include "Robot.h"

Robot::Robot(House *house, AbstractAlgorithm *algo, Point* docking,
	Battery* battery) :
	house(house), algo(algo), position(docking), battery(battery) {
	sensor = new OurSensor(house, docking);
	score = *new Score();
	score.setSumDirtInHouse(house->sumDirt());
	canRun = true;
}

Robot::~Robot() {
	//sensor = delete;
}

void Robot::runRobot() {
	if (canRun) {
		updateHouse(*position);
		updateBattery(*position, *battery);
		Direction direction = algo->step(); //should check if direction is legal
		position->move(direction);
		sensor->getInfoFromPoint(house, position);
		score.setNumSteps(score.getNumSteps() + 1);
	}
}

void Robot::updateHouse(const Point& point) {
	switch (house->findPointState(point)) {
	case DIRTY:
		house->cleanDirtyPoint(point);
		break;
	deafult:;
	}
}
void Robot::updateBattery(Point& point, Battery& battery) {
	switch (house->findPointState(point)) {
	case DOCKING:
		battery.recharge();
		break;
	default:
		battery.reduce();
	}
}

bool Robot::isHouseClean() const {
	return house->isClean();
}
bool Robot::areWeInDocking() const {
	return house->findPointState(*position) == DOCKING;
}

int Robot::DirtCollected(){
	return (score.getSumDirtInHouse() - house->sumDirt());
}

//void Robot::updatePointByDirection(Point& point, Direction direction) {
//	switch (direction) {
//	case Direction::East:
//		point.x++;
//		break;
//	case Direction::West:
//		point.x--;
//		break;
//	case Direction::North:
//		point.y++;
//		break;
//	case Direction::South:
//		point.y--;
//		break;
//	case Direction::Stay:
//		break;
//	default:;
//	}
//}

