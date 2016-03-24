#ifndef CNF_H
#define CNF_H
#include <map>
#include <set>
#include <string>

class CNF
{
private:
	std::set<std::string> non_terminals;
	std::set<std::string> alphabets;
	std::string start_symbol;
	std::map<std::string, std::set<std::string>> grammar;
	std::map<std::string, std::set<std::string>> create_grammar(std::string filename);
	
public:
	CNF(std::string filename);
	bool cyk_parse(std::string s);
};

#endif