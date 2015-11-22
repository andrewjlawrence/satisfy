/*
 * Copyright 2015 Andrew Lawrence
 */

// STL includes
#include <memory>
#include <map>
#include <vector>

// Project includes
#include <decision.h>
#include <clause.h>
#include <cnf.h>
#include <dpll.h>

// Using STL
using std::map;
using std::vector;
using std::shared_ptr;

// Using SAT Types
using SAT::Type::variable;
using SAT::Type::Model;

namespace 
{
	// Hack/Naive Implementation! For now we just select the first unassigned variable
	variable select(shared_ptr<SAT::CNF>& formula, Model& model)
	{
		variable v(0);
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

	/*
	 * Boolean constraint propagation
	 */
	void DPLL::bcp(shared_ptr<CNF>& formula, DecisionStack& model)
	{
		/* We will only resolve with the most recently added literal and all subsequent*/
		Decision lastDecision(model.top());
		if (lastDecision.getAssignment())
			formula->assignVariableTrue(lastDecision.getVariable());
		else
			formula->assignVariableFalse(lastDecision.getVariable());

		// Todo find the unit clauses, add them to the valuation and resolve further
	}

	/* Currently backtracking assumes that the variable has been set to true first. 
	   We will want to allow variable assignments to occur in either order. */
	bool DPLL::resolveConflict(shared_ptr<CNF>& formula, DecisionStack& model)
	{
		// Backtrack
		while (!model.empty())
		{
			if (model.top().flip())
			{
				return true;
			}
			else
			{
				formula->unassignVariable(model.top().getVariable());
				model.pop();
			}
		}
		return false;
	}

	bool DPLL::decide(shared_ptr<CNF>& formula, DecisionStack& model)
	{
		return false;
	}

	bool DPLL::solve(shared_ptr<CNF>& formula, shared_ptr<Model>& SatisfyingAssignment)
	{
		if (formula)
		{
			DecisionStack valuation;

			while (true)
			{			
				// Perform boolean constraint propagation
				bcp(formula, valuation);
				
				if (!formula->hasConflict())
				{
					if (!decide(formula, valuation))
					{
						// All variables in the formula have been decided.
						SatisfyingAssignment = std::make_shared<Model>(Decision::toModel(valuation));
						return true;
					}
				}
				else
				{
					if (!resolveConflict(formula, valuation))
					{
						return false;
					}
				}
			}
		}
		return false;
	}

} // End namespace SAT