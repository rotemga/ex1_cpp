

#include "House.h"
#include <fstream>
#include <iostream>
using namespace std;
House::House() : C(0), R(0), matrix(NULL){
	// TODO Auto-generated constructor stub

}

House::~House() {
	delete[] matrix;
}

void House::fillHouseData(string& filename) {
	ifstream fin("simple1.txt");
	getline(fin, shortDes);
	std::getline(fin, longDes);
	fin >> R;
	fin >> C;
	fin.ignore(); //skip newline and go the begining of matrix
	matrix = new string[R];
	for (int i = 0; i < R; ++i)
	{
		std::getline(fin, matrix[i]);
	}
}
