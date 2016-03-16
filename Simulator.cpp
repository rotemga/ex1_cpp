




#include "Simulator.h"

Simulator::Simulator() :
config({ { "MaxSteps", 1200 }, { "MaxStepsAfterWinner", 200 }, {
	"BatteryCapacity", 400 }, { "BatterConsumptionRate", 1 }, {
		"BatteryRachargeRate", 20 } }) {

}

Simulator::~Simulator() {
}

void Simulator::setInputHouses(vector<House*> input_houses){
	houses = input_houses;
}
void Simulator::setInputConfig(map<string, int> input_config){
	config = input_config;
}
void Simulator::setInputAlgo(vector <AbstractAlgorithm*> input_algorithms){
	algorithms = input_algorithms;
}

/*
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
*/


void Simulator::run() {
	/*for (vector<AbstractAlgorithm*>::iterator it = algorithms.begin(); it != algorithms.end(); ++it) {
		it->setConfiguration(config);
	}*/
	vector <Robot*> robots;
	Robot* robot;
	Battery* battery = new Battery(config.at("BatteryCapacity"), config.at("BatterConsumptionRate"), config.at("BatteryRachargeRate"));
	int Steps = config.at("MaxSteps");
	
	for (vector<AbstractAlgorithm*>::size_type i = 0; i != algorithms.size(); i++) {
		algorithms[i]->setConfiguration(config);
	}


	int time = 0;
	Point point;
	for (vector<House*>::size_type i = 0; i != houses.size(); i++) {
		if (!(houses[i]->findDockingStation(point))){
			cout << "Illegal house: there is no docking station!" << endl;
			continue;
		}
		houses[i]->putWallsOnSides();
		if (!houses[i]->findDockingStation(point)){
			cout << "Illegal house: the docking station overrided by external wall" << endl;
			continue;
		}
		for (vector<AbstractAlgorithm*>::size_type j = 0; j != algorithms.size(); j++){
			robot = new Robot(houses[i], algorithms[j], &point, battery);
			robots.push_back(robot);
		}
		while (Steps > 0){
			for (vector<Robot*>::size_type k = 0; k != algorithms.size(); k++){
				robot[k].runRobot();
				//if robotWin
				//Steps = config.at("MaxStepsAfterWinner");
			}
			Steps--;
		}

	}


}


