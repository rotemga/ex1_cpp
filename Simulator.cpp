#include "Simulator.h"

Simulator::Simulator(vector <House*> houses1, vector <AbstractAlgorithm*> algos1) :
config({ { "MaxSteps", 1200 }, { "MaxStepsAfterWinner", 200 }, {
	"BatteryCapacity", 400 }, { "BatterConsumptionRate", 1 }, {
		"BatteryRachargeRate", 20 } }) {
	houses = houses1;
	algorithms = algos1;
	//houses.push_back(house);
	//algorithms.push_back(algo);


}
Simulator::Simulator(vector <House*> houses1, vector <AbstractAlgorithm*> algos1, map<string, int> config1) : houses(houses1), algorithms(algos1), config(config1){

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

void Simulator::createScore(int num_steps, int pos_in_comeptition, bool is_back_docking, int dirt_collected, Score *score){
	score->setNumSteps(num_steps);
	score->setIsBackInDocking(is_back_docking);
	score->setDirtCollected(dirt_collected);
	score->setPosition(pos_in_comeptition);
}



bool Simulator::hasEnding(string const &fullString, string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	}
	else {
		return false;
	}
}


void Simulator::run() {
	/*for (vector<AbstractAlgorithm*>::iterator it = algorithms.begin(); it != algorithms.end(); ++it) {
	it->setConfiguration(config);
	}*/
	vector <Robot*> robots;
	Score score;
	int pos_in_competition = 1, num_steps = 0, Steps = config.at("MaxSteps");





	for (vector<AbstractAlgorithm*>::size_type i = 0; i != algorithms.size(); i++) {
		algorithms[i]->setConfiguration(config);
	}


	int time = 0;
	Point* point = new Point(0, 0);
	for (vector<House*>::size_type i = 0; i != houses.size(); i++) {

		if (!(houses[i]->checkIfHouseLegal(*point)))
			continue;
		for (vector<AbstractAlgorithm*>::size_type j = 0; j != algorithms.size(); j++){
			Battery* battery = new Battery(config.at("BatteryCapacity"), config.at("BatteryConsumptionRate"), config.at("BatteryRachargeRate"));
			Robot* robot = new Robot(houses[i], algorithms[j], point, battery);
			robots.push_back(robot);
		}
		houses[i]->output();
		while (Steps > 0){
			for (vector<Robot*>::size_type k = 0; k != algorithms.size(); k++){
				if (!robots[k]->isCanRun())
					continue;
				robots[k]->runRobot();
				//robots[k]->printHouse();
				if ((robots[k]->isHouseClean()) && (robots[k]->areWeInDocking())){//robot win
					robots[0]->printHouse();
					Steps = config.at("MaxStepsAfterWinner") + 1;
					robots[k]->setCanRun(false);
					createScore(num_steps, pos_in_competition, true, robots[k]->DirtCollected(), &score);
					robots[k]->setScore(score);
					if (pos_in_competition < 4)
						pos_in_competition++;
				}
				//robots[k]->printHouse();

			}
			num_steps++;
			Steps--;
		}
		robots[0]->printHouse();
		Score s = robots[0]->getScore();
		cout << s.calcResult();


		for (vector<Robot*>::size_type k = 0; k != algorithms.size(); k++){
			if (robots[k]->isCanRun()){
				pos_in_competition = 10;
				createScore(num_steps, pos_in_competition, robots[k]->areWeInDocking(), robots[k]->DirtCollected(), &score);
				robots[k]->setScore(score);
				cout << score.calcResult();



			}
		}

	}


}