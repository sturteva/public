/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the Player class.  A player will have a container of 
**pockets, keep track of the time remaining.  We will also have a few boolean
**variables to keep track of whehter anything is in the pockets.  Or if there
**is a fire that has been made. 
*******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"
#include "Container.hpp"

class Player
{

	private:
		Container* pockets;
		Space* currentLocation;
		double time;
		bool pocket1;
		bool pocket2;
		bool fire;

	public:
		Player();
		Player(Space*);
		~Player();
		Container* getPockets();
		Space* getCurrentLocation();
		double getTime();
		bool getPocket1();
		bool getPocket2();
		bool getFire();
		void setPockets(Container*);
		void setCurrentLocation(Space*);
		void setTime(double);
		void setPocket1(bool);
		void setPocket2(bool);
		void setFire(bool);
		void decreaseTime();
		void pickUpItem();
		void dropItem();		
		void travel(int);
		void startFire();
		string getCurrentDescription();
		void survey();
		void getPocketContents();
		void doSpecial();	
};	
#endif   
