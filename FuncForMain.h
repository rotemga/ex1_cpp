#include <iostream>
#include <fstream>
#include <vector>
#include "House.h"
#include <string>
#include "Simulator.h"
#include "RandomAlgorithm.h"
#include "SimpleIniFileParser.h"

//#include <boost/optional.hpp>
#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations

using namespace std;
namespace fs = boost::filesystem;

void createSimple1();
bool hasEnding(string const &fullString, string const &ending);
bool IsPrefix(string const& fullstring, string const& prefix);
void writeConfigFile(const string &iniPath);