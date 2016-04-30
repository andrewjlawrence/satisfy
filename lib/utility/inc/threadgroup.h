/*
* Copyright 2016 Andrew Lawrence
*/
#ifndef __THREADGROUP_H
#define __THREADGROUP_H

#include <thread>
#include <vector>
#include <functional>

namespace threading {
	class ThreadGroup
	{
		public:
		void joinall(void);
		template <class Func, class Arg1> void add(Func function, Arg1 arg)
		{
			group.emplace_back(function, arg);
		};

		private:
		std::vector<std::thread> group;
	};

} // end namespace threading
#endif // End __THREADGROUP_H
