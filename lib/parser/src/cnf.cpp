/*
 * Copyright 2015 Andrew Lawrence
 */
#include "..\inc\cnf.h"


void CNF::addclause(Clause& clause)
{
	clauses.push_back(clause);
}

ostream & CNF::operator<<(const CNF & rhs)
{
	  // TODO: insert return statement here
}
