/*
 * Copyright 2015 Andrew Lawrence
 */

#include <clause.h>
#include <algorithm>
#include <functional>

using std::all_of;
using std::find_if;
using std::bind;
using std::placeholders::_1;

namespace SAT
{
	void Clause::addliteral(Literal & literal)
	{
		literals.push_back(literal);
	}

	void Clause::assignVariableTrue(variable variableNumber)
	{
		// We make the assumption that the clause is not trivially satisfiable i.e.
		// it contains the literals ¬x and x
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr != literals.end())
			(itr->getPolarity()) ? itr->assign_true() : itr->assign_false();
	}

	void Clause::unassignVariable(variable variableNumber)
	{
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr != literals.end())
			itr->unassign();
	}

	void Clause::assignVariableFalse(variable variableNumber)
	{
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr != literals.end())
			(!itr->getPolarity()) ? itr->assign_true() : itr->assign_false();
	}

	bool Clause::isSatisfied()
	{
		return find_if(literals.begin(), literals.end(), bind(&Literal::isAssignedTrue, _1)) != literals.end();
	}
	bool Clause::isConflict()
	{
		return all_of(literals.begin(), literals.end(), bind(&Literal::isAssignedFalse, _1));
	}

	vector<Literal>::const_iterator Clause::cbegin() const
	{
		return literals.cbegin();
	}

	vector<Literal>::const_iterator Clause::cend() const
	{
		return literals.cend();
	}

}// End namespace SAT
