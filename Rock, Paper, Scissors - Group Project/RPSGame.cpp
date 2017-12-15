/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the RPSGame class source file. It contains setter functions
 * for various data members of the class outlined in RPSGame.hpp as well as functions
 * to play a game, show win/loss/tie statistics, and clear the statistics.
*******************************************************************************/


#include <iomanip>
#include <iostream>
#include "RPSGame.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"
#include "Functions.hpp"

using namespace std;

/*******************************************************************************
** Constructor for the RPSGame class. It initializes all necessary member
** variables.
*******************************************************************************/
RPSGame::RPSGame(){
	clearStatistics();
	player1 = NULL;
	computer = NULL;
	rockStrength = 1;
	paperStrength = 1;
	scissorsStrength = 1;
}

/*******************************************************************************
** Destructor for the RPSGame class. It deletes the member variables that were 
** dynamically allocated.
*******************************************************************************/
RPSGame::~RPSGame(){
	delete player1;
	delete computer;
}

/*******************************************************************************
** After game is created, play is called to start things in motion.
** It gives user an option to set the strength of the tools. For each
** round, it asks user for the tool to be played and generates a random
** tool for the computer. It plays the user's and the computer's tool against
** each other and report the result for the round. 
*******************************************************************************/
void RPSGame::playgame(){
	char answer;
	string msg;

	// Set strength here
	cout << "Would you like to set the strength of the tools?" << endl;
	answer = validAlpha('y', 'n');
	if (answer == 'y')
	{
		msg = "What would you like the strength of Rock to be?\n";
		rockStrength = getIntegerFromUser(msg, 1, 100);
	
		msg = "What would you like the strength of Paper to be?\n";
		paperStrength = getIntegerFromUser(msg, 1, 100);
		
		msg = "What would you like the strength of Scissors to be?\n";
		scissorsStrength = getIntegerFromUser(msg, 1, 100);
	}

    do
    {
		cout << "\nRound #" << totalRound + 1 << ":" << endl;
        setPlayer1();

		if (player1 != NULL)
		{
			setComputer();      
			scoreRound();
        
			cout << "GAME STATISTICS: " << endl;
			showStatistics();        
			cout << endl;
		}
    } while (player1 != NULL);
}	

/*******************************************************************************
** Ask user for the tool to be played and initialize an object of the selected tool.
*******************************************************************************/
void RPSGame::setPlayer1(){
	int userChoice = 0;
	string msg = "Which tool would you like use?\n"
				 "    1. Rock\n"	
				 "    2. Paper\n"
				 "    3. Scissors\n"			 
				 "    4. Exit\n"			 
				 "Please enter your selection: ";
	
	userChoice = getIntegerFromUser(msg, 1, 4);
    cout << endl;

	//Free object to avoid memory leak.
	delete player1;
    
    if (userChoice == ROCK)
    {
        player1 = new Rock(rockStrength);
        cout << "You chose Rock." << endl;
    }    
    else if (userChoice == PAPER)
    {
        player1 = new Paper(paperStrength);
        cout << "You chose Paper." << endl;
    }
    else if (userChoice == SCISSORS)
    {
        player1 = new Scissors(scissorsStrength);
        cout << "You chose Scissors." << endl;
    }
	else
	{
		player1 = NULL;
	}
}
	
/*******************************************************************************
** Set a random tool for the computer.
*******************************************************************************/
void RPSGame::setComputer(){
	//Computer's tool is now randomized. It will Rock 30% of the game, 
	// Paper 30% of the game, and Scissors 30% of the game.
	int randomInt;

	//Free object to avoid memory leak.
	delete computer;

	//Generate random number from 1 to 100.
	randomInt = getRandomInteger(1 , 3);

	if (randomInt == 1)
	{
		computer =  new Rock(rockStrength);
		cout << "Computer chose Rock." << endl;
	}
	else if (randomInt == 2)
	{
		computer =  new Paper(paperStrength);
		cout << "Computer chose Paper." << endl;
	}
	else
	{
		computer =  new Scissors(scissorsStrength);
		cout << "Computer chose Scissors." << endl;
	}	
}

/*******************************************************************************
** Compare and report the result of the round. 
*******************************************************************************/
void RPSGame::scoreRound(){
	cout << "Round result: ";

	int result = player1->fight(*computer);
	if (result== TIE)
    {
        ties++;
        cout << "No winner!" << endl;
    }    
    else if (result  == WIN)
    {
        playerWins++;
        cout << "You won!" << endl;
    }    
    else 
    {
        compWins++;
        cout << "You lost!" << endl;        
    }
    
	totalRound++;
	cout << endl;  
}	

/*******************************************************************************
** Clear all statistics of the game.
*******************************************************************************/
void RPSGame::clearStatistics() {
	playerWins = 0;
	compWins = 0;
	ties = 0;
	totalRound = 0;
}	

/*******************************************************************************
** Display the current statistics of the game.
*******************************************************************************/
void RPSGame::showStatistics() {
	const int FIRST_COL = 24;
	const int OTHER_COL = 10;
	cout << "                               WIN       TIE" << endl;
	cout << "                               ---       ---" << endl;

	cout << setw(FIRST_COL) << left << "    Computer:";
	cout << setw(OTHER_COL) << right << compWins;
	cout << setw(OTHER_COL) << right << ties << endl;

	cout << setw(FIRST_COL) << left << "    Player:";
	cout << setw(OTHER_COL) << right << playerWins;
	cout << setw(OTHER_COL) << right << ties << endl;
	cout << "    Number of games played: " << totalRound << endl;
}	

