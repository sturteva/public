/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 21 July 2017
**Description: This is the subclass Rock.  It's superclass is Tool.hpp. See
**Tool.hpp for that class description.  Rock will be simliar, however the 
**fight(Tool) method will be made unique for Rock.
*******************************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"

class Rock : public Tool
{
	public:
		Rock();
		Rock(int);
		virtual ~Rock();
		double getStrength(Tool &) const;
};
#endif 	 
