/*******************************************************************************
**Program: Menu functions
**Author: Andrew P. Sturtevant
**Date: 06 July 2017
**Description: This library of functions will contain a multitude of different
**types of menus. To start it will have a very simple menu.
*******************************************************************************/

#include <iostream>
#include "Utilities.cpp"

using std::cin;
using std::cout;
using std::endl;

//This simple menu basically just validates an integer choice of 1 or 2 and then
//passes it back to the main function.  The main function should use something
//like while(simpleMenu() == 1) to bring the user back to the menu after all
//of the body of the program has happened.  
int simpleMenu()
{
	int input;

	cout << "Start: Press 1" << endl;
	cout << "Quit: Press 2" << endl;
	input = readIntRange(1,2);
	
	return input;
} 	 	  
