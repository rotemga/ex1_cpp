#include "FuncForMain.h"






int main(int argc, char* argv[]) {
	srand(time(0));

	bool input_house = false, input_config = false;
	string tmp = argv[0];
	string config_fileName;
	vector<string> houses_fileName;
	vector <string> fileName_currDir;
	vector <House*> houses;
	vector <AbstractAlgorithm*> algos;
	map<string, int> config;


	if (argc > 1){ //there are command-line arguments
		string* input = new string[argc - 1];
		for (int i = 1; i < argc; ++i){

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


			}

		}
	}

	else if (!input_house || !input_config){ //at least one of the arguments were missing
		//create vector that containe all files in the current directory
		fs::path full_path_dir(fs::current_path());

		fs::directory_iterator end_iter;

		if (fs::exists(full_path_dir) && fs::is_directory(full_path_dir))
		{
			for (fs::directory_iterator dir_iter(full_path_dir); dir_iter != end_iter; ++dir_iter)
			{
				if (fs::is_regular_file(dir_iter->status()))
				{
					fs::path tmp1 = *dir_iter;
					fileName_currDir.push_back((tmp1).string());
				}
			}
		}


	}
	for (vector<string>::size_type j = 0; j != fileName_currDir.size(); j++){
		if ((hasEnding(fileName_currDir[j], ".ini") && (!input_config))){
			config_fileName = fileName_currDir[j];
		}
		else if ((hasEnding(fileName_currDir[j], ".house") && (!input_house))){
			houses_fileName.push_back(fileName_currDir[j]);
		}
	}

		for (vector<string>::size_type j = 0; j != houses_fileName.size(); j++){
			House *house = new House();
			house->fillHouseData(houses_fileName[j]);
			houses.push_back(house);

		}
		SimpleIniFileParser iniParser(config_fileName);
		config = iniParser.getMap();

		RandomAlgorithm* randomAlgo = new RandomAlgorithm();
		algos.push_back(randomAlgo);

		Simulator sim(houses, algos, config);
		sim.run();

		return 0;

	}





