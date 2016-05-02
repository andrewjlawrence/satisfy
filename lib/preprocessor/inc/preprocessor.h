/*
* Copyright 2016 Andrew Lawrence
*/
#ifndef __PREPROCESSOR_H
#define __PREPROCESSOR_H

#include <string>
#include <memory>
#include <sat-context.h>

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
	class Preprocessor: public SAT::Context {
	public:
		Preprocessor(void);
		void process();
	private: 
		void sortClauses();
		void removeTrivialClauses();
		void removePureLiterals();
	};

} // end namespace preprocessor
#endif // End __Preprocessor_H
