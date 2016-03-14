#include "OurSensor.h"


OurSensor::OurSensor()
{

}


OurSensor::~OurSensor()
{
}


OurSensor::OurSensor(const OurSensor& sensor2) {//copy c'tor
	*this = sensor2;
}

OurSensor& OurSensor::operator=(const OurSensor& sensor2) {// '=' operator
	if (this != &sensor2) {
		setInfo(*sensor2.sensorInfo);
	}
	return *this;
}




void OurSensor::setInfo(SensorInformation& Info){//update the sesnor with new information
	sensorInfo->dirtLevel = Info.dirtLevel;
	for (size_t i = 0; i < 4; ++i) {
		sensorInfo->isWall[i] = Info.isWall[i];
	}
}



SensorInformation OurSensor::sense() const{
	return *this->sensorInfo;
}

/*
void OurSensor::setPos(Position& pos){
	sensorPos->col = pos.col;
	sensorPos->row = pos.row;
}*/

char* OurSensor::ToString(const Direction direct){
	switch (direct)
	{
	case Direction::East:		return "East";
	case Direction::West:		return "West";
	case Direction::South:		return "South";
	case Direction::North:		return "North";
	case Direction::Stay:		return "Stay";
	default:					return "Unknown";
	}
}

//return true if the direction is legal.
//i.e. the direction is not lead to wall, or if the direction is stay, there is dust in the current location.
//index 0 is east, 1 is west, 2 is south, 3 is north
bool OurSensor::directionIsLegal(const Direction direct){

	switch (direct)
	{
	case Direction::East:		return !(sensorInfo->isWall[0]);
	case Direction::West:		return !(sensorInfo->isWall[1]);
	case Direction::South:		return !(sensorInfo->isWall[2]);
	case Direction::North:		return !(sensorInfo->isWall[3]);
	case Direction::Stay:		return (sensorInfo->dirtLevel > 0);
	default:					return false;
	}

}
