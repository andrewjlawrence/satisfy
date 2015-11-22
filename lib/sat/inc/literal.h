/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __LITERAL_H
#define __LITERAL_H

#include <sat-types.h>

namespace SAT
{
	class Literal 
	{
	public:
		enum class Assignment { True, False, Unassigned };

		Literal(Type::variable variableNumber, bool isPos, Assignment pol);
		void assign_true();
		void assign_false();
		void unassign();
		bool isAssignedTrue() const;
		bool isUnassigned() const ;
		bool isAssignedFalse() const;
		Type::variable getVariable() const;
		bool getPolarity() const;

	private:
		Type::variable var;
		bool polarity;
		Assignment assignment;
	};
} // End namespace SAT
#endif // __LITERAL_H
