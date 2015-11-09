/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __LITERAL_H
#define __LITERAL_H

namespace SAT
{
	class Literal 
	{
	public:
		enum class Polarity { Pos, Neg, Unassigned };

		Literal(int variable, Polarity pol);
		void assign_pos();
		void assign_neg();
		void unassign();
		bool isAssignedPos();
		bool isAssignedNeg();
		int getVariable();

	private:
		int var;
		Polarity pol;
	};
} // End namespace SAT
#endif // __LITERAL_H
