/*******************************************************************************
**Program: CS162-400 Group Project (Paper/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**         Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the subclass Paper.  It's superclass is Tool.hpp. See
**Tool.hpp for that class description.  Paper will be simliar, however the
**fight(Tool) method will be made unique for Paper.
*******************************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"

class Paper : public Tool
{
	public:
		Paper();
		Paper(int);
		virtual ~Paper();
		double getStrength(Tool &) const;
};
#endif

