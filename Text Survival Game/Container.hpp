/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This simple container object will have an array with two objects 
**It will be able to change the name of those items as needed.
*******************************************************************************/

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Item.hpp"
#include <string>

using std::string;

class Container
{
	private:
		Item** theArray;
	public:
		Container();
		~Container();
		void displayContainer();
		void changeItem(int, string);
		Item* getItem(int);			


};
#endif
