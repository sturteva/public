/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description. This is the Medusa class. It is a sub class of Creature. Please
**see Creature.hpp for that full description. The Medusa class will set some
**basic values, and also adjust the attack method to accomodate the Medusa's
**special Glare ability.
*******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa : public Creature
{

	public:
		Medusa();
		~Medusa();
		int attack();
};
#endif 
