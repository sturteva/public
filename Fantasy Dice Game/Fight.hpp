/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 31 July 2017
**Description: This is the Fight class, it will have two creature objects,
**it will creature creatures to fight each other. It will also keep track of
**who is the winner and report it.
*******************************************************************************/

#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "Creature.hpp"

class Fight
{

	private:
		bool player1Win;
		bool player2Win;

	public:

		void attack(Creature*,Creature*,int);
		void fullAttack();
		void winner(Creature*,Creature*);

};
#endif  
