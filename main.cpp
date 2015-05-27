#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>	//For Windows

using namespace std;

bool buildMap(string, map< pair<string, string>, vector<string> > &);
void generateWord(map< pair<string, string>, vector<string> >);

int main(int argc, char *argv[])
{
	map< pair<string, string>, vector<string> > suffix_map;
	
	srand(time(NULL));

	buildMap(argv[1], suffix_map);
	generateWord(suffix_map);
}

bool buildMap(string filename, map< pair<string, string>, vector<string> > &in_suffix_map)
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

		in_suffix_map[key].push_back(value);
		it++;
	}
	//Ensure this deallocates.

	whole_file.clear();
	word.clear();

	return 1;
}

void generateWord(map< pair<string, string>, vector<string> > in_suffix_map)
{
	string prevkey1 = "\0", prevkey2 = "\0", output;
	pair<string, string> key;
	int size_in_kp, randomized_word_index, random_end;
	string::size_type str_search;
	bool finished = false;

	while(finished == false)
	{
		key = make_pair(prevkey1, prevkey2);
		size_in_kp = in_suffix_map[key].size();

		randomized_word_index = rand() % size_in_kp;

		output = in_suffix_map[key][randomized_word_index];
		prevkey1 = prevkey2;
		prevkey2 = output;

		key = make_pair(prevkey1, prevkey2);

		if(in_suffix_map[key].size() == 0)	//Close if map pair is invalid.
		{
			finished = true;
		}

		random_end = rand() % 1000 + 1;

		if(random_end < 20)			//Randomly close on a period.
		{
			str_search = output.find(".");
			if(str_search != string::npos)
			{
				finished = true;
			}
		}

		cout << output << " ";
	}
	cout << endl;
}
