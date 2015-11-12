/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CNF_H
#define __CNF_H

// STL includes
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

// Project includes
#include <sat-types.h>
#include <clause.h>

//Using declarations
using std::all_of;
using std::istream;
using std::vector;

namespace SAT
{
	//! Class for conjunctive normal form (CNF) formulas
	class CNF {
	public:
		CNF(uint16_t variableNumber, uint16_t clauseNumber);
		
		void addclause(Clause& clause);
		
		vector<Clause>::const_iterator cbegin();
		vector<Clause>::const_iterator cend();
		/*I dont think we should be passing the formula around*/
		void getclauses(vector<Clause>& outClauses);
		uint16_t getVariableNumber();
		
		void assignVariableTrue(variable variableNumber);
		void assignVariableFalse(variable variableNumber);
		void unassignVariable(variable variableNumber);
		
		bool isSatisfied();
		bool hasConflict();


	private:
		vector<Clause> clauses;
		vector<variable> unassignedVars;
		uint16_t clauseNumber; // This is going to be the maximum number of clauses
		uint16_t variableNumber; // This likely to be the maximum number of literals in a clause;
	};
} // End namespace SAT
#endif // __CNF_H
