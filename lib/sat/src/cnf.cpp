/*
 * Copyright 2015 Andrew Lawrence
 */

#include <cnf.h>
#include <algorithm>

// Using STL
using std::for_each;
using std::placeholders::_1;
using std::find_if;
using std::bind;

// Using SAT Types
using SAT::Type::variable;

namespace SAT
{
/*
 * Constructor
 */
CNF::CNF(uint16_t variableNumber, uint16_t clauseNumber)
	:variableNumber(variableNumber),clauseNumber(clauseNumber)
{
	clauses.reserve(clauseNumber);
}

/*
 * Add a clause to the CNF
 */
void CNF::addclause(Clause& clause)
{
	clauses.push_back(clause);
}

/*
 * Get a const iterator to the beginning of the CNF.
 */
vector<Clause>::const_iterator CNF::cbegin(void)
{
	return clauses.cbegin();
}

/*
 * Get a const iteratore to the end of the CNF.
 */
vector<Clause>::const_iterator CNF::cend(void)
{
	return clauses.cend();
}

/*
 * Get the clauses in the CNF.
 */
void CNF::getclauses(vector<Clause>& outClauses)
{
	outClauses = clauses;
}

/*
 * Get the number of variable in the CNF.
 */
uint16_t CNF::getVariableNumber(void)
{
	return variableNumber;
}

/*
 * Assign a variable true in the formula.
 */
void CNF::assignVariableTrue(variable variableNumber)
{
	for_each(clauses.begin(), clauses.end(), bind(&Clause::assignVariableTrue, _1, variableNumber));
}

/*
 * Assign a variable false in the formula.
 */
void CNF::assignVariableFalse(variable variableNumber)
{
	for_each(clauses.begin(), clauses.end(), bind(&Clause::assignVariableFalse, _1, variableNumber));
}

/*
 * Unassign a variable in the formula.
 */
void CNF::unassignVariable(variable variableNumber)
{
	for_each(clauses.begin(), clauses.end(), bind(&Clause::unassignVariable, _1, variableNumber));
}

/*
 * Check whether the formula has a conflict.
 */
bool CNF::hasConflict(void)
{
	return find_if(clauses.begin(), clauses.end(), bind(&Clause::isConflict, _1)) != clauses.end();
}

/*
 * Check whether the formula has a unit clause.
 */
Literal* CNF::hasUnit(void)
{
	Literal* result(nullptr);
	for (auto itr = clauses.begin();
	     itr != clauses.end();
	     itr++)
	{
		if (result = itr->isUnit())
			break;
	}
	return result;
}
} // End namespace SAT