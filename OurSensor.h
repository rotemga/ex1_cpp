#ifndef OURSENSOR_H_
#define OURSENSOR_H_

#include "AbstractSensor.h"
#include "House.h"


class OurSensor : public AbstractSensor
{
	SensorInformation sensorInfo;
	House *thisHouse;
	Point *currPoint;
public:

	OurSensor(House *house, Point* point);
	OurSensor();
	~OurSensor();
	OurSensor(const OurSensor&);//copy c'tor
	OurSensor& operator=(const OurSensor&);// '=' operator
	virtual SensorInformation sense() const override;
	virtual void setInfo(const SensorInformation& Info);
	void getInfoFromPoint();
	void getInfoFromPoint(House* house, Point* point);
};


#endif /* OURSENSOR_H_ */