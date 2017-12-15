/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 26 July 2017
**Description: This is a parent/base class for a variety of creatures that will
**fight for supremacy.  This game will have a number of different data members
**including attack information and defense information, a creature's armor
**and their strength points.  We will also have the name and description
**of the creature available.  There will be get and set methods for each
**of the data members, also an attack and defend funtion, and a function to
**reduce a creature's strength points. 
*******************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

using std::string;

class Creature
{

	protected:
		int attackNumberDie;
		int attackDieSize;
		int defenseNumberDie;
		int defenseDieSize;
		int armor;
		int strengthPoints;
		int attackDamage;
		int defenseDamage;
		int damageDealt;
		string description;
		string name;
				
	public:
		Creature();
		virtual ~Creature() = 0;
		
		int getAttackNumberDie();
                int getAttackDieSize();
                int getDefenseNumberDie();
                int getDefenseDieSize();
                int getArmor();
                int getStrengthPoints();
                int getAttackDamage();
                int getDefenseDamage();
                int getDamageDealt();
                string getDescription();
                string getName();
                
		void setAttackNumberDie(int);
		void setAttackDieSize(int);
		void setDefenseNumberDie(int);
		void setDefenseDieSize(int);
		void setArmor(int);
		void setStrengthPoints(int);
		void setAttackDamage(int);
		void setDefenseDamage(int);
		void setDamageDealt(int);
		void setDescription(string);
		void setName(string);
		
		virtual int attack();
		virtual int defend();
		virtual void reduceStrengthPoint(int); 		 	




 
};
#endif 
