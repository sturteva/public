/*******************************************************************************
**Program: Menu functions
**Author: Andrew P. Sturtevant
**Date: 31 July 2017
**Description: This library of function will contain a multitude of different
**types of menus. To start it will have a very simple menu.
*******************************************************************************/

#ifndef MENUS_HPP
#define MENUS_HPP
#include "Utility.hpp"

class Menus
{
	private:
		Utility* myUtility;

	public:
		Menus();
		~Menus();
		int simpleMenu();
		int multiMenu();
};
#endif

 
