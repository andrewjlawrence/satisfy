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
#include <types.h>
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
	
	/** \brief Constructor */
	CNF(void);

	/** \brief Add a clause to the formula.
	 *  \param clause The clause to add to the formula. */
	void addclause(Clause& clause);

	/* Iterator Accessors*/

	/** \brief Get the const iterator at the beginning of the literal set.*/
	vector<Clause>::const_iterator cbegin(void) const;	
	/** \brief Get the const iterator at the end of the literal set.*/
	vector<Clause>::const_iterator cend(void) const;
	/** \brief Get the iterator at the beginning of the literal set.*/
	vector<Clause>::iterator begin(void);
	/** \brief Get the iterator at the end of the literal set.*/
	vector<Clause>::iterator end(void);

	/** \brief Erase part of the formula. */
	void erase(vector<Clause>::iterator& begin, vector<Clause>::iterator& end);

	/* I dont think we should be passing the formula around */
	void getclauses(vector<Clause>& outClauses);
	
	/** \brief Get the number of variables in the formula */
	uint16_t getVariableNumber(void);
	
	/** \brief Set the variable number */
	void setVariableNumber(uint16_t variableNumber);

	/** \brief Set the clause number */
	void setClauseNumber(uint16_t clauseNumber);

	/** \brief Assign a variable in the formula to true. */
	inline void assignVariableTrue(Type::variable variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), std::bind(&Clause::assignVariableTrue, std::placeholders::_1, variableNumber));
	}

	/** \brief Assign a variable in the formula to false. */
	inline void assignVariableFalse(Type::variable variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), std::bind(&Clause::assignVariableFalse, std::placeholders::_1, variableNumber));
	}

	/** \brief Unassign a variable in the formula. */
	inline void unassignVariable(Type::variable variableNumber)
	{
		for_each(clauses.begin(), clauses.end(), std::bind(&Clause::unassignVariable, std::placeholders::_1, variableNumber));
	}
		
	/** \brief Check whether the formula contains a conflict. */
	inline bool hasConflict(void)
	{
		return find_if(clauses.begin(), clauses.end(), std::bind(&Clause::isConflict, std::placeholders::_1)) != clauses.end();
	}

	/** \brief Check whether the forumla contains a unit clause. 
	 *  \return The literal contained in the first discovered unit clause, 
		        or nullptr if no such clause is found. */
	inline Literal* hasUnit(void)
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

private:
	vector<Clause> clauses;
	vector<Type::variable> unassignedVars;
	uint16_t clauseNumber; // This is going to be the maximum number of clauses
	uint16_t variableNumber; // This likely to be the maximum number of variables in a clause;
};
} // End namespace SAT
#endif // __CNF_H
