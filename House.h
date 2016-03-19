#ifndef HOUSE_H_
#define HOUSE_H_
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "SensorInformation.h"
#include "Point.h"
using namespace std;

typedef enum { DIRTY, CLEAN, WALL, DOCKING } pointState;

//typedef struct point {
//	int x;
//	int y;
//} Point;
class House {
	int R;
	int C;
	string shortDes;
	string longDes;
	string* matrix;


public:
	House(int R, int C, string sho, string lng);
	House();
	House(const House&);//copy c'tor
	House& operator=(const House&);// '=' operator

	void input()
	{
		//		cout << "Reading house from file: simple1.txt into class House" << endl;
		//		ifstream fin("simple1.txt");
		//		getline()
		//		getline(fin, shortDes);
		//		std::getline(fin, longDes);
		//		fin >> R;
		//		fin >> C;
		//		fin.ignore(); //skip newline and go the begining of matrix
		//		matrix = new string[R];
		//		for (int i = 0; i < R; ++i)
		//		{
		//			std::getline(fin, matrix[i]);
		//		}
	}
	void cleanDirtyPoint(const Point& point);
	pointState findPointState(const Point& point) const;
	int currentValue(int x, int y) const;
	bool findDockingStation(Point&) const;
	char& findDirtLevel(int x, int y) const;
	bool checkIfHouseLegal(Point& point);
	virtual ~House();
	void fillHouseData(string& filename);
	void putWallsOnSides();
	int sumDirt() const;
	void getInfo(Point& currPoint, SensorInformation& info) const;
	bool isClean() const;
	void output();

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
