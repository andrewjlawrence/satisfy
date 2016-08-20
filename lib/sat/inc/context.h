/*
* Copyright 2016 Andrew Lawrence
*/
#ifndef __SAT_CONTEXT_H
#define __SAT_CONTEXT_H

// STL includes
#include <set>

// SAT library includes
#include <cnf.h>
#include <decision.h>
#include <types.h>

using std::set;

namespace SAT
{
	//! \class A singleton class representing the SAT solver context.
	class Context
	{
	public:
		//! The formula being solved.
		CNF formula;
		//! The decision stack.
		DecisionStack valuation;
		//! The literals that occur in the formula.
		set<SAT::Literal> literals;
		// Accessor for the singleton context.
		Context& context(void);
	protected:
		/** \brief Protected constructor */
		Context(void);
	};
} // end namespace SAT
#endif // End __SAT_CONTEXT_H
