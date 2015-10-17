/*
 * Copyright 2015 Andrew Lawrence
 */
#include "..\inc\cnf.h"

namespace parsing
{
	void CNF::addclause(Clause& clause)
	{
		clauses.push_back(clause);
	}
} // End namespace parsing