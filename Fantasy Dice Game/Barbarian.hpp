/*******************************************************************************
**Program:CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the Barbarian class, a sub-class of Creature. Please
**see Creature.hpp for that full description.  The Barbarian class will 
**simply have a constructor that intializes many of the basic data members of
**the Creature class.
*******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian : public Creature
{
	public:
		Barbarian();
		~Barbarian();
};
#endif 
