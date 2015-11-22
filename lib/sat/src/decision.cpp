/*
 * Copyright 2015 Andrew Lawrence
 */

#include <decision.h>

using SAT::Type::Assignment;
using SAT::Type::variable;
using SAT::Type::Model;

namespace SAT
{
	Decision::Decision(Assignment& decision)
		: decision(decision), flipped(false)
	{

	}

	bool Decision::flip()
	{
		if (!flipped)
		{
			decision.second = !decision.second;
			flipped = true;
			return true;
		}
		else
			return false;
	}

	variable Decision::getVariable()
	{
		return decision.first;
	}

	bool Decision::getAssignment()
	{
		return decision.second;
	}

	Model Decision::toModel(std::stack<Decision>& decisionStack)
	{
		return Model();
	}
}
 // End namespace SAT