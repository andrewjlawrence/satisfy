/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>
#include <literal.h>

using std::vector;

namespace SAT
{
	class Clause {
	public:
		void addliteral(Literal& literal);
		void assignVariableTrue(uint16_t variableNumber);
		void unassignVariable(uint16_t variableNumber);
		void assignVariableFalse(uint16_t variableNumber);
		bool isSatisfied();
		bool isConflict();
	private:
		vector<Literal> literals;
	};
} // End namespace SAT
#endif
