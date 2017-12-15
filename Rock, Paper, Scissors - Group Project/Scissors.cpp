/*******************************************************************************
**Program: CS162-400 Group Project (Scissors/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**         Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the class intilization of the Scissors class, please see
**Scissors.hpp for a full class description.
*******************************************************************************/
#include "Scissors.hpp"

/*******************************************************************************
** Constructor for the Scissors class.
*******************************************************************************/
Scissors::Scissors() : Tool(1,'s')
{        
}

/*******************************************************************************
** Constructor for the Scissors class that takes an int for the strength of the tool.
*******************************************************************************/
Scissors::Scissors(int s) : Tool (s,'s')
{
}

/*******************************************************************************
** Destructor for the Scissors class.
*******************************************************************************/
Scissors::~Scissors()
{
}


/*******************************************************************************
** Compute a temporary strength for the Scissors tool. 
** The temporary strength is computed based on the the input tool (t).
** If the input tool is a Paper, the temporary strength is double the actual strength.
** If the input tool is a Rock, the temporary strength is half the actual strength.
** If the input tool is a Scissors, the temporary strength is the same the actual strength.
*******************************************************************************/
double Scissors::getStrength(Tool &t) const
{
	double tempStrength;

	if(t.getType() == 'p')
	{
		tempStrength = strength * 2.0;
	}
	else if(t.getType() == 'r')
	{
		tempStrength = (double)strength / 2.0;
	}
	else
	{
		tempStrength = strength;
	}
	return tempStrength;
}
