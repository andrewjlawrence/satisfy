#ifndef __CLAUSE_H
#define __CLAUSE_H

// Forward declaration

class Clause;

//! Class for conjunctive normal form
class CNF {
public:
  addclase(Clause& clause);
  ostream& operator<<(ostream& lhs, const CNF& rhs) 
 private:
  vector<Clause>;
};

#endif // __CLAUSE_H
