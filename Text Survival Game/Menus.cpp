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
//version is made for CS162-400 Final Project  assignment. 
int Menus::multiMenu()
{
	

	int input;
	
	cout << "******************Select an Action******************" << endl;
	cout << "Current Location Description: Press 1" << endl;
	cout << "Survey nearby locations: Press 2" << endl;
	cout << "Check location for resources: Press 3" << endl;
	cout << "Pick up the resource: Press 4" << endl;
	cout << "Drop a resource: Press 5" << endl; 
	cout << "Check your pockets: Press 6" << endl;
	cout << "Check Time remaining: Press 7" << endl; 
	cout << "Travel to a new location: Press 8" << endl;
	cout << "Perform Location's Special Action: Press 9" << endl;
	cout << "Attempt to start a fire: Press 10" << endl;

	cout << "Quit Game: Press 11" << endl;

	input = myUtility->readIntRange(1,11);

	return input;
}		  	 	  

int Menus::travelMenu()
{
	int input;
	
	cout << "***************Select a Direction********************" << endl;
	cout << "North: Press 1" << endl;
	cout << "East: Press 2" << endl;
	cout << "South: Press 3" << endl;
	cout << "West: Press 4" << endl;
	cout << "No Travel: Press 5" << endl;

	input = myUtility->readIntRange(1,5);
	return input;
} 
