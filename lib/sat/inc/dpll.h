/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DPLL_H
#define __DPLL_H

#include <string>
#include <memory>
#include <map>
#include <vector>

// Using declarations
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

} // end namespace SAT
#endif // End __DPLL_H
