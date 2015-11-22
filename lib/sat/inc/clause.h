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
		void addliteral(Literal& literal);
		void assignVariableTrue(Type::variable variableNumber);
		void unassignVariable(Type::variable variableNumber);
		void assignVariableFalse(Type::variable variableNumber);
		bool isConflict();
		vector<Literal>::const_iterator cbegin() const;
		vector<Literal>::const_iterator cend() const;
	
	private:
		vector<Literal> literals;
	};
} // End namespace SAT
#endif
