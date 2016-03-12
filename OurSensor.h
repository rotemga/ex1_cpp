#pragma once
#include "AbstractSensor.h"
class OurSensor : public AbstractSensor
{
	Position* sensorPos;
	SensorInformation* sensorInfo;
public:
	OurSensor();
	~OurSensor();
	OurSensor(const OurSensor&);//copy c'tor
	OurSensor& operator=(const OurSensor&);// '=' operator
	OurSensor& operator=(const AbstractSensor&);// '=' operator

	virtual SensorInformation sense() const;
	virtual SensorInformation setInfo(SensorInformation& Info);
	void OurSensor::setPos(Position& pos);
};


