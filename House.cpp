#include "House.h"
#include <fstream>
#include <iostream>
#include "SensorInformation.h"
using namespace std;
enum { rows = 4, cols = 6 }; // this is an example for an hard coded house...
char house1[rows][cols + 1] = {
	"WWWWWW",
	"WD263W",
	"W1154W",
	"WWWWWW"
};

House::House(int R, int C, string sho, string lng) :

R(R), C(C), shortDes(sho), longDes(lng){
	matrix = new string[R];
	for (int i = 0; i<R; i++)
		matrix[i] = house1[i];
	// TODO Auto-generated constructor stub

}
House::House() {
}

House::~House() {
	delete[] matrix;
}

House::House(const House& house2){//copy c'tor
	*this = house2;
}

House& House::operator=(const House& house2){// '=' operator
	int R = house2.getR();
	int C = house2.getC();
	string* newMatrix = new string[R];
	string* tmp = house2.getMatrix();
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			newMatrix[i][j] = tmp[i][j];
		}
	}
	this->matrix = newMatrix;
	this->C = C; this->R = R;
	this->longDes = house2.longDes;
	this->shortDes = house2.shortDes;
	return *this;
}

int House::currentValue(int x, int y) const {
	return matrix[x][y];
}

bool House::isClean() const {
	for (int i = 0; i<R; i++)
		for (int j = 0; j<C; j++)
			if (matrix[i][j] >= '1' && matrix[i][j] <= '9')
				return false;
	return true;
}

bool House::findDockingStation(Point& point) const {

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (matrix[i][j] == 'D') {
				point.setPoint(i, j);
				return true;
			}
	return false;
}

char& House::findDirtLevel(int x, int y) const {
	return matrix[x][y];
}
//if the house is llegal return true, else false.
bool House::checkIfHouseLegal(Point& point){
	if (!findDockingStation(point)){
		cout << "Illegal house: there is no docking station!" << endl;
		return false;
	}
	putWallsOnSides();
	if (!findDockingStation(point)){
		cout << "Illegal house: the docking station overrided by external wall" << endl;
		return false;
	}
	SensorInformation info;
	getInfo(point, info);
	if ((info.isWall[0]) && (info.isWall[1]) && (info.isWall[2]) && (info.isWall[3])){
		cout << "Illegal house: the docking station surrounded by walls, the robot can't get out" << endl;
		return false;

	}
	return true;
}

void House::fillHouseData(string& filename) {

	ifstream fin(filename);
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


void House::putWallsOnSides() {
	for (int i = 0; i < C; ++i) {
		matrix[0][i] = 'W';
		matrix[R - 1][i] = 'W';
	}
	for (int i = 0; i < R; ++i) {
		matrix[i][0] = 'W';
		matrix[i][C - 1] = 'W';
	}
}

int House::sumDirt() const {
	int sum = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (matrix[i][j] >= '1' && matrix[i][j] <= '9')
				sum += (int)matrix[i][j] - '0';
	return sum;
}
void House::cleanDirtyPoint(const Point& point) {
	matrix[point.getX()][point.getY()]--;
}
pointState House::findPointState(const Point& point) const {
	int x = point.getX();
	int y = point.getY();
	char ch = matrix[x][y];
	switch (ch) {
	case 'D':
		return DOCKING;
	case ' ':
		return CLEAN;
	case '0':
		return CLEAN;
	case 'W':
		return WALL;
	default:
		return DIRTY;
	}
}

//index 0 is east, 1 is west, 2 is south, 3 is north
void House::getInfo(Point& currPoint, SensorInformation& info) const {
	int x = currPoint.getX();
	int y = currPoint.getY();
	if (matrix[x][y] == 'D' || matrix[x][y] == 'W' || matrix[x][y] == ' '){
		info.dirtLevel = 0;
	}
	else{
		info.dirtLevel = matrix[x][y] - '0';
	}
	info.isWall[0] = (y == getR() - 1) ? true : matrix[x][y + 1] == 'W';
	info.isWall[1] = (y == 0) ? true : matrix[x][y - 1] == 'W';
	info.isWall[2] = (x == 0) ? true : matrix[x + 1][y] == 'W';
	info.isWall[3] = (x == getC() - 1) ? true : matrix[x - 1][y] == 'W';
}

void House::output()
{
	cout << "Printing house from instance into standard output" << endl;
	//	cout << "House name: " << shortDes << endl;
	//	cout << "House description: " << longDes << endl;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
