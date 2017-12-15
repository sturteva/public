/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the class intialization for Harry Potter. Please see
**Harry_Potter.hpp for a full description.
*******************************************************************************/

#include "Harry_Potter.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

Harry_Potter::Harry_Potter() : Creature()
{
	attackNumberDie = 2;
	attackDieSize = 6;
	defenseNumberDie = 2;
	defenseDieSize = 6;
	armor = 0;
	strengthPoints = 10;
	name = "Harry Potter";
	description = "Why are you reading this? How can you not know who";
	description += " Harry Potter is?";

	death = false;
}

Harry_Potter::~Harry_Potter() 
{}

void Harry_Potter::reduceStrengthPoint(int damage)
{

 	if((damage-armor) > 0)
        {
                damageDealt = damage - armor;
                strengthPoints = strengthPoints - damageDealt;

		if(strengthPoints <= 0 && !death)
		{
			cout << "Harry Potter died, and he has re-risen at"
				<< " Hogwarts with 20 strength points!" << endl;
			strengthPoints = 20;
			death = true;
		} 	
                return;
        }
        
	else
        {
                damageDealt = 0;
                return;
        }
}
