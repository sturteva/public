/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the game class that will have the primary menu for the
**player to interact with.  It will be checking the time and the fire status
**and report once certain conditions are met.
*******************************************************************************/

#ifndef SURVIVAL_GAME_HPP
#define SURVIVAL_GAME_HPP

#include "Space.hpp"
#include "Mountain.hpp"
#include "Field.hpp"
#include "Forest.hpp"
#include "Player.hpp"
#include "Menus.hpp"


class Survival_Game
{

	private:
		Space** theMap;
		Player* player;
	public:
		Survival_Game();
		~Survival_Game();
		void startGame();
		void playGame();
};
#endif

 
 
