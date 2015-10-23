/*
 * Copyright 2015 Andrew Lawrence
 */
#include <boost/test/unit_test.hpp>
#include <cnf.h>
#include <parser.h>
#include <memory>

using std::make_shared;
using std::shared_ptr;
using SAT::CNF;
using SAT::Clause;


BOOST_AUTO_TEST_SUITE(DIMACS_PARSER_TESTS)

BOOST_AUTO_TEST_CASE(DIMACS_PARSER_TEST) 
{
	parsing::DimacsParser testParser("./tests/test.dimacs");
	
	shared_ptr<CNF> CNFptr = make_shared<CNF>(CNF(0,0));

	BOOST_CHECK(testParser.load(CNFptr));
	BOOST_REQUIRE(CNFptr != 0);
	vector<Clause> Clauses;
	CNFptr->getclauses(Clauses);
	BOOST_CHECK_EQUAL(Clauses.size(), 3);
}

BOOST_AUTO_TEST_SUITE_END()