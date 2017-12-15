/*******************************************************************************
**Program:CS162-400 Project 3
**Author:Anderw P. Sturtevant
**Date: 30 July 2017
**Description: This is the Blue Men class. A subclass of Creature. Please see
**Creature.hpp for that full description.  Blue Men will have a difference in
**that as they lose strength points, their defense die also goes down.
**With that in mind, their reduceStrengthPoint method will need to be redfined.
*******************************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Creature.hpp"

class Blue_Men : public Creature
{

	private:
		bool eightOrLess;
		bool fourOrLess;
	
	public:
		Blue_Men();
		~Blue_Men();
		void reduceStrengthPoint(int);
};
#endif
  
