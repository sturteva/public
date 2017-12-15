/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert,
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the class initialization for Tool. Please see Tool.hpp
**for a full description of the class.
*******************************************************************************/

#include "Tool.hpp"

/*******************************************************************************
** The only constructor for the Tool class
*******************************************************************************/
Tool::Tool(int s, char t)
{
	strength = s;
	type = t;
}

/*******************************************************************************
** Destructor for the Tool class.
*******************************************************************************/
Tool::~Tool()
{
}

/*******************************************************************************
** Return the strength of the tool.
*******************************************************************************/
double Tool::getStrength(Tool &t) const
{
	return strength;
}

/*******************************************************************************
** Return the type of the tool.
*******************************************************************************/
char Tool::getType() const
{
	return type;
}

/*******************************************************************************
** set the strength of the tool.
*******************************************************************************/
void Tool::SetStrength(int s)
{
	strength = s;
}

/*******************************************************************************
** Compare the isntance's strength against the strength of the input 
** tool (otherTool). Return WIN, LOSE or TIE based on whether the tool's
** strength is greater than, less than or equal to the otherTool's strength,
** respectively.
*******************************************************************************/ 
int Tool::fight(Tool &otherTool)
{
	double myStrength, otherStrength; // Changed from int to double

	//Get the strength of this tool and the opponent's tool
	myStrength = this->strength;
	otherStrength = otherTool.getStrength(*this);

	//Compare the strength and return result.
	if(myStrength > otherStrength)
	{
		return WIN;
	}
	else if(myStrength < otherStrength)
	{
		return LOSE;
	}
	return TIE;
}
	 
