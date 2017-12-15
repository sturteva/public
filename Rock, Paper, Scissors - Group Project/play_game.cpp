/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is main file. It contains the main function and
**		a menu function.
*******************************************************************************/
#include <iostream>
#include <string>
#include "Functions.hpp"
#include "RPSGame.hpp"

using namespace std;

#define PLAY_GAME 1
#define SHOW_STATISTICS 2
#define CLEAR_STATISTICS 3
#define QUIT 4

//Function prototypes
int mainMenu();

/*******************************************************************************
** Main function of the program.
*******************************************************************************/
int main()
{
	int userSelection = 0;
	RPSGame game;

	cout << endl;
	while (userSelection != QUIT)
	{		
		//Show menu and get for selection.
		userSelection = mainMenu();
		
		if (userSelection == PLAY_GAME)
		{
			cout << endl;
			game.playgame();
		}
		else if  (userSelection == SHOW_STATISTICS)
		{
			cout << "\n    GAME STATISTICS: " << endl;
			game.showStatistics();
		}
		else if  (userSelection == CLEAR_STATISTICS)
		{
			game.clearStatistics();
			cout << "\n    GAME STATISTICS: " << endl;
			game.showStatistics();
		}
		cout << endl << endl;
	}

	cout << "\nPress enter to continue ...";
	cin.get();
	return 0;
}

/*******************************************************************************
** Show user the main menu and ask for a selection. If user entered an invalid
** selection, display an error message and ask user to re-enter the selection.
** Return a valid selection as an integer from 1 to 4.
*******************************************************************************/
int mainMenu()
{
	string menuMsg;
	menuMsg = "ROCK-PAPER-SCISSORS GAME MENU\n"
			  "-----------------------------\n"
			  "    1. Play Game\n"
			  "    2. Show Game Statistics\n"
			  "    3. Clear Game Statistics\n"
			  "    4. Quit\n"
			  "\n"
			  "Please enter your selection: ";

	return getIntegerFromUser(menuMsg, PLAY_GAME, QUIT);
}

