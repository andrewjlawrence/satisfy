/*
* Copyright 2016 Andrew Lawrence
*/

#include <sat-context.h>

namespace SAT
{
/*
 * Accessor for singleton context.
 */
Context& Context::context(void)
{
	static Context c;
	return c;
}

/*
 * Protected constructor
 */
Context::Context(void)
{

}
} // end namespace SAT
