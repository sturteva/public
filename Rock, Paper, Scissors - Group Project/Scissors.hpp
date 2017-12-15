/*******************************************************************************
**Program: CS162-400 Group Project (Scissors/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**         Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the subclass Scissors.  It's superclass is Tool.hpp. See
**Tool.hpp for that class description.  Scissors will be simliar, however the
**fight(Tool) method will be made unique for Scissors.
*******************************************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"

class Scissors : public Tool
{
	public:
		Scissors();
		Scissors(int);
		virtual ~Scissors();
		double getStrength(Tool &) const;
};
#endif

