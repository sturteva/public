/*******************************************************************************
**Program: Project 1 - CS162-400 Langton's Ant
**Author: Andrew P. Sturtevant
**Date: 05 July 2017
**Description: This is the class intitilization of the Ant class, see the header
**file for a full description of the class
*******************************************************************************/

#include "Ant.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


//This constructor takes 4 integers, makes the 2D array of characters, and 
//also places the ant in its starting location, pointing North and setting
//the currentSqColor to whie. 
Ant::Ant(int row, int col, int x, int y)
{
	currentX = x;
	currentY = y;
	rowSize = row;
	colSize = col;

	//dynamic allocatio of the 2D array
	boardArray = new char*[rowSize];
	for( int i = 0; i < rowSize; ++i)
	{
		boardArray[i] = new char[colSize];
	}

	//fills the Board with the white square symbol "_"
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			boardArray[i][j] = '_';
		}
	}

	boardArray[currentX][currentY] = '@';

	currentDir = NORTH;
	isWhite = true; 
}   


//This method simply prints the board. 
void Ant::print()
{
		
	for (int row = 0; row < rowSize; row++)
	{
		for( int col = 0; col < colSize; col++)
		{
			cout << boardArray[col][row];
		}
		cout << endl;
	}
}

void Ant::turnRight()
{
	if(currentDir == NORTH)
	{
		boardArray[currentX][currentY] = '#';
		
		//This if/else checks to see if the ant is at the right edge
		//of the board, if it is, it wraps around to the other side. 
		if(currentX < rowSize-1)
		{
			currentX ++;
		}
		else
		{
			currentX = 0;
		}
	   
		//Checking the current color of the new square.
		if(boardArray[currentX][currentY] == '_')
		{
			isWhite = true;
		}
		else
		{
			isWhite = false; 
		}

		boardArray[currentX][currentY] = '@';
		currentDir = EAST;
		return;
	}

	if(currentDir == EAST)
	{
		boardArray[currentX][currentY] = '#';

		if(currentY < colSize - 1)
		{
			currentY++;
		}
		else
		{
			currentY = 0;
		}

		if(boardArray[currentX][currentY] == '_')
		{
			isWhite = true;
		}
		else
		{
			isWhite = false;
		}
		
		boardArray[currentX][currentY] = '@';
		currentDir = SOUTH;
		return;
	}

	if(currentDir == SOUTH)
	{

		boardArray[currentX][currentY] = '#';

		if(currentX > 0)
		{
			currentX--;
		}
		else
		{
			currentX = rowSize - 1;
		}

		if(boardArray[currentX][currentY] == '_')
		{
			isWhite = true;
		}
		else
		{
			isWhite = false;
 		}

		boardArray[currentX][currentY] = '@';
		currentDir = WEST;
		return;
	}

	if(currentDir == WEST)
	{
		boardArray[currentX][currentY] = '#';

		if(currentY > 0)
		{
			currentY--;
		}
		else
		{
			currentY = colSize - 1;
		}
	
		if(boardArray[currentX][currentY] == '_')
		{
			isWhite = true;
		}
		else
		{
			isWhite = false;
		}

		boardArray[currentX][currentY] = '@';
		currentDir = NORTH;
		return;
	}
}  		

void Ant::turnLeft()
{

	if(currentDir == NORTH)
	{
                boardArray[currentX][currentY] = '_';

                if(currentX > 0)
                {
                        currentX --;
                }
                else
                {
                        currentX = rowSize - 1;
                }

                //Checking the current color of the new square.
                if(boardArray[currentX][currentY] == '_')
                {
                   isWhite = true;
                }
                else
                {
                   isWhite = false;
                }
                
                boardArray[currentX][currentY] = '@';
		currentDir = WEST;
		return;                                                                                                                                                 }

   	if(currentDir == WEST)
        {
                boardArray[currentX][currentY] = '_';

                if(currentY < colSize - 1)
                {
                        currentY++;
                }
                else
                {
                        currentY = 0;
                }

      
                if(boardArray[currentX][currentY] == '_')
                {
                        isWhite = true;
                }
                else
                {
                        isWhite = false;
                }

                boardArray[currentX][currentY] = '@';
		currentDir = SOUTH;
		return;
        }

   	if(currentDir == SOUTH)
        {
                boardArray[currentX][currentY] = '_';

                if(currentX < rowSize - 1)
                {
                        currentX ++;
                }
                else
                {
                        currentX = 0;
                }

      
                if(boardArray[currentX][currentY] == '_')
                {
                        isWhite = true;
                }
                else
                {
                        isWhite = false;
                }

                boardArray[currentX][currentY] = '@';
		currentDir = EAST;
		return;
        }

   	if(currentDir == EAST)
        {
                boardArray[currentX][currentY] = '_';

                if(currentY > 0)
                {
                        currentY --;
                }
                else
                {
                        currentY = colSize - 1;
                }

      
                if(boardArray[currentX][currentY] == '_')
                {
                        isWhite = true;
                }
                else
                {
                        isWhite = false;
                }

                boardArray[currentX][currentY] = '@';
		currentDir = NORTH;
		return;
        }
}

//This function checks the color of the current square and then makes the 
//correct move. 
void Ant::moveAnt()
{
	if(isWhite)
	{
		turnRight();
	}
	else
	{
		turnLeft();
	}
return;	
}

//Simply frees the allocated memory
Ant::~Ant()
{
	for (int i = 0; i < rowSize; ++i)
	{
		delete [] boardArray[i];
	}
	delete 	[] boardArray;
return;
}

