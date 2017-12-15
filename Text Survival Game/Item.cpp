/*******************************************************************************
**Program:CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: Class intilization. See Item.hpp for full description.
*******************************************************************************/

#include "Item.hpp"
#include <string>

using std::string;

Item::Item()
{
	name = "Nothing";
}

Item::Item(string s)
{
	name = s;
}

Item::~Item()
{
}

string Item::getName()
{
	return name;
}

void Item::setName(string s)
{
	name = s;
}	
 
