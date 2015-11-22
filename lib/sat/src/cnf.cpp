/*
 * Copyright 2015 Andrew Lawrence
 */

#include <cnf.h>
#include <algorithm>

// Using STL
using std::all_of;
using std::for_each;
using std::placeholders::_1;
using std::find_if;
using std::bind;

// Using SAT Types
using SAT::Type::variable;

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

	vector<Clause>::const_iterator CNF::cbegin()
	{
		return clauses.cbegin();
	}

	vector<Clause>::const_iterator CNF::cend()
	{
		return clauses.cend();
	}

	void CNF::getclauses(vector<Clause>& outClauses)
	{
		outClauses = clauses;
	}

	uint16_t CNF::getVariableNumber()
	{
		return variableNumber;
	}

	void CNF::assignVariableTrue(variable variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), bind(&Clause::assignVariableTrue, _1, variableNumber));
	}

	void CNF::assignVariableFalse(variable variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), bind(&Clause::assignVariableFalse, _1, variableNumber));
	}

	void CNF::unassignVariable(variable variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), bind(&Clause::unassignVariable, _1, variableNumber));
	}

	bool CNF::hasConflict()
	{
		return find_if(clauses.begin(), clauses.end(), bind(&Clause::isConflict, _1)) != clauses.end();
	}

} // End namespace SAT