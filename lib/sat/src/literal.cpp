/*
 * Copyright 2015 Andrew Lawrence
 */

#include <literal.h>

// Using SAT Types
using SAT::Type::variable;

namespace SAT
{
	Literal::Literal(variable variableNumber, bool isPos, Assignment pol)
		:var(variableNumber), polarity(isPos), assignment(pol)
	{}

	void Literal::assign_true()
	{
		assignment = Assignment::True;
	}

	void Literal::assign_false()
	{
		assignment = Assignment::False;
	}

	void Literal::unassign()
	{
		assignment = Assignment::Unassigned;
	}

	bool Literal::isUnassigned() const
	{
		return assignment == Assignment::Unassigned;
	}

	bool Literal::isAssignedTrue() const
	{
		return assignment == Assignment::True;
	}

	bool Literal::isAssignedFalse() const
	{
		return assignment == Assignment::False;
	}

	variable Literal::getVariable() const
	{
		return var;
	}

	bool Literal::getPolarity() const
	{
		return polarity;
	}
}
 // End namespace SAT