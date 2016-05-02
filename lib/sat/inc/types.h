/*
* Copyright 2015 Andrew Lawrence
*/
#ifndef __SAT_TYPES_H
#define __SAT_TYPES_H

// STL includes
#include <vector>

namespace SAT
{
	namespace Type
	{
		// Alias defintions 
		using variable = uint16_t;
		using Assignment = std::pair<variable, bool>;
		using Model = std::vector<Assignment>;
	}
} // end namespace SAT
#endif // End __SAT_TYPES_H
