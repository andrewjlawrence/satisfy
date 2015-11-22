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
#include <decision.h>

// Using STL
using std::shared_ptr;
using std::string;

namespace SAT
{
	// Forward declarations
	class CNF;

	class DPLL {
	public:
		DPLL();
		void bcp(shared_ptr<CNF>& formula, DecisionStack& model);
		bool resolveConflict(shared_ptr<CNF>& formula, DecisionStack& model);
		bool decide(shared_ptr<CNF>& formula, DecisionStack& model);
		bool solve(shared_ptr<CNF>& formula, shared_ptr<SAT::Type::Model>& valuation);
	private:
		string path;
	};

} // end namespace SAT
#endif // End __DPLL_H
