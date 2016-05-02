/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>
#include <literal.h>
#include <sat-types.h>
#include <utils.h>


// Using STL
using std::vector;

namespace SAT
{
class Clause {
public:
	/** \brief Constructor */
	Clause(void);

	/** \brief Add a literal to the clause */
	void addliteral(Literal& literal);

	/** \brief Assign a variable true. */
	inline void assignVariableTrue(Type::variable variableNumber)
	{
		// Really we would remove trivially satisfiable clauses that contain e.g. x and ¬x.
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr != literals.end())
		{
			if (itr->getPolarity())
			{
				itr->assign_true();
				trueLiterals++;
			}
			else
			{
				itr->assign_false();
				falseLiterals++;
			}
			unassignedLiterals--;
			(literals.size() == unassignedLiterals + falseLiterals + trueLiterals);
		}
	}
	
	/** \brief Unassign a variable */
	inline void unassignVariable(Type::variable variableNumber)
	{
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr != literals.end())
		{
			// The variable will have always either been assigned true or false.
			if (itr->isAssignedFalse())
				falseLiterals--;
			else
				trueLiterals--;

			unassignedLiterals++;
			SATISFY_ASSERT(literals.size() == unassignedLiterals + falseLiterals + trueLiterals);
			itr->unassign();
		}
	}

	/** \brief Assign a variable false */
	inline void assignVariableFalse(Type::variable variableNumber)
	{
		auto itr = find_if(literals.begin(), literals.end(), [variableNumber](Literal& lit) {return lit.getVariable() == variableNumber;});
		if (itr != literals.end())
		{
			if (!itr->getPolarity())
			{
				itr->assign_true();
				trueLiterals++;
			}
			else
			{
				itr->assign_false();
				falseLiterals++;
			}

			unassignedLiterals--;
			SATISFY_ASSERT(literals.size() == unassignedLiterals + falseLiterals + trueLiterals);
		}
	}

	/** \brief Check whether the clause is empty i.e. a conflict has occured*/
	bool isConflict(void);
	
	/** \brief Check whether a clause is unit */
	Literal* isUnit(void);

	/** Accessors for underlying iterators */
	vector<Literal>::const_iterator cbegin(void) const;
	vector<Literal>::const_iterator cend(void) const;
	vector<Literal>::iterator begin(void);
	vector<Literal>::iterator end(void);

private:
	vector<Literal> literals;
	uint16_t unassignedLiterals;
	uint16_t trueLiterals;
	uint16_t falseLiterals;
};
} // End namespace SAT
#endif
