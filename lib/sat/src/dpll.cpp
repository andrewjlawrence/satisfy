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
#include <utils.h>

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
variable select(shared_ptr<SAT::CNF>& formula, SAT::DecisionStack& model)
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
} //End annonymous namespace

namespace SAT
{
DPLL::DPLL(void)
{
}

/*
 * Boolean constraint propagation
 */
void DPLL::bcp(shared_ptr<CNF>& formula, DecisionStack& model)
{
	/* We will only resolve with the most recently added literal and all subsequent*/
	if (!model.empty())
	{
		Decision lastDecision(model.top());
		if (lastDecision.getAssignment())
			formula->assignVariableTrue(lastDecision.getVariable());
		else
			formula->assignVariableFalse(lastDecision.getVariable());
	}	
	
	// Now we should check for unit clauses and propagate them.
	Literal* unitLiteral(nullptr);
	while (unitLiteral = formula->hasUnit())
	{
		if (unitLiteral->getPolarity())
		{
			model.push(Decision(Type::Assignment(unitLiteral->getVariable(), true), false));
			formula->assignVariableTrue(unitLiteral->getVariable());
		}
		else
		{
			model.push(Decision(Type::Assignment(unitLiteral->getVariable(), false), false));
			formula->assignVariableFalse(unitLiteral->getVariable());
		}
	}

}

/* Currently backtracking assumes that the variable has been set to true first. 
   We will want to allow variable assignments to occur in either order. */
bool DPLL::resolveConflict(shared_ptr<CNF>& formula, DecisionStack& model)
{
	// Backtrack
	while (!model.empty() && !model.top().flip())
	{
		formula->unassignVariable(model.top().getVariable());
		model.pop();
	}

	// If we have done a flip then unassign the variable.
	if (!model.empty())
	{
		formula->unassignVariable(model.top().getVariable());
	}

	return !model.empty();
}

/*
 * Make a decision and branch the search.
 */
variable DPLL::decide(shared_ptr<CNF>& formula, DecisionStack& model)
{
	if (model.empty() || model.top().isPropagated())
	{
		variable var(select(formula, model));
		if (var != 0)
			model.push(Decision(Type::Assignment(var, true), true));
		return var;
	}
	else
	{
		return 0;
	}
}

/*
 * Solve the formula
 */
bool DPLL::solve(shared_ptr<CNF>& formula, shared_ptr<Model>& SatisfyingAssignment)
{
	if (formula)
	{
		DecisionStack valuation;

		while (true)
		{	
			if (!decide(formula, valuation))
			{
				// All variables in the formula have been decided.
				SatisfyingAssignment = std::make_shared<Model>(Decision::toModel(valuation));
				return true;
			}

			// Perform boolean constraint propagation
			bcp(formula, valuation);
				
			if (formula->hasConflict())
			{
				if (!resolveConflict(formula, valuation))
				{
					return false;
				}
				SATISFY_ASSERT(!formula->hasConflict());
			}
		}
	}
	return false;
}
} // End namespace SAT