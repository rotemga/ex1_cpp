#pragma once
#include "AbstractSensor.h"


class OurSensor : public AbstractSensor
{
	SensorInformation* sensorInfo;
public:
	OurSensor();

	OurSensor(SensorInformation *docking) : sensorInfo(docking){

	}
	~OurSensor();
	OurSensor(const OurSensor&);//copy c'tor
	OurSensor& operator=(const OurSensor&);// '=' operator
	virtual SensorInformation sense() const override;
	virtual void setInfo(SensorInformation& Info);
};



