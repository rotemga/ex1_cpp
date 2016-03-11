#include "AbstractSensor.h"


AbstractSensor::AbstractSensor()
{
}


AbstractSensor::~AbstractSensor()
{
}

char* AbstractSensor::ToString(const Direction direct){
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
bool AbstractSensor::directionIsLegal(const Direction direct){

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
