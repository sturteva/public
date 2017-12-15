/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the functions header file. It contains 3 input functions.
 *     The first function gets an integer from the user, the second returns a random
 *     integer, and the third gets a character from the user.
*******************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

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
int getIntegerFromUser(string prompt, int minValue, int maxValue);

/***********************************************************************************
Arguments:
	min - The minimum value.
	max - The maximum value.
Return:
	An integer betwen min and max
Description:
	Randomly generate and return an integer between min and max.
***********************************************************************************/
int getRandomInteger(int min, int max);

/***********************************************************************************
Arguments:
	a - The first valid character that a user can input.
    b - The second valid character that a user can input.
Return:
	Character that the user inputs (which must be one of the two characters passed to the function)
Description:
	Prompt user for an input and make sure that user entered a valid character
	that is equal to either of the characters passed to the function.
***********************************************************************************/
char validAlpha(char a, char b);

#endif