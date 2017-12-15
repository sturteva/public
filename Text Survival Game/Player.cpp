/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description:  This is the class intitialization, see Player.hpp for details.
*******************************************************************************/

#include "Player.hpp"
#include <string>
#include <iostream>
#include "Utility.hpp"

using std::string;
using std::cout;
using std::endl;

Player::Player()
{
	pockets = new Container();
	currentLocation = NULL;
	time = 5;
	pocket1 = false;
	pocket2 = false;
	fire = false;
}

Player::Player(Space* s)
{
	pockets = new Container();
	currentLocation = s;
	time = 5;
	pocket1 = false;
	pocket2 = false;
	fire = false;
}

Player::~Player()
{
	delete pockets;
}

double Player::getTime()
{
	return time;
}

bool Player::getPocket1()
{
	return pocket1;
}

bool Player::getPocket2()
{
	return pocket2;
}

bool Player::getFire()
{
	return fire;
}

Container* Player::getPockets()
{
	return pockets;
}

Space* Player::getCurrentLocation()
{
	return currentLocation;
}	

void Player::setPockets(Container* c)
{
	pockets = c;
}

void Player::setCurrentLocation(Space* s)
{
	currentLocation = s;
}

void Player::setTime(double t)
{
	time = t;
}

void Player::setPocket1(bool p)
{
	pocket1 = p;
}

void Player::setPocket2(bool p)
{
	pocket2 = p;
}

void Player::setFire(bool f)
{
	fire = f;
}

void Player::decreaseTime()
{
	time -= 0.5;
}

void Player::pickUpItem()
{
	cout << "Which item would you like to pick up?" << endl;
	currentLocation->getResources()->displayContainer();
	cout << "Or Press 3 to not pick up anything." << endl;  

	Utility myUtility;

	int itemSel = myUtility.readIntRange(1,3);

	if(itemSel < 3)
	{ 
	string tempItem = 
		currentLocation->getResources()->getItem(itemSel)->getName();
	

	if (tempItem == "Nothing")
	{
		cout << "Nothing has been added to your pockets" << endl;
	}
	else if(!pocket1)
	{
		pockets->changeItem(1,tempItem);
		currentLocation->getResources()->changeItem(itemSel,"Nothing");
		pocket1 = true;
		cout << tempItem << " has been added to your pockets" << endl; 
	}

	else if(!pocket2 )
	{
		pockets->changeItem(2, tempItem);
		currentLocation->getResources()->changeItem(itemSel,"Nothing");
		pocket2 = true;	    
		cout << tempItem << " has been added to your pockets" << endl;
	}

	else
	{
		cout << "Your pockets are full, you need to drop an item" 
			<< endl; 	
	}
	}

	
}

void Player::dropItem()
{
	cout << "Note:A dropped item is destroyed forever." << endl;
	cout << "Which item would you like to drop?" << endl;
	pockets->displayContainer();
	cout << "Or Press 3 to not drop anything." << endl;
	

	Utility myUtility;
	
	int dropSelection = myUtility.readIntRange(1,3);

	if(dropSelection != 3)
	{
		pockets->changeItem(dropSelection,"Nothing");
	
		if(dropSelection == 1)
			pocket1 = false;
		else
			pocket2 = false;
	}
}

void Player::travel(int direction)	 	
{
	Space* travelDirection = NULL;

	if(direction == 1)
	{
		travelDirection = currentLocation->getNorth();
	}

	else if(direction == 2)
	{
		travelDirection = currentLocation->getEast();
	}

	else if(direction == 3)
	{
		travelDirection = currentLocation->getSouth();
	}
	
	else if(direction == 4)
	{
		travelDirection = currentLocation->getWest();
	}

	if(travelDirection != 0)
	{
		currentLocation = travelDirection;
		decreaseTime();
		
		cout << "You have arrived at " << currentLocation->getType()
			<< endl;	
	}

	else
	{
		cout << "You tried climbing the wall unsuccessfully" 
			<< " wasting a half hour." << endl;
		decreaseTime();
	}
}

void Player::startFire()
{
	if(currentLocation->getCrash())
	{
		string item1 = pockets->getItem(1)->getName();
		string item2 = pockets->getItem(2)->getName();

		if((item1 == "Flint" && item2 == "Wood") ||
			(item1 == "Wood" && item2 == "Flint"))
		{
			decreaseTime();
			cout << "A fire has been started!" << endl;
			fire = true;
		}

		else if(item1 == "Wood" && item2 == "Wood")
		{
			decreaseTime();
			decreaseTime();
			cout << "A fire has been started!" << endl;
			fire = true;
		}

		else
		{
			cout << "You do not have the resources to start a "
				<< "fire. You need 2 wood or 1 wood and a "
				<< "flint." << endl;
		}
	
	}

	else
	{
		cout << "You do not have the crash site to provide shelter,"
			<< " you need to find the crash site." << endl;
	}
				
}

string Player::getCurrentDescription()
{
	return currentLocation->getDescription();
}

void Player::survey()
{
	currentLocation->inDistance();
}

void Player::getPocketContents()
{
	pockets->displayContainer();
}

void Player::doSpecial()
{
	decreaseTime();
	if(currentLocation->getType() == "a Mountain")
	{
		cout << "Got here" << endl;
		if(!currentLocation->getPrayed())
		{
			cout << "Got here too" << endl;
			time += 2;
			currentLocation->specialAction();
		}

		else		
			currentLocation->specialAction();
	}

	else
	{
		currentLocation->specialAction();
	}
}	
