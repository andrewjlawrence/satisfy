/*
 * Copyright 2015 Andrew Lawrence
 */

// STL includes
#include <algorithm>
#include <functional>

// Project includes
#include <clause.h>

// Using STL
using std::find_if;
using std::bind;
using std::placeholders::_1;

// Using SAT Types
using SAT::Type::variable;

namespace SAT
{
/*
 * Constructor
 */
Clause::Clause(void)
	: unassignedLiterals(0),
	  trueLiterals(0),
	  falseLiterals(0)
{
}

/*
 * Add a literal to the clause. 
 */
void Clause::addliteral(Literal & literal)
{
	literals.push_back(literal);
	unassignedLiterals++;
}

/*
 * Assign a variable to be true in the clause.
 */
void Clause::assignVariableTrue(variable variableNumber)
{
	// Really we would remove trivially satisfiable clauses that contain e.g. x and �x.
	auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
	if (itr != literals.end())
	{
		if (itr->getPolarity())
		{
			itr->assign_true();
			trueLiterals++;
		}
		else
		{
			itr->assign_false();
			falseLiterals++;
		}
		unassignedLiterals--;

		auto itr2 = find_if(itr + 1, literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr2 != literals.end())
		{
			if (itr2->getPolarity())
			{
				itr2->assign_true();
				trueLiterals++;
			}
			else
			{
				itr2->assign_false();
				falseLiterals++;
			}
			unassignedLiterals--;
		}
	}
}

/*
 * Unassign a variable.
 */
void Clause::unassignVariable(variable variableNumber)
{
	auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
	if (itr != literals.end())
	{
		// The variable will have always either been assigned true or false.
		if (itr->isAssignedFalse())
			falseLiterals--;
		else
			trueLiterals--;

		unassignedLiterals++;
		itr->unassign();

		auto itr2 = find_if(itr + 1, literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr2 != literals.end())
		{
			// The variable will have always either been assigned true or false.
			if (itr2->isAssignedFalse())
				falseLiterals--;
			else
				trueLiterals--;

			unassignedLiterals++;
			itr2->unassign();
		}
	}
}

/*
 * Assign a variable false.
 */
void Clause::assignVariableFalse(variable variableNumber)
{
	auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
	if (itr != literals.end())
	{
		if (!itr->getPolarity())
		{
			itr->assign_true();
			trueLiterals++;
		}
		else
		{
			itr->assign_false();
			falseLiterals++;
		}

		unassignedLiterals--;

		auto itr2 = find_if(itr + 1, literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr2 != literals.end())
		{
			if (!itr2->getPolarity())
			{
				itr2->assign_true();
				trueLiterals++;
			}
			else
			{
				itr2->assign_false();
				falseLiterals++;
			}
			unassignedLiterals--;
		}
	}
}

/*
 * Check whether a clause is a conflict. i.e. All of its literals are assigned false.
 */
bool Clause::isConflict(void)
{
	return falseLiterals == literals.size();
}

/*
 * Check whether a clause is unit. i.e. All but one of its clauses are assigned false 
 * and the remaining one is unassigned. Since it is the only one left it must be true.
 */
Literal* Clause::isUnit(void)
{
	Literal* result(nullptr);
	if ((literals.size() - falseLiterals == 1) && unassignedLiterals == 1)
	{
		auto itr = find_if(literals.begin(), literals.end(), [](Literal& lit) {return lit.isUnassigned();});
			result = &*itr;
	}

	return result;
}

/*
 * Get the const iterator for the beginning of the set of literals.
 */
vector<Literal>::const_iterator Clause::cbegin(void) const
{
	return literals.cbegin();
}

/*
 * Get the const iterator for the end of the set of literals.
 */
vector<Literal>::const_iterator Clause::cend(void) const
{
	return literals.cend();
}
}// End namespace SAT
