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
	void Preprocessor::process(shared_ptr<SAT::CNF>& formula, shared_ptr<SAT::Model>& model)
	{
		sortClauses(formula);
		removeTrivialClauses(formula, model);
		removePureLiterals(formula, model);
	}

	void Preprocessor::sortClauses(shared_ptr<SAT::CNF>& formula)
	{
		parallel::foreach(formula->begin(), formula->end(),
			[](SAT::Clause& clause) {std::sort(clause.begin(), clause.end(),
				[](SAT::Literal& leftlit, SAT::Literal& rightlit) {return leftlit.getVariable() < rightlit.getVariable();});});
	}

	void Preprocessor::removeTrivialClauses(shared_ptr<SAT::CNF>& formula, shared_ptr<SAT::Model>& model)
	{
		formula->erase(std::remove_if(formula->begin(), formula->end(), [](SAT::Clause& clause) {
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
		), formula->end());
	}

	void Preprocessor::removePureLiterals(shared_ptr<SAT::CNF>& formula, shared_ptr<SAT::Model>& model)
	{

	}

} // End namespace preprocessor

