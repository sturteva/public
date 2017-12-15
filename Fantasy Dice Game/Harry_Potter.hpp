/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the Harry Potter class, a subclass of Creature. Please
**see Creature.hpp for a full class description.  Harry Potter comes back to
**lifewhen he is first killed, so the reduceStrengthPoint method will be 
**adjusted to accomodate that.
*******************************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Creature.hpp"

class Harry_Potter : public Creature
{

	private:
		bool death;
	
	public:
		Harry_Potter();
		~Harry_Potter();
		void reduceStrengthPoint(int);

};
#endif   
