/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: Class intilization. See Container.hpp for full description.
*******************************************************************************/

#include "Container.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
Container::Container()
{
	theArray = new Item*[2]; 
	theArray[0] = new Item;
	theArray[1] = new Item;
	
}	  

Container::~Container()
{
	delete theArray[0];
	delete theArray[1];
	delete [] theArray;
}

void Container::displayContainer()
{
	cout << "1: " << theArray[0]->getName() << endl;
	cout << "2: " << theArray[1]->getName() << endl;
}

void Container::changeItem(int n, string s)
{
	theArray[n-1]->setName(s);
}

Item* Container::getItem(int n)
{
	return theArray[n-1];
}

	
