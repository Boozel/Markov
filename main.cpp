#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool buildMap(string, map< pair<string, string>, string> &);

int main(int argc, char *argv[])
{
	map< pair<string, string>, string> suffix_map;

	buildMap(argv[1], suffix_map);
}

bool buildMap(string filename, map< pair<string, string>, string> &in_suffix_map)
{
	ifstream fin;
	string word;
	vector<string> whole_file;	//Not very nice to memory - will rewrite function to optimize this.
					//Will have to change loop to a queueing structure or something
					//so I can have just 3 words at a time w/o moving too far.

	whole_file.clear();
	word.clear();

	fin.open(filename.c_str());

	while(fin.good())
	{
		//use basic fin - cuts off on spaces and newlines so it's perfect.
		fin >> word;
		whole_file.push_back(word);
	}

	fin.close();
	return 1;
}
