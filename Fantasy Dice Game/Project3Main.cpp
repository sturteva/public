/*******************************************************************************
**Program: CS162-400 Projet 3
**Author: Andrew P. Sturtevant
**Date: 31 July 2017
**Description: This is the main method for Project 3. It will basically have the
**user start the game, and then creates a Fight and has the fight run the
**majority of the program.
*******************************************************************************/

#include "Fight.hpp"
#include "Menus.hpp"
#include <iomanip>

int main()
{
	Menus menu;

	while(menu.simpleMenu() == 1)
	{
		srand(time(NULL));

		Fight* theFight = new Fight();
		theFight->fullAttack();

		delete theFight;
	}
return 0;
}
		
	 
