/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DPLL_H
#define __DPLL_H

#include <string>
#include <memory>
#include <map>
#include <vector>
#include <sat-types.h>

// Using declarations
using std::shared_ptr;
using std::string;

namespace SAT
{
	// Forward declaration
	class CNF;

	class DPLL {
	public:
		DPLL();
		void unitresolution(shared_ptr<CNF>& formula, Model& model);
		bool backtrack(shared_ptr<CNF>& formula, Model& model);
		bool solve(shared_ptr<CNF>& formula, shared_ptr<Model>& valuation);
	private:
		string path;
	};

} // end namespace SAT
#endif // End __DPLL_H
