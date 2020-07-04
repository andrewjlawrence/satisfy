/*
 * Copyright 2015 Andrew Lawrence
 */

#include <decision.h>

using SAT::Type::Assignment;
using SAT::Type::variable;
using SAT::Type::Model;

namespace SAT
{
Decision::Decision(const Assignment& assignment, bool isBranch)
	: assignment(assignment), flipped(false), branch(isBranch)
{
}

/*
 * Flip the assignment of a decision
 */
bool Decision::flip(void)
{
	if (!flipped && branch)
	{
		assignment.second = !assignment.second;
		flipped = true;
		return true;
	}
	else
		return false;
}

/*
 * Accessor for the variable.
 */
variable Decision::getVariable(void)
{
	return assignment.first;
}

/*
 * Accessor for the assignment.
 */
bool Decision::getAssignment(void)
{
	return assignment.second;
}

/*
 * Check whether a decision has been propagated.
 */
bool Decision::isPropagated(void)
{
	return propagated;
}

/*
 * Check whether a decision is a branch.
 */
bool Decision::isBranch(void)
{
	return branch;
}

/*
 * Accessor for the assignment.
 */
Type::Assignment Decision::getVarAssignment(void)
{
	return assignment;
}

/*
 * Convert a decision stack to a model.
 */
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
} // End namespace SAT
