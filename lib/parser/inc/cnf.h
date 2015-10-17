/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CNF_H
#define __CNF_H

#include <vector>
#include <iostream>
#include <clause.h>

using std::istream;
using std::vector;

namespace parsing
{
	//! Class for conjunctive normal form
	class CNF {
	public:
		void addclause(Clause& clause);
	private:
		vector<Clause> clauses;
	};
} // End namespace parsing
#endif // __CLAUSE_H
