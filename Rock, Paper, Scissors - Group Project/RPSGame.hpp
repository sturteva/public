/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the RPSGame class header file.  It will have two data members
 * that are pointers to tool objects, setters for those pointers, and data members
 * to hold the score of the current game as well as strength attributes for each tool.
 * The class has functions to play a game, show win/loss/tie statistics,
 * and clear the statistics.
*******************************************************************************/


#ifndef RPSGAME_HPP
#define RPSGAME_HPP
#include "Tool.hpp"

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

class RPSGame {
public:
	RPSGame();
	~RPSGame();
	void playgame();
	void showStatistics();
	void clearStatistics();
	
private:
	//pointers to Tool objects for player tool and computer tool
	Tool* player1;
	Tool* computer;
	
	//method to set Tool for user controlled player
	void setPlayer1();
	
	//method to set Tool for computer
	void setComputer();
	
	//method to score round
	void scoreRound();
	
	//variables used for score calculation
	int playerWins;
	int compWins;
	int ties;
	int totalRound;

	int rockStrength;
	int paperStrength;
	int scissorsStrength;
};

#endif