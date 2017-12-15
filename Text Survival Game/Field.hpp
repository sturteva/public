/*******************************************************************************
Program: CS162-400  Final Project
Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: The Field class is a child class of Space.  It has a function
**that will return a string with the type it is.  See Space.hpp for a full
**description of the base class.
*******************************************************************************/

#ifndef FIELD_HPP
#define FIELD_HPP

#include "Space.hpp"
#include <string>

using std::string;

class Field : public Space
{

        public:
                Field();
                string getType();
		void specialAction();
};
#endif

