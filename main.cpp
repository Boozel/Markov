#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool buildMap(string, map< pair<string, string>, string> &);
string generateWord(map< pair<string, string>, string>);

int main(int argc, char *argv[])
{
	map< pair<string, string>, string> suffix_map;

	buildMap(argv[1], suffix_map);
}

bool buildMap(string filename, map< pair<string, string>, string> &in_suffix_map)
{
	ifstream fin;
	string word;
	string key1, key2, value;
	pair<string, string> key;
	vector<string>::iterator it;
	vector<string> whole_file;	//Not very nice to memory - will rewrite function to optimize this.
					//Will have to change loop to a queueing structure or something
					//so I can have just 3 words at a time w/o moving too far.

	whole_file.clear();
	word.clear();

	/* -- Read all file input -- */
	fin.open(filename.c_str());
	while(fin.good())
	{
		//use basic fin - cuts off on spaces and newlines so it's perfect.
		fin >> word;
		whole_file.push_back(word);
	}
	whole_file.pop_back();	//Have to eliminate the extra.
	fin.close();

	/* -- Build the map ------- */
	it = whole_file.begin();
	
	while(it != whole_file.end())
	{
		//First run
		if( it == whole_file.begin() )
		{
			key1[0] = '\0';
			key2[0] = '\0';
			value = *it;
			key = make_pair(key1, key2);
		}
		//Second run
		else if( it - 1 == whole_file.begin() )
		{
			key1[0] = '\0';
			key2 = *(it - 1);
			value = *it;
			key = make_pair(key1, key2);
		}
		//Every other run
		else
		{
			key1 = *(it - 2);
			key2 = *(it - 1);
			value = *it;
			key = make_pair(key1, key2);
		}

		in_suffix_map[key] = value;
		it++;
	}

	return 1;
}

string generateWord(map< pair<string, string>, string>)
{
	return "stub";
}
