#include "RandomAlgorithm.h"

RandomAlgorithm::RandomAlgorithm()
{
}


RandomAlgorithm::~RandomAlgorithm()
{
}

void RandomAlgorithm::setSensor(const AbstractSensor& sensor){
	thisSensor.setInfo(&sensor.sense());

}

void RandomAlgorithm::setConfiguration(map<string, int> config){
	thisConfig = config;//********to fix, assignment of strings not good!!!

}
Direction RandomAlgorithm::step(){
	Direction direct;
	while (1){
		int randIndex = rand() % 5; // randIndex in the range 0 to 4
		direct = static_cast<Direction>(randIndex);
		if (thisSensor.directionIsLegal(direct))
			break;
	}
	return direct;
}


void RandomAlgorithm::aboutToFinish(int stepsTillFinishing){

}