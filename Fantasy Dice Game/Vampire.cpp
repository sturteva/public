/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the class intilization for the Vampire class. Please see
**Vampire.hpp for a full description.
*******************************************************************************/

#include "Vampire.hpp"
#include <iostream>
#include <string>
#include <iomanip>


using std::string;
using std::cout;
using std::endl;


Vampire::Vampire() 
{
	attackNumberDie = 1;
	attackDieSize = 12;
	defenseNumberDie = 1;
	defenseDieSize = 6;
	armor = 1;
	strengthPoints = 18;
	name = "Vampire";
	description = "Suave, debonair, but vicious and surpsingly resilient!";
	srand(time(NULL));
}

Vampire::~Vampire()
{}

int Vampire::defend()
{
	int randomDefend = rand() % 2;
	
	if(randomDefend == 0)
	{
		defenseDamage =
		 rand() % (defenseNumberDie* defenseDieSize) + defenseNumberDie;
		
		return defenseDamage;
	}

	else
	{
		defenseDamage = 9999;
		cout << "The vampire charmed the enemy, the Enemy"
			<< " will not attack!" << endl;	
		return defenseDamage;
	}
}
