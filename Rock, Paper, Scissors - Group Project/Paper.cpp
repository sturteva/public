/*******************************************************************************
**Program: CS162-400 Group Project (Paper/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**         Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the class intilization of the Paper class, please see
**Paper.hpp for a full class description.
*******************************************************************************/
#include "Paper.hpp"

/*******************************************************************************
** Constructor for the Paper class.
*******************************************************************************/
Paper::Paper() : Tool(1,'p')
{
}

/*******************************************************************************
** Constructor for the Paper class that takes an integer for the strength of the tool.
*******************************************************************************/
Paper::Paper(int s) : Tool (s,'p')
{
}

/*******************************************************************************
** Destructor for the Paper class.
*******************************************************************************/
Paper::~Paper()
{
}


/*******************************************************************************
** Compute a temporary strength for the Paper tool. 
** The temporary strength is computed based on the the input tool (t).
** If the input tool is a Rock, the temporary strength is double the actual strength.
** If the input tool is a Scissors, the temporary strength is half the actual strength.
** If the input tool is a Paper, the temporary strength is the same the actual strength.
*******************************************************************************/
double Paper::getStrength(Tool &t) const
{
	double tempStrength;

	if(t.getType() == 'r')
	{
		tempStrength = strength * 2.0;
	}
	else if(t.getType() == 's')
	{
		tempStrength = (double)strength / 2.0;		 
	}
	else
	{
		tempStrength = strength;
	}
	return tempStrength;
}
