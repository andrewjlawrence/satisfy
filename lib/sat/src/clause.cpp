/*
 * Copyright 2015 Andrew Lawrence
 */

#include <clause.h>
#include <algorithm>
#include <functional>

using std::find_if;
using std::bind;
using std::placeholders::_1;

namespace SAT
{
	void Clause::addliteral(Literal & literal)
	{
		literals.push_back(literal);
	}

	bool Clause::isSatisfied()
	{
		return find_if(literals.begin(), literals.end(), bind(&Literal::isAssignedPos, _1)) != literals.end();
	}
}
