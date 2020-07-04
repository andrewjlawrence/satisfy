#include "parser.h"
/*
 * Copyright 2015 Andrew Lawrence
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <clause.h>
#include <cnf.h>
#include <stdlib.h>

using std::shared_ptr;
using std::ifstream;
using std::string;
using std::stringstream;
using SAT::CNF;
using SAT::Literal;
using SAT::Clause;

namespace parsing
{
	DimacsParser::DimacsParser(const string & inpath)
		:path(inpath)
	{
	}

	bool DimacsParser::load()
	{
		bool Success(false);

		ifstream dimacsFile;
		dimacsFile.open(path, ifstream::in);
		try 
		{
			if (dimacsFile.is_open())
			{
				bool headerRead(false);
				uint16_t clauseNumber(0);
				uint16_t variableNumber(0);
				string line("");

				while (std::getline(dimacsFile, line))
				{
					// If the line is a comment ignore it
					// otherwise do something with it
					if (line.at(0) != 'c')
					{
						stringstream streamline(line);
						// The first non comment line should be the header
						if (headerRead)
						{
							// We are going to be parsing negative values.
							int literal(1);
							Clause clause;

							while (literal != 0)
							{
								streamline >> literal;
								if (literal != 0)
								{
									Literal newLit(abs(literal), 0 < literal, Literal::Assignment::Unassigned);
									clause.addliteral(newLit);
									context().literals.insert(newLit);
								}
							}

							context().formula.addclause(clause);
						}
						else
						{
							// The header is of the form p cnf x y 
							// where x is the number of variables
							// and y is the number of clauses
							streamline >> line;
							if (line != "p")
							{
								throw string("Invalid header");
							}

							streamline >> line;
							if (line != "cnf")
							{
								throw string("Invalid header");
							}

							streamline >> variableNumber;
							streamline >> clauseNumber;

							context().formula.setVariableNumber(variableNumber);
							context().formula.setClauseNumber(clauseNumber);

							headerRead = true;
						}
					}
				}
				Success = true;
			}
		}
		catch (const string& /*error*/)
		{

		}

		return Success;
	}

} // End namespace parsing
