/*
 * Copyright 2015 Andrew Lawrence
 */

#include <decision.h>

using SAT::Type::Assignment;
using SAT::Type::variable;
using SAT::Type::Model;

namespace SAT
{
	Decision::Decision(Assignment& assignment)
		: assignment(assignment), flipped(false)
	{

	}

	bool Decision::flip()
	{
		if (!flipped)
		{
			assignment.second = !assignment.second;
			flipped = true;
			return true;
		}
		else
			return false;
	}

	variable Decision::getVariable()
	{
		return assignment.first;
	}

	bool Decision::getAssignment()
	{
		return assignment.second;
	}

	Type::Assignment Decision::getVarAssignment()
	{
		return assignment;
	}

	Model Decision::toModel(std::stack<Decision>& decisionStack)
	{
		Model model;
		
		while (!decisionStack.empty())
		{
			model.push_back(decisionStack.top().getVarAssignment());
			decisionStack.pop();
		}

		return model;
	}
}
 // End namespace SAT