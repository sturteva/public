/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the class intilization of the Rock class, please see
**Rock.hpp for a full class description.
*******************************************************************************/
#include "Rock.hpp"

/*******************************************************************************
** Constructor for the Rock class.
*******************************************************************************/
Rock::Rock() : Tool(1,'r')
{
}

/*******************************************************************************
** Constructor for the Rock class that takes an integer for the strength of the tool.
*******************************************************************************/
Rock::Rock(int s) : Tool (s,'r')
{
}

/*******************************************************************************
** Destructor for the Rock class.
*******************************************************************************/
Rock::~Rock()
{
}

/*******************************************************************************
** Compute and return a temporary strength for the Rock tool. 
** The temporary strength is computed based on the the input tool (t).
** If the input tool is a Scissors, the temporary strength is double the actual strength.
** If the input tool is a Paper, the temporary strength is half the actual strength.
** If the input tool is a Rock, the temporary strength is the same the actual strength.
*******************************************************************************/
double Rock::getStrength(Tool &t) const
{
	double tempStrength;

	if(t.getType() == 's')
	{
		tempStrength = strength * 2.0;
	}	
	else if(t.getType() == 'p')
	{
		tempStrength = (double)strength / 2.0;
	}
	else
	{
		tempStrength = strength;
	}
	return tempStrength;
}
