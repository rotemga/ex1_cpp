#include "House.h"
#include <fstream>
#include <iostream>
#include "SensorInformation.h"
using namespace std;
House::House() :
C(0), R(0), matrix(NULL) {
	// TODO Auto-generated constructor stub

}

House::~House() {
	delete[] matrix;
}

int House::currentValue(int x, int y) const {
	return matrix[x][y];
}

bool House::findDockingStation(Point& point) const {

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (matrix[i][j] == 'D') {
				point.x = i;
				point.y = j;
				return true;
			}
	return false;
}

char& House::findDirtLevel(int x, int y) const {
	return matrix[x][y];
}


void House::fillHouseData(string& filename) {
	ifstream fin("simple1.txt");
	getline(fin, shortDes);
	std::getline(fin, longDes);
	fin >> R;
	fin >> C;
	fin.ignore(); //skip newline and go the begining of matrix
	matrix = new string[R];
	for (int i = 0; i < R; ++i) {
		std::getline(fin, matrix[i]);
	}
}


void House::putWallsOnSides(){
	for (int i = 0; i < R; ++i){
		matrix[0][i] = 'W';
		matrix[R - 1][i] = 'W';
	}
	for (int i = 0; i < C; ++i){
		matrix[i][0] = 'W';
		matrix[i][C-1] = 'W';
	}
}

int House::sumDirt() const {
	int sum = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (matrix[i][j] >= '1' && matrix[i][j] <= '9')
				sum += (int)matrix[i][j];
	return sum;
}

//index 0 is east, 1 is west, 2 is south, 3 is north
void House::getInfo(Point& currPoint, SensorInformation& info) const {
	int x = currPoint.x;
	int y = currPoint.y;
	info.dirtLevel = getMatrix()[x][y];
	info.isWall[0] = 
		(y == getR() - 1) ? 
		true : getMatrix()[x][y + 1] == 'W';
	info.isWall[1] = (y == 0) ? true : getMatrix()[x][y - 1] == 'W';
	info.isWall[2] = (x == 0) ? true : getMatrix()[x - 1][y] == 'W';
	info.isWall[3] =
		(x == getC() - 1) ?
		true : getMatrix()[x + 1][y] == 'W';
}
