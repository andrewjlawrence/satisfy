/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __SAT_TYPES_H
#define __SAT_TYPES_H

#include <string>
#include <memory>
#include <map>
#include <vector>

using std::shared_ptr;
using std::string;

namespace SAT
{
	// Alias defintions 

	// We define a model to be a map from variables to booleans
	using variable = uint16_t;
	using Assignment = std::pair<variable, bool>;
	using Model = std::map<variable, bool>;

} // end namespace SAT
#endif // End __SAT_TYPES_H
