/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CNF_H
#define __CNF_H

#include <vector>
#include <iostream>
#include <clause.h>
#include <algorithm>
#include <functional>

using std::all_of;
using std::istream;
using std::vector;

namespace SAT
{
	//! Class for conjunctive normal form
	class CNF {
	public:
		CNF(uint16_t clauseNumber, uint16_t variableNumber);
		void addclause(Clause& clause);
		void getclauses(vector<Clause>& outClauses);
		uint16_t getVariableNumber();
		void assignVariable(uint16_t variableNumber, bool assignment);
		bool isSatisfied();

	private:
		vector<Clause> clauses;
		uint16_t clauseNumber; // This is going to be the maximum number of clauses
		uint16_t variableNumber; // This likely to be the maximum number of literals in a clause;
	};
} // End namespace parsing
#endif // __CNF_H
