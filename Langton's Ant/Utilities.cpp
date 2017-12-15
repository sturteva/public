/*******************************************************************************
**Program: Input Validation Custom Class
**Author: Andrew P. Sturtevant
**Date: 05 Jul 2017
**Description: This class will have various functions that will check for
**input validation.  To start I only need to validate integers, so it will only
**have the one method.
*******************************************************************************/

#include <cmath>
#include <iostream>


using std::cout;
using std::endl; 
using std::cin;

//This is the basis for any Integer validation.
//https://stackoverflow.com/questions/16934183/integer-validation-for-input
int readInt()
{
	int input;
	bool valid = false;
	while (!valid)
	{
		cin >> input;
		if(cin.fail())
		{
			cout << "Not an integer, please enter an integer." 
				<< endl;

			cin.clear();
			cin.ignore(256, '\n');
		}
	
		else
		{
			valid = true;
		}
	}
	return input;
}

//Validates an integer within a particular range.
int readIntRange(int minSize, int maxSize)
{
	int input;
	bool valid = false;
	
	while(!valid)
	{
		cin >> input;

		if(cin.fail() || input > maxSize || input < minSize)
		{
			cout << "Not an integer between " << minSize << 
				"-" << maxSize << ". Please select an integer"
				<< " within that range." << endl; 	 
				
			
			cin.clear();
			cin.ignore(256, '\n');
		}

		else
		{
			valid = true;
		}
	}
	return input;
}	 				

//Ensures that an integers is positive. 
int readPosInt()
{
	int input;
	bool valid = false;
	while (!valid)
	{
		cin >> input;
		if(cin.fail() || input < 0)
		{
			cout << "Please select a Positive Integer." << endl;

			cin.clear();
			cin.ignore(256,'\n');
		}
		else
		{
			valid = true;
		}
	}
	return input;
}	 
					
