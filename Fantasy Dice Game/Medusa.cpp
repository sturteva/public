/******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the class intialization for Medusa. Please see Medusa.hpp
**for a full class description.
*******************************************************************************/

#include "Medusa.hpp"
#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;

Medusa::Medusa():Creature()
{
	attackNumberDie = 2;
	attackDieSize = 6;
	defenseNumberDie = 1;
	defenseDieSize = 6;
	armor = 3;
	strengthPoints = 8;
	name = "Medusa";
	description = "Scrawny lady with snakes for hair. They help with";
	description += " fighting. Just don’t look at her!";
}

Medusa::~Medusa()
{}

int Medusa::attack()
{
	 attackDamage =
                rand() % (attackNumberDie * attackDieSize) + attackNumberDie;

	if(attackDamage == 12)
	{
		cout << "The Medusa caught the enemies eyes with a Gaze and"
			<< " turned them to stone!" << endl;

		attackDamage = 9999;
		return attackDamage;
	}

	else
	{
		return attackDamage;
	}
} 

