#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "util.h"

using namespace std;

//split a string at a given delimiter
vector<string> split(string &s, char delim)
{
	stringstream ss(s);
	vector<string> elems;
	string item;
	while (getline(ss, item, delim))
		elems.push_back(item);
	return elems;
}

//function to split a function at white space and return a vector of words of the string
vector<string> split_ws(string& s)
{
	vector<string> result;
    istringstream st(s);
    string token;
    while(st >> token)
		result.push_back(token);
	
	return result;
}