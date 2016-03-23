#include "Simulator.h"



Simulator::Simulator(vector <House*> houses1, vector <AbstractAlgorithm*> algos1) :
config({ { "MaxSteps", 1200 }, { "MaxStepsAfterWinner", 200 }, {
	"BatteryCapacity", 400 }, { "BatterConsumptionRate", 1 }, {
		"BatteryRachargeRate", 20 } }) {
	houses = houses1;
	algorithms = algos1;



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



void Simulator::createScore(int winner_num_stepsint, int num_steps, int pos_in_comeptition, bool is_back_docking, int dirt_collected, Score *score){
	score->setWinnerNumSteps(winner_num_stepsint);
	score->setNumSteps(num_steps);
	score->setIsBackInDocking(is_back_docking);
	score->setDirtCollected(dirt_collected);
	score->setPosition(pos_in_comeptition);
}





bool Simulator::allRobotsFinished(vector <Robot*> robots){
	int cnt = 0;
	for (vector<Robot*>::size_type k = 0; k != robots.size(); k++){
		if (!(robots[k]->isCanRun()))
			cnt++;
	}
	if (cnt == robots.size())
		return true;
	return false;
}

bool Simulator::robotWin(Robot* robot){
	return ((robot->isHouseClean()) && (robot->areWeInDocking()));
}


void Simulator::run() {

	vector <Robot*> robots;
	Score score;
	//int pos_in_competition = 1, num_steps = 0, Steps;


	for (vector<AbstractAlgorithm*>::size_type i = 0; i != algorithms.size(); i++) {
		algorithms[i]->setConfiguration(config);
	}


	int time = 0;
	Point* point = new Point(-1, -1);
	for (vector<House*>::size_type i = 0; i != houses.size(); i++) {
		int Steps = config.at("MaxSteps"), pos_in_competition = 1, actual_position_in_copmetition = 0;
		int simulation_steps = 0, winner_num_steps = 0, num_of_wins_this_iter = 0;
		if (!(houses[i]->checkIfHouseLegal(*point)))
			continue;
		for (vector<AbstractAlgorithm*>::size_type j = 0; j != algorithms.size(); j++){
			// robot for all pair <house,algorithm>
			Battery* battery = new Battery(config.at("BatteryCapacity"), config.at("BatteryConsumptionRate"), config.at("BatteryRachargeRate"));
			Robot* robot = new Robot(houses[i], algorithms[j], point, battery);
			robots.push_back(robot);
		}
		houses[i]->output();
		while (Steps > 0){
			for (vector<Robot*>::size_type k = 0; k != robots.size(); k++){
				if (!robots[k]->isCanRun())
					continue;
				robots[k]->runRobot();
				if (robotWin(robots[k])){//robot win
					Steps = config.at("MaxStepsAfterWinner") + 1;
					if (winner_num_steps == 0){
						winner_num_steps = simulation_steps;
					}
					num_of_wins_this_iter++;
					pos_in_competition = min(4, actual_position_in_copmetition);
					createScore(winner_num_steps, simulation_steps, pos_in_competition, true, robots[k]->DirtCollected(), &score);

				}

			}
			if (allRobotsFinished(robots))
				break;
			simulation_steps++;
			Steps--;
			if (num_of_wins_this_iter > 0){
				actual_position_in_copmetition += num_of_wins_this_iter;
			}
		}

		if (winner_num_steps == 0){
			winner_num_steps = simulation_steps;
		}



		for (vector<Robot*>::size_type k = 0; k != robots.size(); k++){

			//the robot crashed a wall or the battery is empty 
			//or:
			//the robot  didn't finish cleaning the house and it can run
			if ((robots[k]->isCanRun() || robots[k]->isBrokedDown())){
				createScore(winner_num_steps, simulation_steps, 10, robots[k]->areWeInDocking(), robots[k]->DirtCollected(), &score);
				robots[k]->setScore(score);
				cout <<"the robot didnt win:"  <<score.calcResult() << endl;


			}
			if (robots[k]->isBrokedDown())
				cout << "battery empty" << endl;
		}


	}
	for (vector<Robot*>::size_type k = 0; k != robots.size(); k++){
		robots[k]->printHouse();
		Score s = robots[k]->getScore();
		cout << s.calcResult() << endl;
	}


}