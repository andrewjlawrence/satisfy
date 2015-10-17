#include "..\inc\literal.h"
/*
 * Copyright 2015 Andrew Lawrence
 */
namespace parsing
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
}
 // End namespace parsing