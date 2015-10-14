#include "..\inc\clause.h"
/*
 * Copyright 2015 Andrew Lawrence
 */

void Clause::addliteral(Literal & literal)
{
	literals.push_back(literal);
}
