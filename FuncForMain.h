#ifndef FUNCFORMAIN_H_
#define FUNCFORMAIN_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "House.h"
#include <string>
#include "Simulator.h"
#include "RandomAlgorithm.h"
#include "SimpleIniFileParser.h"


#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

using namespace std;
namespace fs = boost::filesystem;

void createSimple1();
bool hasEnding(string const &fullString, string const &ending);
bool IsPrefix(string const& fullstring, string const& prefix);
void writeConfigFile(const string &iniPath);

#endif /* FUNCFORMAIN_H_ */