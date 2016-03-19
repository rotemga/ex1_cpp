#include <iostream>
#include <fstream>
#include <vector>
#include "OurSensor.h"
#include "House.h"
#include <string>
#include "Simulator.h"
#include "RandomAlgorithm.h"
#include "SimpleIniFileParser.h"

#include <boost/optional.hpp>
#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations


using namespace std;
namespace fs = boost::filesystem;

void writeConfigFile(const string &iniPath)
{
	ofstream fout(iniPath.c_str());
	fout << "BatteryConsumptionRate  =    1" << endl;
	fout << "MaxSteps   = 1200" << endl;
	fout << "MaxStepsAfterWinner=200" << endl;
	fout << "BatteryCapacity=400" << endl;
	fout << "BatteryRachargeRate=20" << endl;
	fout.close();

	ifstream fin(iniPath.c_str());
	string line;
	std::cout << "Original config ini file: " << endl;
	while (getline(fin, line))
	{
		std::cout << line << endl;
	}
}

void createSimple1()
{
	std::cout << "Creating file: simple1.txt" << endl;
	ofstream fout("simple1.txt");
	fout << "Simple1" << endl;
	fout << "2 Bedrooms + Kitchen Isle" << endl;
	fout << 8 << endl;
	fout << 10 << endl;
	fout << "WWWWWWWWWW" << endl;
	fout << "W22  DW59W" << endl;
	fout << "W  W 1119W" << endl;
	fout << "W WWW3WW W" << endl;
	fout << "W6   3W  W" << endl;
	fout << "W78W  W  W" << endl;
	fout << "W99W  W  W" << endl;
	fout << "WWWWWWWWWW" << endl;
	fout.close();
}

bool hasEnding(string const &fullString, string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	}
	else {
		return false;
	}
}

bool IsPrefix(string const& fullstring,string const& prefix)
{
	return equal(
		fullstring.begin(),
		fullstring.begin() + min(fullstring.size(), prefix.size()),
		prefix.begin());
}






	int main(int argc, char* argv[]) {


		bool input_house = false, input_config = false;
		string tmp = argv[0];
		string config_fileName;
		vector<string> houses_fileName;
		vector <string> fileName_currDir;
		vector <House*> houses;
		vector <AbstractAlgorithm*> algos;
		map<string, int> config;


		if (argc > 1){
			string* input = new string[argc - 1];
			for (size_t i = 1; i < argc; ++i){
				if (IsPrefix(argv[i], "–config")){
					argv[i] += 7;
					input_config = true;
				}
				else if (IsPrefix(argv[i], "–house_path")){
					argv[i] += 11;
					input_house = true;
				}
				if (hasEnding(argv[i], ".ini")){
					fs::path p(argv[i]);
					fs::path full_p = fs::complete(p); // complete == absolute
					config_fileName = full_p.string();
					input_config = true;


				}
				else if (hasEnding(argv[i], ".house")){
					fs::path p(argv[i]);
					fs::path full_p = fs::complete(p); // complete == absolute
					houses_fileName.push_back(full_p.string());
					input_house = true;

					/*ifstream in_stream;
					string line;

					in_stream.open(full_p.string());

					while (!in_stream.eof())
					{
						in_stream >> line;
						cout << line << endl;
					}
					in_stream.close();*/
				}

			}
		}

		else{ 
			fs::path full_path_dir(fs::current_path());
			//cout << "Current path is : " << full_path_dir << endl;

			fs::directory_iterator end_iter;
			//typedef std::multimap<std::time_t, fs::path> result_set_t;
			//result_set_t result_set;

			if (fs::exists(full_path_dir) && fs::is_directory(full_path_dir))
			{
				for (fs::directory_iterator dir_iter(full_path_dir); dir_iter != end_iter; ++dir_iter)
				{
					if (fs::is_regular_file(dir_iter->status()))
					{
						fs::path tmp1 = *dir_iter;
						fileName_currDir.push_back((tmp1).string());
						//result_set.insert(result_set_t::value_type(fs::last_write_time(dir_iter->path()), *dir_iter));
					}
				}
			} 


		}
		for (vector<string>::size_type j = 0; j != fileName_currDir.size(); j++){
			if (hasEnding(fileName_currDir[j], ".ini")){
				config_fileName = fileName_currDir[j];
			}
			else if (hasEnding(fileName_currDir[j], ".house")){
				houses_fileName.push_back(fileName_currDir[j]);
			}
		}

		for (vector<string>::size_type j = 0; j != houses_fileName.size(); j++){
			House *house = new House();
			house->fillHouseData(houses_fileName[j]);
			house->output();
			houses.push_back(house);

		}
		writeConfigFile(config_fileName);
		SimpleIniFileParser iniParser(config_fileName);
		std::cout << endl << endl << "Parameters read:" << endl;
		std::cout << iniParser.toString() << endl;
		config = iniParser.getMap();

		RandomAlgorithm* randomAlgo = new RandomAlgorithm();
		algos.push_back(randomAlgo);

		Simulator sim(houses, algos, config);
		sim.run();

		return 0;

	}





	/*fs::path p(argv[1]);
	fs::path full_p = fs::complete(p); // complete == absolute
	cout << "The absolute path: " << full_p << endl;
	int i = 0;


	vector <House*> house1;
	vector<AbstractAlgorithm*> algos;
	House* h = new House();
	createSimple1();
	string name = "simple1.txt";
	h->fillHouseData(name);
	h->output();
	house1.push_back(h);

	RandomAlgorithm* algo = new RandomAlgorithm();
	algos.push_back(algo);
	/*Direction direct;
	for (size_t i = 0; i < 10; i++){
	direct = algo->step();
	cout << algo->ToString(direct) << endl;

	}
	cout << endl;
	Simulator sim(house1, algos);
	sim.run();*/
