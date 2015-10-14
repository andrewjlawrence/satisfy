#ifndef __PARSER_H
#define __PARSER_H

#include <string>

using std::string;

class CNF;

class Parser {
public:
	Parser(string& inpath);
	void load(CNF& formula);
private:
  string path;
};

#endif
