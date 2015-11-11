#include "..\inc\parser.h"
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

	bool DimacsParser::load(shared_ptr<CNF>& formula)
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
							int literal(1);
							Clause clause;

							while (literal != 0)
							{
								streamline >> literal;
								if (formula)
									clause.addliteral(Literal(abs(literal), 0 < literal, Literal::Assignment::Unassigned));
							}

							formula->addclause(clause);
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

							formula = std::make_shared<CNF>(CNF(variableNumber, clauseNumber));

							headerRead = true;
						}
					}
				}
			}

			Success = true;
		}
		catch (const string& /*error*/)
		{

		}

		return Success;
	}

} // End namespace parsing