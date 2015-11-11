/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>
#include <literal.h>
#include <sat-types.h>

using std::vector;

namespace SAT
{
	class Clause {
	public:
		void addliteral(Literal& literal);
		void assignVariableTrue(variable variableNumber);
		void unassignVariable(variable variableNumber);
		void assignVariableFalse(variable variableNumber);
		bool isSatisfied();
		bool isConflict();
		vector<Literal>::const_iterator cbegin() const;
		vector<Literal>::const_iterator cend() const;
	
	private:
		vector<Literal> literals;
	};
} // End namespace SAT
#endif
