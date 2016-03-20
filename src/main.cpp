/*
 * Copyright 2015 Andrew Lawrence
 */


// STL includs
#include <iostream> 
#include <string>
#include <memory>
#include <algorithm>

// Boost includes
#include "boost/program_options.hpp" 

// Project includes
#include <parser.h>
#include <cnf.h>
#include <dpll.h>

// Using declarations
using std::string;
using std::shared_ptr;
using std::sort;

// Annonymous Namespace
namespace
{
	const size_t ERROR_IN_COMMAND_LINE = 1;
	const size_t SUCCESS = 0;
	const size_t ERROR_UNHANDLED_EXCEPTION = 2;

	string outputModel(shared_ptr<SAT::Type::Model>& model)
	{
		sort(model->begin(), model->end(), [](SAT::Type::Assignment& a, SAT::Type::Assignment& b) {return a.first < b.first;});
		std::ostringstream outmodel;
		if (model)
		{
			for (auto itr = model->begin();
			     itr != model->end();
				 itr++)
			{
				outmodel << "Variable: " << itr->first
					<< " -> " << itr->second << std::endl;
			}
		}

		return outmodel.str();
	}

} // End annonymous namespace 



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
			("input-file,f", po::value<string>(), "input file")
			;

		po::variables_map vm;
		try
		{
			po::store(po::parse_command_line(argc, argv, desc), vm); // can throw 
			notify(vm);
			// Display help if it was asked for.
			if (vm.count("help"))
			{
				std::cout << "Satisfy SAT solver" << std::endl
					<< desc << std::endl;
				return SUCCESS;
			}
			
			if (!vm.count("input-file"))
			{
				throw string("Error No file name");
			}
			string path(vm["input-file"].as<string>());
			parsing::DimacsParser parser(path);
			shared_ptr<SAT::CNF> formulaptr(0);
			shared_ptr<SAT::Type::Model> modelptr(0);

			// Attempt to load the formula.
			if (parser.load(formulaptr))
			{
				SAT::DPLL solver;
				if (solver.solve(formulaptr, modelptr))
				{
					// The formula is satisfiable
					std::cout << "Yes" << std::endl;
					if (modelptr)
					{
						std::cout << "Satisfying Assignment: " << std::endl
							<< outputModel(modelptr);
					}
				}
				else
				{
					// The formula is unsatisfiable
					std::cout << "No" << std::endl;
				}
			}
			else
			{
				std::cout << "Unable to load dimacs" << std::endl;
			}

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