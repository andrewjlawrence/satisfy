/*
* Copyright 2016 Andrew Lawrence
*/
#ifndef __PREPROCESSOR_H
#define __PREPROCESSOR_H

#include <string>
#include <memory>

using std::shared_ptr;
using std::string;

// Forward declaration
namespace SAT 
{
	class CNF;
	class Model;
}

namespace preprocessor
{
	class Preprocessor {
	public:
		Preprocessor(void);
		void process(shared_ptr<SAT::CNF>& formula, shared_ptr<SAT::Model>& SatisfyingAssignment);
	private: 
		void sortClauses(shared_ptr<SAT::CNF>& formula);
		void removeTrivialClauses(shared_ptr<SAT::CNF>& formula, shared_ptr<SAT::Model>& SatisfyingAssignment);
		void removePureLiterals(shared_ptr<SAT::CNF>& formula, shared_ptr<SAT::Model>& SatisfyingAssignment);
	};

} // end namespace preprocessor
#endif // End __Preprocessor_H
