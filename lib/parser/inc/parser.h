/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DIMACSPARSER_H
#define __DIMACSPARSER_H

#include <string>

using std::string;

namespace parsing
{
	class CNF;

	class DimacsParser {
	public:
		DimacsParser(string& inpath);
		void load(CNF& formula);
	private:
		string path;
	};

} // end namespace parsing
#endif // End __DIMACSPARSER_H
