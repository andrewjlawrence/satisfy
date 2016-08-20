/*
* Copyright 2016 Andrew Lawrence
*/

#include <preprocessor.h>
#include <cnf.h>
#include <types.h>
#include <algorithm>
#include <parforeach.h>
#include <set>

using std::set;

namespace preprocessor
{
	/* Constructor */
	Preprocessor::Preprocessor(void)
	{
	}

	/* Apply preprocessing to a formula */
	void Preprocessor::process(void)
	{
		sortClauses();
		removeTrivialClauses();
		removePureLiterals();
	}

	void Preprocessor::sortClauses(void)
	{
		parallel::foreach(context().formula.begin(), context().formula.end(),
			[](SAT::Clause& clause) {std::sort(clause.begin(), clause.end(),
				[](SAT::Literal& leftlit, SAT::Literal& rightlit) {return leftlit.getVariable() < rightlit.getVariable();});});
	}

	void Preprocessor::removeTrivialClauses(void)
	{
		SAT::CNF& formula(context().formula);
		formula.erase(std::remove_if(formula.begin(), formula.end(), [](SAT::Clause& clause) {
			for (auto itr = clause.begin();
				itr != clause.end();
				itr++)
			{
				if (itr + 1 != clause.end() && itr->getVariable() != (itr + 1)->getVariable())
					itr++;
				else
					return true;
			}
			return false;
		}
		), formula.end());
	}

	/*
	 * A literal is pure if it occurs in only one polarity in the entire formula.
	 * They can be set true and removed from the proof search as they do not affect satisfiability.
	 */
	void Preprocessor::removePureLiterals(void)
	{
		for (auto clause : context().formula.getclauses())
		{

		}

	}

} // End namespace preprocessor

