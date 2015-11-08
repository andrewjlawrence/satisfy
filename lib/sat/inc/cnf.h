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
		CNF(uint16_t variableNumber, uint16_t clauseNumber);
		void addclause(Clause& clause);
		void getclauses(vector<Clause>& outClauses);
		uint16_t getVariableNumber();
		void assignVariableTrue(uint16_t variableNumber);
		void assignVariableFalse(uint16_t variableNumber);
		bool isSatisfied();
		bool hasConflict();
	private:
		vector<Clause> clauses;
		uint16_t clauseNumber; // This is going to be the maximum number of clauses
		uint16_t variableNumber; // This likely to be the maximum number of literals in a clause;
	};
} // End namespace parsing
#endif // __CNF_H
