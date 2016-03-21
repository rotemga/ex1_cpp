#include "FuncForMain.h"

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

}

bool hasEnding(string const &fullString, string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	}
	else {
		return false;
	}
}

bool IsPrefix(string const& fullstring, string const& prefix)
{
	return equal(
		fullstring.begin(),
		fullstring.begin() + min(fullstring.size(), prefix.size()),
		prefix.begin());
}
