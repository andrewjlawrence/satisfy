#include "..\inc\literal.h"
/*
 * Copyright 2015 Andrew Lawrence
 */

Literal::Literal(int variable, polarity pol)
	:var(variable), pol(pol)
{}

void Literal::assign_pos()
{
	pol = Pos;
}

void Literal::assign_neg()
{
	pol = Neg;
}

void Literal::unassign()
{
	pol = Unassigned;
}
