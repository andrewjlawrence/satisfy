/*
 * Copyright 2015 Andrew Lawrence
 */

#include <memory>
#include <clause.h>
#include <cnf.h>
#include <dpll.h>
#include <map>
#include <vector>


using std::map;
using std::vector;
using std::shared_ptr;

namespace 
{
	vector<uint16_t> generateorder(uint16_t variableNumber)
	{
		vector<uint16_t> result;
		for (int i = 1;
		     i < variableNumber;
		     i++)
		{
			result.push_back(i);
		}
		
		 return result;
	}
}


namespace SAT
{
	DPLL::DPLL()
	{
	}

	bool DPLL::solve(shared_ptr<CNF>& formula)
	{
		if (formula)
		{
			vector<uint16_t> order = generateorder(formula->getVariableNumber());
			map<uint16_t, bool> valuation;

			for (vector<uint16_t>::const_iterator itr = order.begin();
			     itr != order.end();
			     )
			{
				// Case variable has yet to be assigned;
				map<uint16_t, bool>::const_iterator itr2 = valuation.find(*itr);
				if (itr2 == valuation.end())
				{
					valuation.insert(std::pair<uint16_t, bool>(*itr, true));
					formula->assignVariable(*itr, true);
					itr++;
				}
				else
				{
					if (itr2->second == true)
					{
						valuation.insert(std::pair<uint16_t, bool>(*itr, false));
						itr++;
					}
					else
					{
						if (itr == order.begin())
						{
							return false;
						}
						else
						{
							itr--;
						}
					}
				}
			}
		}
		return formula->isSatisfied();
	}
} // End namespace SAT