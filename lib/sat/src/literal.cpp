/*
 * Copyright 2015 Andrew Lawrence
 */

#include <literal.h>

namespace SAT
{
	Literal::Literal(int variable, Polarity pol)
		:var(variable), pol(pol)
	{}

	void Literal::assign_pos()
	{
		pol = Polarity::Pos;
	}

	void Literal::assign_neg()
	{
		pol = Polarity::Neg;
	}

	void Literal::unassign()
	{
		pol = Polarity::Unassigned;
	}

	bool Literal::isAssignedPos()
	{
		return pol == Literal::Polarity::Pos;
	}

	bool Literal::isAssignedNeg()
	{
		return false;
	}

	int Literal::getVariable()
	{
		return var;
	}
}
 // End namespace parsing