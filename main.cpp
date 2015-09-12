#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>	//For Windows

using namespace std;

bool buildMap(string, map< pair<string, string>, vector<string> > &);
void exportMap(map< pair<string, string>, vector<string> >);
void injectStarterWords(string filename, map< pair<string, string>, vector<string> > &in_suffix_map);
void generateWord(map< pair<string, string>, vector<string> > in_suffix_map);


int main(int argc, char *argv[])
{
	map< pair<string, string>, vector<string> > suffix_map;

	srand(time(NULL));

	injectStarterWords("db", suffix_map);
	if(argv[1] != NULL)
	{
		buildMap(argv[1], suffix_map);
	}
	generateWord(suffix_map);
	exportMap(suffix_map);
}

bool buildMap(string filename, map< pair<string, string>, vector<string> > &in_suffix_map)
{
	ifstream fin;
	string word;
	string key1, key2, value;
	pair<string, string> key;

	word.clear();
	value[0] = '\0';
	key2[0] = '\0';

	/* -- Read all file input -- */
	fin.open(filename.c_str());
	while (fin.good())
	{
		//use basic fin - cuts off on spaces and newlines so it's perfect.
		fin >> word;
		key1 = key2;
		key2 = value;
		key = make_pair(key1, key2);
		value = word;
		in_suffix_map[key].push_back(value);
	}
	fin.close();

	//Ensure this deallocates.
	word.clear();

	return 1;
}


void exportMap(map< pair<string, string>, vector<string> > outMap)
{
	ofstream fout;
	map< pair<string, string>, vector<string> >::iterator it;
	vector<string>::iterator it2;

	fout.open("db");

	it = outMap.begin();

	while(it!= outMap.end())
	{
		it2 = it->second.begin();
		fout <<"-KEYBAWS- " << it->first.first << " -KEYBAWS- " << it->first.second << " ";
		while(it2 != it->second.end())
		{
			fout << *it2 << " ";
			it2++;
		}
		it++;
		
		fout << "-ENDBAWS-" << endl;
	}

	fout.close();
}

void injectStarterWords(string filename, map< pair<string, string>, vector<string> > &in_suffix_map)
{
	ifstream fin;
	string word;
	string key1, key2;
	pair<string, string> key;

	word.clear();
	word[0] = '\0';
	key1[0] = '\0';
	key2[0] = '\0';

	/* -- Read all file input -- */
	fin.open(filename.c_str());

	key = make_pair(key1, key2);

	fin >> word;

	while(word == "-KEYBAWS-")
	{
		fin >> word;
	}

	while(word != "-ENDBAWS-" && fin.good())
	{
		in_suffix_map[key].push_back(word);
		fin >> word;
	}

	fin >> word;
	fin >> word;

	//Get next key
	while(word == "-KEYBAWS-")
	{
		fin >> word;
		key2 = word;
		key = make_pair(key1, key2);
		fin >> word;

		while(word != "-ENDBAWS-" && fin.good())
		{
			in_suffix_map[key].push_back(word);
			fin >> word;
		}

		fin >> word;
		fin >> word;
	}

	while (fin.good())
	{
		//use basic fin - cuts off on spaces and newlines so it's perfect.
		if(word != "-ENDBAWS-")
		{
			key1 = word;
		}
		
		fin >> word;
		fin >> word;

		if(word != "-ENDBAWS-")
		{
			key2 = word;
		}

		key = make_pair(key1, key2);

		fin >> word;
		while(word != "-ENDBAWS-" && fin.good())
		{
			in_suffix_map[key].push_back(word);
			fin >> word;
		}

		fin >> word;
		fin >> word;
	}
	fin.close();

	//Ensure this deallocates.
	word.clear();
}

void generateWord(map< pair<string, string>, vector<string> > in_suffix_map)
{
	string prevkey1 = "\0", prevkey2 = "\0", output;
	pair<string, string> key;
	int size_in_kp, randomized_word_index, random_end, random_break;
	string::size_type str_search;
	bool finished = false;

	prevkey1[0] = '\0';
	prevkey2[0] = '\0';

	while (finished == false)
	{
		key = make_pair(prevkey1, prevkey2);

		size_in_kp = in_suffix_map[key].size();

		randomized_word_index = rand() % size_in_kp;

		output = in_suffix_map[key][randomized_word_index];
		prevkey1 = prevkey2;
		prevkey2 = output;

		key = make_pair(prevkey1, prevkey2);

		if (in_suffix_map[key].size() == 0)	//Close if map pair is invalid.
		{
			finished = true;
		}

		random_end = rand() % 1000 + 1;

		if (random_end < 20)			//Randomly close on a period.
		{
			str_search = output.find(".");
			if (str_search != string::npos)
			{
				finished = true;
			}
		}

		random_break = rand() % 1000 + 1;

		cout << output << " ";

		if (random_break < 125)			//Random line breaks on periods
		{
			str_search = output.find(".");
			if (str_search != string::npos)
			{
				cout << endl << endl;
			}
		}
	}
	cout << endl;
}
