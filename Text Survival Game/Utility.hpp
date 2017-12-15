/*******************************************************************************
**Program: Utilities Class
**Author: Andrew P. Sturtevant
**Description: Header file for Utilities. See Utilities.cpp for full description
*******************************************************************************/

#ifndef UTILITY_HPP 
#define UTILITY_HPP

class Utility
{


	public:
		int readInt();
		int readIntRange(int, int);
		int readPosInt();
		double readDouble();
		double readPosDouble();
		char readChar();
		char readCharYesNo();
		
};
#endif 
