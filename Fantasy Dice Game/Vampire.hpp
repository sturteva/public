/*******************************************************************************
**Program:CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the Vampire class, which is a subclass of the Creature
**class. See Creature.hpp for that full description.  This class is basically
**the same, however it will define its own defend class to "charm" the enemy.
**The constructor will also assign some of the basic values.
*******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

class Vampire : public Creature
{

	public:
		Vampire();
		~Vampire();
		int defend();
};
#endif 
