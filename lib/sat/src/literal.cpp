/*
 * Copyright 2015 Andrew Lawrence
 */
#include <utils.h>
#include <literal.h>

// Using SAT Types
using SAT::Type::variable;

namespace SAT
{
	Literal::Literal(variable variableNumber, bool isPos, Assignment pol)
		:var(variableNumber), polarity(isPos), assignment(pol)
	{}

	void Literal::assign_true(void)
	{
		SATISFY_ASSERT(assignment == Assignment::False || assignment == Assignment::Unassigned);
		assignment = Assignment::True;
	}

	void Literal::assign_false(void)
	{
		SATISFY_ASSERT(assignment == Assignment::True || assignment == Assignment::Unassigned);
		assignment = Assignment::False;
	}

	void Literal::unassign(void)
	{
		SATISFY_ASSERT(assignment == Assignment::True || assignment == Assignment::False);
		assignment = Assignment::Unassigned;
	}

	bool Literal::isUnassigned(void) const
	{
		return assignment == Assignment::Unassigned;
	}

	bool Literal::isAssignedTrue(void) const
	{
		return assignment == Assignment::True;
	}

	bool Literal::isAssignedFalse(void) const
	{
		return assignment == Assignment::False;
	}

	variable Literal::getVariable(void) const
	{
		return var;
	}

	bool Literal::getPolarity(void) const
	{
		return polarity;
	}

	bool Literal::operator==(const Literal& rhs) const
	{
		return polarity == rhs.polarity &&
		       assignment == rhs.assignment;
	}

	bool Literal::operator!=(const Literal& rhs) const
	{
		return !(*this == rhs);
	}

	bool Literal::operator<(const Literal& other) const
	{
		return this->var < other.var && this->polarity < other.polarity;
	}

} // End namespace SAT
