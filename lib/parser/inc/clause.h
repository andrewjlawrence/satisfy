/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>
#include <literal.h>

using std::vector;

namespace parsing
{
	class Clause {
	public:
		void addliteral(Literal& literal);
	private:
		vector<Literal> literals;
	};
} // End namespace parsing
#endif
