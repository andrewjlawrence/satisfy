/*
 * Copyright 2016 Andrew Lawrence
 */

#include <threadgroup.h>

namespace threading
{
	void ThreadGroup::joinall(void)
	{
		for (auto& thread : group)
		{
			if (thread.joinable())
				thread.join();
		}
	}
} // End namespace threading