/*
 * Copyright 2016 Andrew Lawrence
 */
#ifndef __UTILS_H
#define __UTILS_H

// STL includes
#include <assert.h>

#ifdef DEBUG_ASSERT
#define SATISFY_ASSERT(arg) assert(arg);
#else
#define SATISFY_ASSERT(arg)
#endif

namespace SAT
{
	namespace Utils
	{

	}//end namespace Utils
} // end namespace SAT
#endif // End __UTILS_H
