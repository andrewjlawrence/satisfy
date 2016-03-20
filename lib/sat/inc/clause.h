/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>
#include <literal.h>
#include <sat-types.h>

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

	void assignVariableTrue(Type::variable variableNumber);
	void unassignVariable(Type::variable variableNumber);
	void assignVariableFalse(Type::variable variableNumber);
	bool isConflict(void);
	Literal* isUnit(void);
	vector<Literal>::const_iterator cbegin(void) const;
	vector<Literal>::const_iterator cend(void) const;
	
private:
	vector<Literal> literals;
	uint16_t unassignedLiterals;
	uint16_t trueLiterals;
	uint16_t falseLiterals;
};
} // End namespace SAT
#endif
