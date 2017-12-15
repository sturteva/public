/*******************************************************************************
**CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is the class intilizaiton. See Mountain.hpp for full details
*******************************************************************************/

#include "Forest.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Forest::Forest():Space()
{
        description = "Beutiful forest all around you";
        resources->changeItem(1,"Wood");
}

string Forest::getType()
{
        return "a Forest";
}

void Forest::specialAction()
{
 

	cout << "You climb a tree in the forest and see more than you"
		<<" normally would!" << endl;

	cout << "To the North you see...";
        if(toNorth == NULL)
        {
                cout <<"Nothing, the mysterious wall blocks your sight."
                        << endl;
		cout <<"To the NorthEast you see...Nothing, the mysterious wall"
                        << " blocks your sight" << endl;
                cout <<"To the NorthWest you see...Nothing, the mysterious wall"
                        << " blocks your sight" << endl;
        }

        else
        {
                cout << toNorth->getType() << endl;
                if(toNorth->getCrash())
			cout << "You also see your crash site." << endl;

		cout << "To the NorthEast you see...";
        	if(toNorth->getEast() == NULL)
        	{
                cout << "Nothing, the mysterious wall blocks"<<" your sight."  
			<< endl;
        	}

		else
        	{
                	cout << toNorth->getEast()->getType() << endl;
                	if(toNorth->getEast()->getCrash())
                         	cout << "You also see your crash site." << endl;

        	}

		cout << "To the NorthWest you see...";
	        if(toNorth->getWest() == NULL)
        	{
                	cout <<"Nothing, the mysterious wall blocks your sight."
                        	<< endl;
       		 }

	        else
	        {
        	        cout << toWest->getNorth()->getType() << endl;
                	if(toWest->getNorth()->getCrash())
                        	 cout << "You also see your crash site." 
					<< endl;

        	}	 

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
		cout <<"To the SouthEast you see...Nothing, the mysterious wall"
			<< " blocks your sight" << endl;
		cout <<"To the SouthWest you see...Nothing, the mysterious wall"
			<< " blocks your sight" << endl;	
        }

        else
        {
                cout << toSouth->getType() << endl;
                if(toSouth->getCrash())
                        cout << "You also see your crash site." << endl;


	 	cout << "To the SouthEast you see...";
	        if(toSouth->getEast() == NULL )
        	{
                	cout <<"Nothing, the mysterious wall blocks your sight."
                        	<< endl;
        	}

	        else
        	{
                	cout << toEast->getSouth()->getType() << endl;
	                if(toEast->getSouth()->getCrash())
        	                 cout << "You also see your crash site." 
					<< endl;

	        }

		cout << "To the SouthWest you see..";
	        if(toSouth->getWest() == NULL)
        	{
                	cout <<"Nothing, the mysterious wall blocks your sight."
                        	<< endl;
	        }

	        else
        	{
                	cout << toSouth->getWest()->getType() << endl;
	                if(toSouth->getWest()->getCrash())
        	                 cout << "You also see your crash site." 
					<< endl;

        	}


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
