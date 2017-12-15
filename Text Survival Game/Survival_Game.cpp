/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the class initialization. See Survival_Game.hpp for the 
**full details
*******************************************************************************/

#include "Survival_Game.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

Survival_Game::Survival_Game()
{
	srand(time(NULL));

	theMap = new Space*[9];
	int numMount = 0;
	int numField = 0;
	for( int i = 0; i<9; ++i)
	{
		int select = rand() % 3 + 1;
				 	
		if(select == 1 && numMount < 4)
		{
			theMap[i] = new Mountain;
			numMount++;
		}
		else if(select == 2 && numField < 4)
		{
			theMap[i] = new Field;
			numField++;
		}

		else 
		{
			theMap[i] = new Forest;
		} 
	}

	//The following sets up the links between all pieces that it is 
	//cardinally adjacent to.
	
	//0 1 2
	//3 4 5
	//6 7 8 

	//Space 1's adjacent 
	theMap[0]->setEast(theMap[1]);
	theMap[0]->setSouth(theMap[3]);

	//Space 2's adjacent
	theMap[1]->setEast(theMap[2]);
	theMap[1]->setSouth(theMap[4]);
	theMap[1]->setWest(theMap[0]);

	//Space 3's adjacent
	theMap[2]->setSouth(theMap[5]);
	theMap[2]->setWest(theMap[1]);

	//Space 4's adjacent
	theMap[3]->setNorth(theMap[0]);
	theMap[3]->setEast(theMap[4]);
	theMap[3]->setSouth(theMap[6]);

	//Space 5's adjacent
	theMap[4]->setNorth(theMap[1]);
	theMap[4]->setEast(theMap[5]);
	theMap[4]->setSouth(theMap[7]);
	theMap[4]->setWest(theMap[3]);

	//Space 6's adjacent
	theMap[5]->setNorth(theMap[2]);
	theMap[5]->setSouth(theMap[8]);
	theMap[5]->setWest(theMap[4]);

	//Space 7's adjacent						
	theMap[6]->setNorth(theMap[3]);
	theMap[6]->setEast(theMap[7]);
	
	//Space 8's adjacent
	theMap[7]->setNorth(theMap[4]);
	theMap[7]->setEast(theMap[8]);
	theMap[7]->setWest(theMap[6]);

	//Space 9's adjacent
	theMap[8]->setNorth(theMap[5]);
	theMap[8]->setWest(theMap[7]);

	int startLocation = rand() % 8;

        player = new Player(theMap[startLocation]);
        player->getCurrentLocation()->setCrash();

	
}

Survival_Game::~Survival_Game()
{

	for (int i = 0; i<9; ++i)
	{
		delete theMap[i];
	}

	delete [] theMap;
	delete player;
}

void Survival_Game::startGame()
{

//	int startLocation = rand % 8;

//	player->setCurrentLocation(theMap[startLocation]);
//	player->getCurrentLocation()->setCrash();

	cout << "You have crashed in a mysterious walled complex that has"
		<< " moutains, forests and fields.  Based on the last weather"
		<< " reports you know that a freak blizzard"
		<<" is coming in 5 hours. All you have is your knife."<< endl;

	cout <<"Use that time to collect 2 wood to start a fire or to make"
		<< " it a quicker process, get 1 piece of wood and a piece of"
		<< " flint from the mountains." << endl;

	cout <<"Once that is done, get back to the crash site to use it as"
		<<" shelter for you and your fire." << endl; 

	cout <<"It takes 30 minutes to travel to a new spot." << endl; 

}

void Survival_Game::playGame()
{
	Menus menu; 

	
	while(!player->getFire() && player->getTime() > 0)

	{ 
		int choice = menu.multiMenu();

		if(choice == 1)
		{
			cout << player->getCurrentDescription() << endl;
		}

		else if(choice == 2)
		{
			player->survey();
		}

		else if(choice == 3)
		{
			player->getCurrentLocation()->
				getResources()->displayContainer();
		}

		else if(choice == 4)
		{
			player->pickUpItem();
		}

		else if(choice == 5)
		{
			player->dropItem();
		}

		else if(choice == 6)
		{
			player->getPocketContents();
		}

		else if(choice == 7)
		{
			cout << "There are " << player->getTime()
				<< " hours before the blizzard hits." << endl;
		}

		else if(choice == 8)
		{
			int travel = menu.travelMenu();

			if(travel < 5)
			{	
				player->travel(travel);
			}
		}

		else if(choice == 10)
		{
			player->startFire();
		}

		else if(choice == 9)
		{
			player->doSpecial();
		}
		
		else 
			break;
			
	}

	if(player->getFire() && player->getTime() >= 0)
	{
		cout << "You survived the blizzard and might survive"  
			<< " until you are rescued...." << endl;
	}

	else
	{

		cout << "You did not get a fire started in time, you have died"
			<<" from exposure and hypothermia." << endl;
	}
}  		
