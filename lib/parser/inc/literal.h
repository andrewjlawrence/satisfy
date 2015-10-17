/*
 * Copyright 2015 Andrew Lawrence
 */
#ifndef __LITERAL_H
#define __LITERAL_H

namespace parsing
{
	class Literal {
		enum class Polarity { Pos, Neg, Unassigned };

	public:
		Literal(int variable, Polarity pol);
		void assign_pos();
		void assign_neg();
		void unassign();
	private:
		int var;
		Polarity pol;
	};
} // End namespace parsing
#endif // __LITERAL_H
