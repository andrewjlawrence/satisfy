/*
 * Copyright 2015 Andrew Lawrence
 */

// STL includes
#include <memory>
#include <clause.h>
#include <map>
#include <vector>

// Project includes
#include <cnf.h>
#include <dpll.h>

// Using declarations
using std::map;
using std::vector;
using std::shared_ptr;

namespace 
{
	// Hack! For now we just select the first unassigned variable
	SAT::variable select(shared_ptr<SAT::CNF>& formula, SAT::Model& model)
	{
		SAT::variable v(0);

		return v;
	}
}


namespace SAT
{
	DPLL::DPLL()
	{
	}

	void DPLL::unitresolution(shared_ptr<CNF>& formula, Model& model)
	{

	}

	void DPLL::backtrack(Model& model)
	{
		for (auto itr = model.rbegin();
			 itr != model.rend();
			 itr++)
		{
			if (itr->second)
			{
				itr->second = false;
			}
			else
			{
				model.erase((itr + 1).base());
				if (model.empty())
				{
					
				}
			}
		}
	}

	bool DPLL::solve(shared_ptr<CNF>& formula)
	{
		if (formula)
		{
			// This is a model of our formula that maps variables to booleans
			Model valuation;

			while (variable v = select(formula, valuation))
			{
				// Add the variable to the valuation as a positive literal
				// Backtracking will flip to negative literals if possible
				valuation.insert(Assignment(v, true));
				
				// Perform unit resolution
				unitresolution(formula, valuation);
				
				// Check if the formula has been satisfied
				if (formula->isSatisfied())
				{
					return true;
				}

				// We have found a conflict so backtrack.
				if (formula->hasConflict())
				{
					backtrack(valuation);
				}
			}
		}

		return false;
	}
} // End namespace SAT