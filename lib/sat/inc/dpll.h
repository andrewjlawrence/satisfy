/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __DPLL_H
#define __DPLL_H

#include <string>
#include <memory>
#include <map>
#include <vector>
#include <sat-types.h>
#include <decision.h>
#include <sat-context.h>

// Using STL
using std::shared_ptr;
using std::string;

namespace SAT
{
// Forward declarations
class CNF;

class DPLL: public Context {
public:
	DPLL(void);
	/** \brief Perform boolean constraint propagation. */
	void bcp();

	/** \brief Make a decision. */
	Type::variable decide();

	/** \brief Resolve a conflict. */
	bool resolveConflict();

	/** \brief Solve a CNF formula.
	 *  \return A model of the formula in the case that a satisfying assignment is found, false otherwise. */
	shared_ptr<SAT::Type::Model>& solve(void);
};
} // end namespace SAT
#endif // End __DPLL_H
