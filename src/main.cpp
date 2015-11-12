/*
 * Copyright 2015 Andrew Lawrence
 */

#include "boost/program_options.hpp" 

#include <iostream> 
#include <string>
#include <memory>
#include <parser.h>
#include <cnf.h>
#include <dpll.h>

namespace
{
	const size_t ERROR_IN_COMMAND_LINE = 1;
	const size_t SUCCESS = 0;
	const size_t ERROR_UNHANDLED_EXCEPTION = 2;

} // namespace 

// Using declarations
using std::string;

int main(int argc, char* argv[])
{
	try
	{
		/** Define and parse the program options
		*/
		namespace po = boost::program_options;
		po::options_description desc("Options");
		desc.add_options()
			("help", "Print help messages")
			("f", "The dimacs file name");

		po::variables_map vm;
		try
		{
			po::store(po::parse_command_line(argc, argv, desc),
				vm); // can throw 

					 /** --help option
					 */
			if (vm.count("help"))
			{
				std::cout << "Satisfy SAT solver" << std::endl
					<< desc << std::endl;
				return SUCCESS;
			}
			
			auto itr = vm.find("f");

			if (itr == vm.end())
			{
				throw string("Error No file name");
			}
	
			parsing::DimacsParser parser(itr->second.as<std::string>());
			std::shared_ptr<SAT::CNF> formulaptr;
			parser.load(formulaptr);
			SAT::DPLL solver;
			solver.solve(formulaptr);

			po::notify(vm); // throws on error, so do after help in case 
							// there are any problems 
		}
		catch (po::error& e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
			std::cerr << desc << std::endl;
			return ERROR_IN_COMMAND_LINE;
		}
		catch (string& sErr)
		{
			std::cerr << "ERROR: " << sErr << std::endl << std::endl;
			std::cerr << desc << std::endl;
			return ERROR_IN_COMMAND_LINE;
		}

		// application code here // 

	}
	catch (std::exception& e)
	{
		std::cerr << "Unhandled Exception reached the top of main: "
			<< e.what() << ", application will now exit" << std::endl;
		return ERROR_UNHANDLED_EXCEPTION;

	}

	return SUCCESS;

}// main