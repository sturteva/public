/*******************************************************************************
**Program: Project 1 - CS 162-400 Langton's Ant
**Author: Andrew P. Sturtevant
**Date: 05 July 2017
**Description: This Ant class will do most of the direct manipulation of a 2D 
**array that will be decided by the user both the height and width of the board.
**The board will also keep track of where the ant is and whether the board 
**space is white or black.  
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

//These enumartors will keep track of both the direction and the color of the
//square the ant is on.
enum Direction {NORTH, EAST, SOUTH, WEST};


class Ant
{

	private:
		Direction currentDir;
		int currentX;
		int currentY;
		int rowSize;
		int colSize;
		bool isWhite;	
		char** boardArray;
		void turnRight();
		void turnLeft();
	

	public:    		
		Ant(int,int,int,int);
		~Ant();
		void moveAnt();
		void print();	
		void endAnt();	
};
#endif     
