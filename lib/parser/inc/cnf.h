/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>
#include <iostream>

using std::ostream;
using std::vector;

// Forward declaration
class Clause;

//! Class for conjunctive normal form
class CNF {
public:
  void addclause(Clause& clause);
  ostream& operator<<(const CNF& rhs);
 private:
  vector<Clause> clauses;
};

#endif // __CLAUSE_H
