#pragma once

#ifndef OURSENSOR_H_
#define OURSENSOR_H_

#include "AbstractSensor.h"
#include "House.h"


class OurSensor : public AbstractSensor
{
	SensorInformation* sensorInfo;
	House *thisHouse;
	Point *currPoint;
public:

	/*OurSensor(SensorInformation *docking) : sensorInfo(docking){

	}*/
	OurSensor(House *house, Point* point);
	~OurSensor();
	OurSensor(const OurSensor&);//copy c'tor
	OurSensor& operator=(const OurSensor&);// '=' operator
	virtual SensorInformation sense() const override;
	virtual void setInfo(SensorInformation& Info);
	SensorInformation OurSensor::getInfoFromPoint();
};


#endif /* OURSENSOR_H_ */
