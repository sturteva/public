/*******************************************************************************
**Program:CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: Class intilization for the Barbarian class. Please see 
**Barbarian.hpp for a full description.
*******************************************************************************/

#include "Barbarian.hpp"
#include <string>

using std::string;
 
Barbarian::Barbarian() : Creature()
{
	attackNumberDie = 2;
	attackDieSize = 6;
	defenseNumberDie = 2;
	defenseDieSize = 6;
	armor = 0;
	strengthPoints = 18;
	name = "Barbarian";
	description="Think Conan or Hercules from the movies.";

	description+= " Big sword,big muscles, bare torso.";
		
}

Barbarian::~Barbarian()
{}
  	 
