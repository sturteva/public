/*******************************************************************************
**Program: CS 162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: The Mountain class is a child class of Space.  It has a function
**that will return a string with the type it is.  See Space.hpp for a full
**description of the base class.
*******************************************************************************/

#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "Space.hpp"
#include <string>

using std::string;

class Mountain : public Space
{

	private:
		bool prayed;
	public:
		Mountain();
		string getType();
		void specialAction();
		bool getPrayed();
		
};
#endif 
