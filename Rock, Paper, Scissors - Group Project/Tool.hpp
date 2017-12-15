/*******************************************************************************
**Program: CS162-400 Group Project (Rock/Paper/Scissors)
**Authors: Bao Chau, Brendan James, Daniel Maynard, Brock Neidert, 
**	   Andrew Sturtevant
**Date: 30 July 2017
**Description: This is the base class Tool.  It will have two data members,
**one an integer for the tool strength, and the other a character for the tool type.
 * It will also have methods that will allow the tool type to be returned,
 * the strength to be set, and tools to fight.
*******************************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

#define LOSE -1
#define TIE 0
#define WIN 1

class Tool 
{
	protected:
		int strength;
		char type;

	public:
		Tool(int,char);
		virtual ~Tool();

		virtual double getStrength(Tool &) const;
		char getType() const;
		void SetStrength(int s);
		int fight(Tool &);
};
#endif  
