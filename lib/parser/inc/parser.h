/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DIMACSPARSER_H
#define __DIMACSPARSER_H

#include <string>
#include <memory>
#include <sat-context.h>

using std::shared_ptr;
using std::string;

// Forward declaration
namespace SAT 
{
	class CNF;
}

namespace parsing
{
	class DimacsParser : public SAT::Context
	{
	public:
		DimacsParser(const string& inpath);
		bool load();
	private:
		string path;
	};

} // end namespace parsing
#endif // End __DIMACSPARSER_H
