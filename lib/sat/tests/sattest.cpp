/*
 * Copyright 2015 Andrew Lawrence
 */
#include <boost/test/unit_test.hpp>
#include <cnf.h>
#include <dpll.h>
#include <memory>

using std::make_shared;
using std::shared_ptr;
using SAT::CNF;
using SAT::Clause;


BOOST_AUTO_TEST_SUITE(SAT_TESTS)

BOOST_AUTO_TEST_CASE(SAT_TEST) 
{

	/* p cnf 5 3
	 * 1 - 5 4 0
	 * - 1 5 3 4 0
	 * - 3 - 4 0
	 */

	CNF myCNF(5, 3);

}

BOOST_AUTO_TEST_SUITE_END()