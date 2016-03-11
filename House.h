#pragma once


#ifndef HOUSE_H_
#define HOUSE_H_

#include <string>
#include <iostream>

using namespace std;
class House {
	string shortDes;
	string longDes;
	int C;
	int R;
	string* matrix;


public:
	House();
	virtual ~House();
	void fillHouseData(string& filename);
};

#endif /* HOUSE_H_ */
