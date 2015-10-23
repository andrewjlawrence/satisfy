/*
 * Copyright 2015 Andrew Lawrence
 */

#include <cnf.h>
#include <algorithm>

namespace SAT
{
	CNF::CNF(uint16_t clauseNumber, uint16_t variableNumber)
		:clauseNumber(clauseNumber), variableNumber(variableNumber)
	{
		clauses.reserve(clauseNumber);
	}

	void CNF::addclause(Clause& clause)
	{
		clauses.push_back(clause);
	}
	
	void CNF::getclauses(vector<Clause>& outClauses)
	{
		outClauses = clauses;
	}

	uint16_t CNF::getVariableNumber()
	{
		return variableNumber;
	}

	void CNF::assignVariable(uint16_t variableNumber, bool assignment)
	{
		
	}

	bool CNF::isSatisfied()
	{
		return all_of(clauses.begin(), clauses.end(), std::bind(&Clause::isSatisfied, std::placeholders::_1));
	}
} // End namespace parsing