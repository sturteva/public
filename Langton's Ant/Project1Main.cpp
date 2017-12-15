/*******************************************************************************
**Program: Project 1 - CS162-400 Langton's Ant
**Author: Andrew P. Sturtevant
**Date: 05 July 2017
**Description: This will ask the user for the size of the board, along with the
**starting location of the ant. It will also ask for the number of steps it 
**should perform.  It will then perform a loop moving the ant that many times
*******************************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "Menus.cpp"
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{

	int row;
	int col; 
	int steps;
	int startX;
	int startY;

	while(simpleMenu() == 1)
	{
	cout <<  "Please select the number of rows you would like between 1-80 "
		 << endl;
	row = readIntRange(1,80);
	
	cout << "Please select the number of columns you would like between "
		<< "1-80:" << endl;
	col = readIntRange(1, 80);

	
	cout << "Your board will be: " << row << " x " << col << endl;	

	cout << "What X Position would you like the Ant to start on?"  << endl;
	startX = readIntRange(0,row-1);

	cout << "What Y Position would you like the Ant to start on?" << endl;
	startY = readIntRange(0,col-1);
	
	cout << "The Ant will start on (" << startX << "," << startY << ")" 
		<< endl; 
		   
	cout << "Please enter the number of steps you want the Ant to take: "
		<< endl;
	
	steps = readPosInt();
	
	//Ant myAnt(row,col,startX,startY);
	Ant* myAnt = new Ant( row, col, startX, startY); 
	
	cout << "Starting Board" << endl;

	myAnt->print();
 
	for(int i = 0; i < steps; ++i)
	{
		cout << "Move #: " << i+1 << endl;	

		myAnt->moveAnt();
		myAnt->print();
	}

	
	delete myAnt;

	}

 return 0;
}
