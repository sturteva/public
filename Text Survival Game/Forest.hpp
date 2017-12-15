/*******************************************************************************
**Program: CS162-400 Final Project 
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: The Forest class is a child class of Space.  It has a function
**that will return a string with the type it is.  See Space.hpp for a full
**description of the base class.
*******************************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

#include "Space.hpp"
#include <string>

using std::string;

class Forest : public Space
{

        public:
                Forest();
                string getType();
		void specialAction();
};
#endif

