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

// Using STL 
using std::all_of;
using std::istream;
using std::vector;

namespace SAT
{
//! Class for conjunctive normal form (CNF) formulas
class CNF {
public:
	/** \brief Constructor 
	 *  \param variableNumber The number of variables in the formula.
	 *  \param clauseNumber The number of clauses in the formula. */
	CNF(uint16_t variableNumber, uint16_t clauseNumber);
	
	/** \brief Add a clause to the formula.
	 *  \param clause The clause to add to the formula. */
	void addclause(Clause& clause);

	/** \brief Get the const iterator at the beginning of the literal set.*/
	vector<Clause>::const_iterator cbegin(void);	
	/** \brief Get the const iterator at the end of the literal set.*/
	vector<Clause>::const_iterator cend(void);
	
	/** \brief Get the iterator at the beginning of the literal set.*/
	vector<Clause>::iterator begin(void);
	/** \brief Get the iterator at the end of the literal set.*/
	vector<Clause>::iterator end(void);

	void erase(vector<Clause>::iterator& begin, vector<Clause>::iterator& end);


	/*I dont think we should be passing the formula around */
	void getclauses(vector<Clause>& outClauses);
	
	/** \brief Get the number of variables in the formula */
	uint16_t getVariableNumber(void);
		
	void assignVariableTrue(Type::variable variableNumber);
	void assignVariableFalse(Type::variable variableNumber);
	void unassignVariable(Type::variable variableNumber);
		
	/** \brief Check whether the formula contains a conflict. */
	bool hasConflict(void);

	/** \brief Check whether the forumla contains a unit clause. 
	 *  \return The literal contained in the first discovered unit clause, 
		        or nullptr if no such clause is found. */
	Literal* hasUnit(void);

private:
	vector<Clause> clauses;
	vector<Type::variable> unassignedVars;
	uint16_t clauseNumber; // This is going to be the maximum number of clauses
	uint16_t variableNumber; // This likely to be the maximum number of variables in a clause;
};
} // End namespace SAT
#endif // __CNF_H
