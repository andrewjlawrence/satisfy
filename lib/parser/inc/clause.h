/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __CLAUSE_H
#define __CLAUSE_H

#include <vector>

using std::vector;

// Forward declaration
class Literal;

class Clause {
public:
  void addliteral(Literal& literal);
private:
  vector<Literal> literals;
};


#endif
