/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the functions source file. It contains 3 input functions.
 *     The first function gets an integer from the user, the second returns a random
 *     integer, and the third gets a character from the user.
*******************************************************************************/

#include <string>
#include <iostream>
#include <limits>
#include <ctime>
#include "Functions.hpp"

/***********************************************************************************
Arguments:
	prompt - a string that holds a message to inform the user what kind/type of
		input is expected.
	minValue - An integer indicates the minimum integer input to be accepted.
	maxValue - An integer indicates the maximum integer input to be accepted.
Return:
	An acceptable integer that user entered.
Description:
	Prompt user for an input and make sure that user entered a valid integer
	between the minValue maxValue input parameters.
***********************************************************************************/
int getIntegerFromUser(string prompt, int minValue, int maxValue)
{
	bool inputFail = true;
	int input;

	while (inputFail)
	{
		//Display prompt message
		cout << prompt;

		//Read input
		cin >> input;
		inputFail = cin.fail();

		//clear input stream buffer.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//Inform user if input is valid.
		if ((inputFail) || (input < minValue) || (input > maxValue))
		{
			cout << "\nYour input is invalid.\n";
			cout << "Please enter an integer from ";
			cout << minValue << " to " << maxValue << ".\n\n";

			inputFail = true;
		}
	}

	return input;
}

/***********************************************************************************
Arguments:
	min - The minimum value.
	max - The maximum value.
Return:
	An integer betwen min and max
Description:
	Randomly generate and return an integer between min and max.
***********************************************************************************/
int getRandomInteger(int min, int max)
{
	int result;
	static bool setSeed = false;

	if (setSeed == false)
	{
		srand(static_cast<int>(time(0)));
		setSeed = true;
	}

	result = (rand() % (max - min + 1)) + min;
	return result;
}

/*******************************************************************************
** Prompt user for an input character and make sure that user entered a valid 
** character. Otherwise, request user for another entry.
** Return the valid input character.
*******************************************************************************/
char validAlpha(char a, char b){
	char alpha;

	cout << "Valid choices are " << a << " or " << b << std::endl;
	cin >> alpha;
	alpha = tolower(alpha);

	while(alpha != a && alpha != b){
		std::cin.clear();
		cin.ignore(100, '\n');

		cout << "Valid choices are " << a << " or " << b << std::endl;
		cin >> alpha;
		alpha = tolower(alpha);
	}
	return alpha;
}