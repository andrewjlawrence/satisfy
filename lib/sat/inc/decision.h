/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __DECISION_H
#define __DECISION_H

// STL includes
#include <stack>

// Project includes
#include <sat-types.h>

namespace SAT
{
	class Decision
	{
	public:
		Decision(Type::Assignment& decision);
		bool flip();
		Type::variable getVariable();
		bool getAssignment();
		static Type::Model toModel(std::stack<Decision>& decisionStack);

	private:
		Type::Assignment decision;
		//! When the variable has been set the second time this flag is set.
		bool flipped; 
		//! This flag is set when the decision has been propagated.
		bool propagated;
	};

	//! We define a model to be a stack of decisions
	using DecisionStack = std::stack<Decision>;

} // End namespace SAT
#endif // __DECISION_H
