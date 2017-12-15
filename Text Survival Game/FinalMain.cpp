/*******************************************************************************
**Program:CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the main method for the FInal Project.  All it does is
**creat the Survival Game object and has its opening menu to play the game 
**again until the user no longer wants to.
*******************************************************************************/

#include "Menus.hpp"
#include "Survival_Game.hpp"

int main()
{

	Menus menu;
	
	while(menu.simpleMenu() == 1)
	{
		Survival_Game game;

		game.startGame();
		game.playGame();
	}

return 0;
} 
