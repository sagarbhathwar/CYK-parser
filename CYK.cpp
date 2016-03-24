#include <iostream>
#include <vector>
#include <string>
#include "CNF.h"

using namespace std;

int main()
{
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	CNF grammar(filename);
	while(true)
	{
		string s;
		cout << "Enter the string: ";
		cin >> s;
		bool accepted = grammar.cyk_parse(s);
		if(accepted)
			cout << "Accepted" << endl;
		else
			cout << "Rejected" << endl;
	}
	
}