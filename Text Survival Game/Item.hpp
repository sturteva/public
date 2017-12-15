/*******************************************************************************
**Program: CS162-400 Final Project
**Author: Andrew P. Sturtevant
**Date: 15 Aug 2017
**Description: This is a simple object that basically just holds a string.
**It can be changed.
*******************************************************************************/

#ifndef ITEM_HPP 
#define ITEM_HPP

#include <string>

using std::string;

class Item
{
	private:
		string name;
	public:
		Item();	
		Item(string);
		~Item();	
		string getName();	
		void setName(string);
};		
		
#endif
