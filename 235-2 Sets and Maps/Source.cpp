#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <cctype>
#include <iterator>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

void printVector(vector<string> vect1, string input_name, string filename, string word)
{
	ifstream inputfile;
	ofstream outputfile;
	inputfile.open(filename.c_str());
	if (inputfile.is_open())
	{
		while (inputfile >> word)
		{
			for (int i = 0; i < word.size(); ++i)
			{
				if (!iswalpha(word[i]))
				{
					word.erase(i, 1);
					i--;
				}
			}
			vect1.push_back(word);
		}
	}

	string output_name = input_name + "_vector.txt";
	outputfile.open(output_name);
	for (int i = 0; i < vect1.size(); i++)
	{
		outputfile << vect1[i] << "\n";
	}
	inputfile.close();
	outputfile.close();

	map<string, string> wordmap;
	string last = "";
	for (vector<string>::iterator it = vect1.begin(); it != vect1.end(); it++)
	{
		wordmap[last] = *it;
		last = *it;
	}

	string output_map = input_name + "_1_1.txt";
	outputfile.open(output_map);
	for (auto p : wordmap)
	{
		outputfile << p.first << ", " << p.second << "\n";
	}
	outputfile.close();

	string state = "";
	for (int i = 0; i < 100; i++)
	{
		cout << wordmap[state] << " ";
		state = wordmap[state];
	}
	cout << endl;
	cout << endl;

	map< string, vector<string> > wordmap_a;
	state = "";
	for (vector<string>::iterator it = vect1.begin(); it != vect1.end(); it++)
	{
		wordmap_a[state].push_back(*it);
		state = *it;
	}

	map<string, vector<string> >::iterator it = wordmap_a.begin();
	advance(it, 6);
	string s = it->first;
	vector<string> new_vec = it->second;
	cout << s << ": ";
	for (int i = 0; i < new_vec.size(); i++)
	{
		cout << new_vec[i] << ", ";
	}
	cout << endl;
	cout << endl;

	srand(time(NULL));

	state = "";
	for (int i = 0; i < 100; i++)
	{
		int ind = rand() % wordmap_a[state].size();
		cout << wordmap_a[state][ind] << " ";
		state = wordmap_a[state][ind];
	}
	cout << endl;
	cout << endl;

	map< list<string>, vector<string> > wordmap_b;
	list<string> new_state;
	for (int i = 0; i < 2; i++)
	{
		new_state.push_back("");
	}
	for (vector<string>::iterator it = vect1.begin(); it != vect1.end(); it++)
	{
		wordmap_b[new_state].push_back(*it);
		new_state.push_back(*it);
		new_state.pop_front();
	}

	list<string> new_state1;
	for (int i = 0; i < 2; i++)
	{
		new_state1.push_back("");
	}


	for (int i = 0; i < 100; i++)
	{
		if (wordmap_b[new_state1].size() == 0)
		{
			new_state1.pop_back();
			new_state1.pop_back();
			new_state1.push_back("");
			new_state1.push_back("");
		}
		int ind = rand() % wordmap_b[new_state1].size();
		cout << wordmap_b[new_state1][ind] << " ";
		new_state1.push_back(wordmap_b[new_state1][ind]);
		new_state1.pop_front();
	}
	cout << endl;

	
}

int main(int argc, char* argv[])
{
	string filename;
	set<string> set1;
	string word;
	ifstream inputfile;
	ofstream outputfile;
	vector<string> vect1;
	string input_name;

	//cin >> input_name;
	input_name = argv[1];
	filename = input_name + ".txt";
	inputfile.open(filename.c_str());
	if (inputfile.is_open())
	{
		while (inputfile >> word)
		{
			for (int i = 0; i < word.size(); ++i)
			{
				if (!iswalpha(word[i]))
				{
					word.erase(i, 1);
					i--;
				}
			}
			set1.insert(word);
		}
	}

	string output_name = input_name + "_set.txt";
	outputfile.open(output_name);
	for (set<string>::const_iterator itr = set1.begin(); itr != set1.end(); ++itr)
	{
		outputfile << *itr << "\n";
	}
	inputfile.close();
	outputfile.close();

	printVector(vect1, input_name, filename, word);

	system("pause");
	return 0;
}