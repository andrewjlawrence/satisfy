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
		bool isSatisfied();
	private:
		vector<Literal> literals;
		bool satisfied;
	};
} // End namespace parsing
#endif
