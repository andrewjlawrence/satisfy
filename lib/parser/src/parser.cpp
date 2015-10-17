#include "..\inc\parser.h"
/*
 * Copyright 2015 Andrew Lawrence
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using std::ifstream;
using std::string;
using std::stringstream;

namespace
{
	bool parseDimacsHeader(const string& line)
	{

	}
}

namespace parsing
{
	DimacsParser::DimacsParser(string & inpath)
		:path(inpath)
	{
	}

	void DimacsParser::load(CNF & formula)
	{
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

						}
						{
							// The header is of the form p cnf x y 
							// where x is the number of variables
							// and y is the number of clauses
							streamline >> line;
							if (line != "p")
							{
								throw "Invalid header";
							}

							streamline >> line;
							if (line != "cnf")
							{
								throw "Invalid header";
							}

							streamline >> clauseNumber;
							streamline >> variableNumber;
							headerRead = true;
						}
					}
				}
			}
		}
		catch (const string& /*error*/)
		{

		}
	}

} // End namespace parsing