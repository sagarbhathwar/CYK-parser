#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include "CNF.h"
#include "util.h"

using namespace std;

map<string, set<string> > CNF::create_grammar(string filename)
{
	ifstream file(filename);
	vector<vector<string> > input;
	for (string line; getline(file, line);)
		input.push_back(split_ws(line));
	
	non_terminals.insert(input[0].begin(), input[0].end());
	alphabets.insert(input[1].begin(), input[1].end());
	start_symbol = input[2][0];
	
	map<string, set<string> > grammar;
	for(int i = 4; i < input.size(); ++i)
		grammar.insert(make_pair(input[i][0], set<string>(input[i].begin() + 2, input[i].end())));
	
	for(auto &x: grammar)
		x.second.erase("|");
	return grammar;
}

CNF::CNF(string filename) : grammar(create_grammar(filename)) {}
bool CNF::cyk_parse(string s)
{
	vector<vector<set<string>>> table(s.size() + 1);
	for(int i = 1; i < table.size(); ++i)
		table[i] = vector<set<string>>(s.size() - i + 2);
	
	//fill first row of the parsing table
	for(int i = 0; i < s.size(); ++i)
		for(auto x: grammar)
			if(x.second.find(string(1,s[i])) != x.second.end())
				table[1][i+1].insert(x.first);
			
	
	for(int i = 2; i < table.size(); ++i)
	{
		for(int j = 1; j < table[i].size(); ++j)
		{
			set<string> temp_str_set;
			for(int k = 1; k < i; ++k)
			{
				set<string> s1 = table[k][j];
				set<string> s2 = table[i - k][k + j];
				set<string> temp_set;
				for(auto x: s1)
					for(auto y: s2)
						temp_set.insert(x + y);
				for(auto x: grammar)
					for(auto y: temp_set)
						if(x.second.find(y) != x.second.end())
							temp_str_set.insert(x.first);
			}
			table[i][j] = temp_str_set;
		}
	}
	
	return table[table.size() - 1][1].find(start_symbol) != table[table.size() - 1][1].end();
}