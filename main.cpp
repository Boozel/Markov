#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

bool buildMap(string, map< pair<string, string>, string> &);

int main()
{
	map< pair<string, string>, string> suffix_map;

	buildMap("fark.com", suffix_map);
}

bool buildMap(string filename, map< pair<string, string>, string> &in_suffix_map)
{
	ifstream fin;

	fin.open(filename.c_str());
	while(fin.good())
	{
		
	}
	fin.close();
	return 1;
}
