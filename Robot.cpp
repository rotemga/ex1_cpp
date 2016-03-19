#include "Robot.h"

Robot::Robot(House *house, AbstractAlgorithm *algo, Point* docking,
	Battery* battery) :
	house(house), algo(algo), position(docking), battery(battery) {
	sensor = new OurSensor(house, docking);
	score = *new Score();
	score.setSumDirtInHouse(house->sumDirt());
	canRun = true;
	algo->setSensor(*sensor);
}

Robot::~Robot() {
	//sensor = delete;
}

void Robot::runRobot() {
	if (canRun) {
		position->print();
		if (updateHouse(*position))
			score.setDirtCollected(score.getDirtCollected() + 1);
		updateBattery(*position, *battery);
		if (battery->isEmpry()) {
			canRun = false;
			score.setPosition(10);
			return;
		}
		algo->setSensor(*sensor);

		Direction direction = algo->step(); //should check if direction is legal
		position->move(direction);
		if (crashedToWall(*position)) {
			canRun = false;
			return;
		}
		sensor->getInfoFromPoint(house, position);
		score.setNumSteps(score.getNumSteps() + 1);
	}
}

bool Robot::updateHouse(const Point& point) {
	if (house->findPointState(point) == DIRTY) {
		house->cleanDirtyPoint(point);
		return true;
	}
	return false;
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

void Robot::updatePositionDirt(Point& point){
	int dirt = house->currentValue(point.getX(), point.getY());
	if (dirt > 0){
		house->cleanDirtyPoint(point);
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

void Robot::printHouse(){
	string* matrix = house->getMatrix();
	cout << "Printing house from instance into standard output" << endl;
	for (int i = 0; i < house->getR(); ++i)
	{
		for (int j = 0; j < house->getC(); ++j)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
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