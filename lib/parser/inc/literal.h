/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __LITERAL_H
#define __LITERAL_H

// Forward declaration

class Literal {
enum polarity {Pos, Neg, Unassigned};

public:
	Literal(int variable, polarity pol);
	void assign_pos();
	void assign_neg();
	void unassign();
private:
	int var;
	polarity pol;
};

#endif // __LITERAL_H
