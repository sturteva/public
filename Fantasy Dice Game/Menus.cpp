/*******************************************************************************
**Program: Menu functions
**Author: Andrew P. Sturtevant
**Date: 06 July 2017
**Description: This library of functions will contain a multitude of different
**types of menus. To start it will have a very simple menu.
*******************************************************************************/
#include "Menus.hpp"
#include <iostream>
#include "Utility.hpp"

using std::cin;
using std::cout;
using std::endl;

Menus::Menus()
{
	myUtility = new Utility(); 
}

Menus::~Menus()
{
	delete myUtility;
}
//This simple menu basically just validates an integer choice of 1 or 2 and then
//passes it back to the main function.  The main function should use something
//like while(simpleMenu() == 1) to bring the user back to the menu after all
//of the body of the program has happened.  
int Menus::simpleMenu()
{

	int input;

	cout << "*****************STARTING MENU***********************" << endl;
	cout << "Play Game: Press 1 " << endl;
	cout << "Quit Game: Press 2" << endl;
	input = myUtility->readIntRange(1,2);
	
	return input;
}

//This menu is a template for a menu that needs multiple options. It should be
//updated for each unique program, as menu options will change.  This particular
//version is made for CS162-400 Project 3 assignment. 
int Menus::multiMenu()
{
	

	int input;
	
	cout << "******************Select a Creature******************" << endl;
	cout << "Vampire: Press 1" << endl;
	cout << "Barbarian: Press 2" << endl;
	cout << "Blue Men: Press 3" << endl;
	cout << "Medusa: Press 4" << endl;
	cout << "Harry Potter: Press 5" << endl; 

	input = myUtility->readIntRange(1,5);

	return input;
}		  	 	  
