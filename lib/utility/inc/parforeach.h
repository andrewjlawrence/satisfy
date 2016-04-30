/*
* Copyright 2016 Andrew Lawrence
*/
#ifndef __PARFOREACH_H
#define __PARFOREACH_H

#include <threadgroup.h>
#include <vector>

namespace parallel
{
template<class Iterator, class Fun> inline void foreach(Iterator beginitr, 
		                                                Iterator enditr, 
		                                                Fun function)
{
	threading::ThreadGroup threadgroup;
	for ( ;
		 beginitr != enditr;
		 beginitr++)
	{
		threadgroup.add(function, *beginitr);
	}
	threadgroup.joinall();
};
} // end namespace preprocessor
#endif // End __Preprocessor_H
