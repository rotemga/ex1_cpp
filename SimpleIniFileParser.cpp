#include "SimpleIniFileParser.h"





SimpleIniFileParser::SimpleIniFileParser() { }
SimpleIniFileParser:: SimpleIniFileParser(const string& iniPath)
{
	this->loadFromFile(iniPath);
}

void SimpleIniFileParser::loadFromFile(const string& iniPath)
	{
		this->parameters.clear();
		ifstream fin(iniPath.c_str());
		string line;
		while (getline(fin, line))
		{
			this->processLine(line);
		}
	}

string SimpleIniFileParser::toString()
	{
		string out;
		for (map<string, int>::const_iterator itr = this->parameters.begin();
			itr != this->parameters.end();
			++itr)
		{
			if (itr != this->parameters.begin())
			{
				out += "\n";
			}
			out += "parameters[" + itr->first + "] = " + to_string(itr->second);
		}
		return out;
	}


map<string, int> SimpleIniFileParser::getMap(){
	return parameters;
}


