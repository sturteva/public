/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the class intilization. Please see Space.hpp for full
**class description.
*******************************************************************************/

#include "Space.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Space::Space()
{
	toNorth = NULL;
	toEast = NULL;
	toSouth = NULL;
	toWest = NULL;
	resources = new Container();
	description = "This is an empty space";
	isCrash = false;
}

Space::~Space()
{
	delete resources;
	 toNorth = NULL;
        toEast = NULL;
        toSouth = NULL;
        toWest = NULL;
}

void Space::setNorth(Space* s)
{
	toNorth = s;
}

void Space::setEast(Space* s)
{
	toEast = s;
}

void Space::setSouth (Space* s)
{
	toSouth = s;
}

void Space::setWest (Space* s)
{
	toWest = s;
}

Space* Space::getNorth()
{
	if(toNorth == NULL)
		return 0;
	else
		return toNorth;
}

Space* Space::getEast()
{
	if(toEast == NULL)
		return 0;
	else
		return toEast;
}

Space* Space::getSouth()
{
	if(toSouth == NULL)
		return 0;
	else
		return toSouth;
}

Space* Space::getWest()
{
	if(toWest == NULL)
		return 0;
	else
		return toWest;
}

Container* Space::getResources()
{
	return resources;
}

string Space::getDescription()
{
	return description;
}

void Space::setCrash()
{
	isCrash = true;
}

bool Space::getCrash()
{
	return isCrash;
}

void Space::inDistance()
{

	cout << "To the North you see...";
	if(toNorth == NULL)
	{
		cout <<"Nothing, the mysterious wall blocks your sight." 
			<< endl;    	 
	}

	else
	{
		cout << toNorth->getType() << endl;
		if(toNorth->getCrash())
		cout << "You also see your crash site." << endl;
	}

	cout << "To the East you see...";
        if(toEast == NULL)
        {
                cout <<"Nothing, the mysterious wall blocks your sight."
                        << endl;
        }

        else
        {
                cout << toEast->getType() << endl;
                if(toEast->getCrash())
                        cout << "You also see your crash site." << endl;
 	}
	cout << "To the South you see...";
        if(toSouth == NULL)
        {
                cout <<"Nothing, the mysterious wall blocks your sight."
                        << endl;
        }

        else
        {
                cout << toSouth->getType() << endl;
                if(toSouth->getCrash())
                        cout << "You also see your crash site." << endl;
	}
	cout << "To the West you see...";
        if(toWest == NULL)
        {
                cout <<"Nothing, the mysterious wall blocks your sight."
                        << endl;
        }

        else
        {
                cout << toWest->getType() << endl;
                if(toWest->getCrash())
                        cout << "You also see your crash site." << endl;
	}
}

bool Space::getPrayed()
{
	return false;
}
