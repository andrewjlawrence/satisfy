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

	void Clause::assignVariableTrue(uint16_t variableNumber)
	{
		// We make the assumption that the clause is not trivially satisfiable i.e.
		// it contains the literals ¬x and x
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber || -lit.getVariable() == variableNumber;});
		(0 < itr->getVariable()) ? itr->assign_pos() : itr->assign_neg();
	}

	void Clause::unassignVariable(uint16_t variableNumber)
	{
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber || -lit.getVariable() == variableNumber;});
		(0 < itr->getVariable()) ? itr->assign_pos() : itr->assign_neg();
	}

	void Clause::assignVariableFalse(uint16_t variableNumber)
	{
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber || -lit.getVariable() == variableNumber;});
		(itr->getVariable() < 0) ? itr->assign_pos() : itr->assign_neg();
	}

	bool Clause::isSatisfied()
	{
		return find_if(literals.begin(), literals.end(), bind(&Literal::isAssignedPos, _1)) != literals.end();
	}
	bool Clause::isConflict()
	{
		return all_of(literals.begin(), literals.end(), bind(&Literal::isAssignedNeg, _1));
	}
}
