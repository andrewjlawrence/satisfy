/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __DECISION_H
#define __DECISION_H

// STL includes
#include <stack>

// Project includes
#include <types.h>

namespace SAT
{
class Decision
{
public:
	/** \brief Constructor 
	 *  \param decision The decision 
	 *  \param flag indicating that this is a branch */
	Decision(Type::Assignment& decision, bool isBranch);

	/** \brief Flip the decision if its been flipped.
		*  \return true if the flip was successful, false otherwise. */
	bool flip(void);

	/** \brief Accessor method for the variable. */
	Type::variable getVariable(void);

	/** \brief Accessor for the assignment as a bool. */
	bool getAssignment(void);

	/** \brief Accessor for the propagated flag. */
	bool isPropagated(void);

	/** \brief Accessor for the branch flag. */
	bool isBranch(void);

	/** \brief Accessor for the assignment as an assignment type. */
	Type::Assignment getVarAssignment(void);

	/** \brief Static method to convert a decision stack into a model. */
	static Type::Model toModel(std::stack<Decision>& decisionStack);

private:
	Type::Assignment assignment;
	//! When the variable has been set the second time this flag is set.
	bool flipped; 
	//! This flag is set when the decision has been propagated.
	bool propagated;
	//! Flag indicating that the decision is a branch in the search.
	bool branch;
};
//! We define a model to be a stack of decisions
using DecisionStack = std::stack<Decision>;
} // End namespace SAT
#endif // __DECISION_H
