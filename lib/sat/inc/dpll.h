/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DIMACSPARSER_H
#define __DIMACSPARSER_H

#include <string>
#include <memory>

using std::shared_ptr;
using std::string;

namespace SAT
{
	class CNF;

	class DPLL {
	public:
		DPLL();
		bool solve(shared_ptr<CNF>& formula);
	private:
		string path;
	};

} // end namespace parsing
#endif // End __DIMACSPARSER_H
