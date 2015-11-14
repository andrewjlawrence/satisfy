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
	// Hack/Naive Implementation! For now we just select the first unassigned variable
	SAT::variable select(shared_ptr<SAT::CNF>& formula, SAT::Model& model)
	{
		SAT::variable v(0);
		for (auto itr = formula->cbegin();
		     itr != formula->cend() && v == 0;
			 itr ++)
		{
			for (auto itr2 = itr->cbegin();
				 itr2 != itr->cend() && v == 0;
				 itr2++)
			{
				if (itr2->isUnassigned())
					v = itr2->getVariable();
			}
		}

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
		/* We will only resolve with the most recently added literal and all subsequent*/
		Assignment lastDecision(model.back());
		if (lastDecision.second)
			formula->assignVariableTrue(lastDecision.first);
		else
			formula->assignVariableFalse(lastDecision.first);

		// Todo find the unit clauses, add them to the valuation and resolve further
	}

	bool DPLL::backtrack(shared_ptr<CNF>& formula, Model& model)
	{
		for (auto itr = model.rbegin();
			 itr != model.rend();
			 itr++)
		{
			if (itr->second)
			{
				itr->second = false;
				formula->assignVariableFalse(itr->first);
				break;
			}
			else
			{
				model.erase((itr).base());
				formula->unassignVariable(itr->first);
				if (model.empty())
				{
					return false;
				}
			}
		}
		return true;
	}

	bool DPLL::solve(shared_ptr<CNF>& formula, shared_ptr<Model>& SatisfyingAssignment)
	{
		if (formula)
		{
			// This is a model of our formula that maps variables to booleans
			Model valuation;

			while (variable v = select(formula, valuation))
			{
				// Add the variable to the valuation as a positive literal
				// Backtracking will flip to negative literals if possible
				valuation.push_back(Assignment(v, true));
				
				// Perform unit resolution
				unitresolution(formula, valuation);
				
				// Check if the formula has been satisfied
				if (formula->isSatisfied())
				{
					SatisfyingAssignment = std::make_shared<Model>(valuation);
					return true;
				}

				// We have found a conflict so backtrack.
				if (formula->hasConflict())
				{
					if (!backtrack(formula, valuation))
					{
						return false;
					}
					if (formula->isSatisfied())
					{
						SatisfyingAssignment = std::make_shared<Model>(valuation);
						return true;
					}
				}
			}
		}

		return false;
	}
} // End namespace SAT