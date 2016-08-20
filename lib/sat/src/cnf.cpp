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

CNF::CNF(void)
	:variableNumber(0), clauseNumber(0)
{
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
vector<Clause>::const_iterator CNF::cbegin(void) const
{
	return clauses.cbegin();
}

/*
 * Get a const iteratore to the end of the CNF.
 */
vector<Clause>::const_iterator CNF::cend(void) const
{
	return clauses.cend();
}

vector<Clause>::iterator CNF::begin(void)
{
	return clauses.begin();
}

vector<Clause>::iterator CNF::end(void)
{
	return clauses.end();
}

void CNF::erase(vector<Clause>::iterator & begin, vector<Clause>::iterator & end)
{
	clauses.erase(begin, end);
}

/*
 * Get the clauses in the CNF.
 */
vector<Clause>& CNF::getclauses()
{
	return clauses;
}

const vector<Clause>& CNF::getclauses() const
{
	return clauses;
}

/*
 * Get the number of variable in the CNF.
 */
uint16_t CNF::getVariableNumber(void)
{
	return variableNumber;
}

void CNF::setVariableNumber(uint16_t newVariableNumber)
{
	variableNumber = newVariableNumber;
}

void CNF::setClauseNumber(uint16_t newClauseNumber)
{
	clauses.reserve(newClauseNumber);
	clauseNumber = newClauseNumber;
}

} // End namespace SAT