/*******************************************************************************
**Program: CS162-400
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the abstract class Space.  It will have a number of
**"child" classes that will be Spaces.  It will also have pointers to the other
**spaces around it, and able to report what it is "next" to the space.
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Container.hpp"
#include <string>

using std::string;

class Space
{
	protected:
		Space* toNorth;
		Space* toEast;
		Space* toSouth;
		Space* toWest;
		Container* resources;
		string description;
		bool isCrash;

	public:
		Space();
		virtual ~Space();
		void setNorth(Space*);
		void setEast(Space*);
		void setSouth(Space*);
		void setWest(Space*);
		Space* getNorth();
		Space* getEast();
		Space* getSouth();
		Space* getWest();
		virtual string getType() = 0;
		Container* getResources();
		string getDescription();
		void inDistance();
		bool getCrash();
		void setCrash();
		virtual void specialAction() = 0;
		virtual bool getPrayed();		
};
#endif 
