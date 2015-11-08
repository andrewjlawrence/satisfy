/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DIMACSPARSER_H
#define __DIMACSPARSER_H

#include <string>
#include <memory>
#include <map>
#include <vector>

using std::shared_ptr;
using std::string;

namespace SAT
{
	// We define a model to be a map from variables to booleans
	using variable = uint16_t;
	using Assignment = std::pair<variable, bool>;
	using Model = std::map<variable, bool>;
	class CNF;

	class DPLL {
	public:
		DPLL();
		void unitresolution(shared_ptr<CNF>& formula, Model& model);
		void backtrack(Model& model);
		bool solve(shared_ptr<CNF>& formula);
	private:
		string path;
	};

} // end namespace parsing
#endif // End __DIMACSPARSER_H
