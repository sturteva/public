/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the class intilization for the Blue Men. Please see
**Blue_Men.hpp for a full description.
*******************************************************************************/

#include "Blue_Men.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Blue_Men::Blue_Men() : Creature()
{

	attackNumberDie = 2;
	attackDieSize = 10;
	defenseNumberDie = 3;
	defenseDieSize = 6;
	armor = 3;
	strengthPoints = 12;
	name = "Blue Men";
	description = "They are small (6” tall), fast and tough.";

	description += " So they are hard to hit and can take some damage.";
	description += "As for the attack value, you can do a LOT of damage";
	description += "  when you can crawl inside the armor or clothing of";
	description += " your opponent.";

	eightOrLess = false;
	fourOrLess = false;
}

Blue_Men::~Blue_Men()
{}

void Blue_Men::reduceStrengthPoint(int damage)
{
	if((damage-armor) > 0)
	{
		damageDealt = damage - armor;
        	strengthPoints = strengthPoints - damageDealt;
		
		if(strengthPoints <= 8 && !eightOrLess)
		{
			cout << "The Blue Men Mob has gotten smaller" << endl;
			defenseNumberDie--;
			eightOrLess = true;
		}
		
		if(strengthPoints <= 4 && !fourOrLess)
		{

			cout << "The Blue Men Mob has gotten even smaller!"
				<< endl;
			defenseNumberDie--;         	
			
			fourOrLess = true;
		}

		return;
   	}
   	else
   	{
          	damageDealt = 0;
                return;
        }
} 	 
