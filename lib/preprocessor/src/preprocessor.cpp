/*
* Copyright 2016 Andrew Lawrence
*/

#include <preprocessor.h>
#include <cnf.h>
#include <sat-types.h>
#include <algorithm>
#include <parforeach.h>
namespace preprocessor
{
	/* Constructor */
	Preprocessor::Preprocessor(void)
	{
	}

	/* Apply preprocessing to a formula */
	void Preprocessor::process()
	{
		sortClauses();
		removeTrivialClauses();
		removePureLiterals();
	}

	void Preprocessor::sortClauses()
	{
		parallel::foreach(context().formula.begin(), context().formula.end(),
			[](SAT::Clause& clause) {std::sort(clause.begin(), clause.end(),
				[](SAT::Literal& leftlit, SAT::Literal& rightlit) {return leftlit.getVariable() < rightlit.getVariable();});});
	}

	void Preprocessor::removeTrivialClauses()
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

	void Preprocessor::removePureLiterals()
	{

	}

} // End namespace preprocessor

