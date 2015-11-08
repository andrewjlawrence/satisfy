/*
 * Copyright 2015 Andrew Lawrence
 */

#include <cnf.h>
#include <algorithm>

using std::all_of;
using std::for_each;
using std::placeholders::_1;
using std::find_if;
using std::bind;

namespace SAT
{
	CNF::CNF(uint16_t variableNumber, uint16_t clauseNumber)
		:variableNumber(variableNumber),clauseNumber(clauseNumber)
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

	void CNF::assignVariableTrue(uint16_t variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), bind(&Clause::assignVariableTrue, _1, variableNumber));
	}

	void CNF::assignVariableFalse(uint16_t variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), bind(&Clause::assignVariableTrue, _1, variableNumber));
	}

	bool CNF::isSatisfied()
	{
		return all_of(clauses.begin(), clauses.end(), bind(&Clause::isSatisfied, _1));
	}

	bool CNF::hasConflict()
	{
		return find_if(clauses.begin(), clauses.end(), bind(&Clause::isConflict, _1)) != clauses.end();
	}

} // End namespace parsing