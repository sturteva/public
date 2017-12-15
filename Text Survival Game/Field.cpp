/*******************************************************************************
**Program:CS 162-400 Final Project 
**CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the class intilizaiton. See Field.hpp for full details
*******************************************************************************/

#include "Field.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Field::Field():Space()
{
        description = "Beutiful field full of flowers all around you";
        resources->changeItem(1,"Flowers");
}

string Field::getType()
{
        return "a Field";
}

void Field::specialAction()
{
	cout << "You spend some time creating a crown of flowers. You may" 
		<< " pick it up if you wish" << endl;
	resources->changeItem(2,"Flower Crown");
}	
