/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DIMACSPARSER_H
#define __DIMACSPARSER_H

#include <string>
#include <memory>

using std::shared_ptr;
using std::string;

// Forward declaration
namespace SAT 
{
	class CNF;
}

namespace parsing
{
	class DimacsParser {
	public:
		DimacsParser(const string& inpath);
		bool load(shared_ptr<SAT::CNF>& formula);
	private:
		string path;
	};

} // end namespace parsing
#endif // End __DIMACSPARSER_H
