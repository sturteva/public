/*******************************************************************************
**Program: Cs162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the class intilizaiton. See Mountain.hpp for full details
*******************************************************************************/

#include "Mountain.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Mountain::Mountain():Space()
{
	description = "Beutiful mountains all around you";
	resources->changeItem(1,"Flint");
	prayed = false;
}  

string Mountain::getType()
{
	return "a Mountain";
}

void Mountain::specialAction()
{
	cout << "You have chosen to pray to the god or gods of your choice" 
		<< " for the storm to be delayed." << endl;
	
	if(!prayed)
	{
		cout << "Your prayers have been heard, you have 2 additional"
			<< " hours, after 30 minutes of prayer." << endl;
		prayed = true;
	}

	else
		cout << "You have already prayed on this mountain." << endl;  
	 	
}

bool Mountain::getPrayed()
{
	return prayed;
} 
