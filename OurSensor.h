#pragma once
#include "AbstractSensor.h"
#include "OurSensor.h"
#include "House.h"
#include <string>
#include <map>
#include <stdlib.h> 

/*struct Position {
	int row;
	int col;
};*/
class OurSensor : public AbstractSensor
{
	//Position* sensorPos;
	SensorInformation* sensorInfo;
public:
	OurSensor();

	OurSensor(SensorInformation *docking) : sensorInfo(docking){

	}
	~OurSensor();
	OurSensor(const OurSensor&);//copy c'tor
	OurSensor& operator=(const OurSensor&);// '=' operator
	char* ToString(const Direction direct);
	bool directionIsLegal(const Direction direct);//return true if the direction is legal
	virtual SensorInformation sense() const;
	virtual void setInfo(SensorInformation& Info);
	//void setPos(Position& pos);
};


