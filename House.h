#pragma once


#ifndef HOUSE_H_
#define HOUSE_H_
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef struct point {
	int x;
	int y;
} Point;
class House {
	string shortDes;
	string longDes;
	int C;
	int R;
	string* matrix;


public:
	House();
	int currentValue(int x, int y) const;
	bool findDockingStation(Point&) const;
	char& findDirtLevel(int x, int y) const;
	virtual ~House();
	void fillHouseData(string& filename);
	void putWallsOnSides();
	int sumDirt() const;
	void getInfo(point& currPoint, SensorInformation& info) const;


	int getC() const {
		return C;
	}

	void setC(int c) {
		C = c;
	}

	string* getMatrix() const {
		return matrix;
	}


	int getR() const {
		return R;
	}

	void setR(int r) {
		R = r;
	}
};

#endif /* HOUSE_H_ */
