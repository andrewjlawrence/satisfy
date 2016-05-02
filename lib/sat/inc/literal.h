/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __LITERAL_H
#define __LITERAL_H

#include <types.h>

namespace SAT
{
class Literal 
{
public:
	enum class Assignment { True, False, Unassigned };

	Literal(Type::variable variableNumber, bool isPos, Assignment pol);
	void assign_true(void);
	void assign_false(void);
	void unassign(void);
	bool isAssignedTrue(void) const;
	bool isUnassigned(void) const ;
	bool isAssignedFalse(void) const;
	Type::variable getVariable(void) const;
	bool getPolarity(void) const;
	bool operator==(const Literal& rhs) const;
	bool operator!=(const Literal& rhs) const;
private:
	Type::variable var;
	bool polarity;
	Assignment assignment;
};
} // End namespace SAT
#endif // __LITERAL_H
