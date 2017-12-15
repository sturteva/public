/*******************************************************************************
**Program: CS162-400 Program 3
**Author: Andrew P. Sturtevant
**Date: 30 July 2017
**Description: This is the class intilization of the base class Creature. Please
**see Creature.hpp for a full description.
*******************************************************************************/

#include "Creature.hpp"
#include <string>
#include <iomanip>
using std::string;

Creature::Creature()
{}

Creature::~Creature()
{}
int Creature::getAttackNumberDie()
{
	return attackNumberDie;
}

int Creature::getAttackDieSize()
{
	return attackDieSize;
}

int Creature::getDefenseNumberDie()
{
	return defenseNumberDie;
}

int Creature::getDefenseDieSize()
{
	return defenseDieSize;
}

int Creature::getArmor()
{
	return armor;
}

int Creature::getStrengthPoints()
{
	return strengthPoints;
}

int Creature::getAttackDamage()
{
	return attackDamage;
}

int Creature::getDefenseDamage()
{
	return defenseDamage;
}

int Creature::getDamageDealt()
{
	return damageDealt;
}

string Creature::getDescription()
{
	return description;
}

string Creature::getName()
{
	return name;
}

void Creature::setAttackNumberDie(int a)
{
	attackNumberDie = a;
}

void Creature::setAttackDieSize(int a)
{
	attackDieSize = a;
}

void Creature::setDefenseNumberDie(int a)
{
	defenseNumberDie = a;
}

void Creature::setDefenseDieSize(int a)
{
	defenseDieSize = a;
}

void Creature::setArmor(int a)
{
	armor = a;
}

void Creature::setStrengthPoints(int a)
{
	strengthPoints = a;
}

void Creature::setAttackDamage(int a)
{
	attackDamage = a;
}

void Creature::setDefenseDamage(int a)
{
	defenseDamage = a;
}

void Creature::setDamageDealt(int a)
{
	damageDealt = a;
}

void Creature::setDescription(string a)
{
	description = a;
}

void Creature::setName(string a)
{
	name = a;
}

int Creature::attack()
{
	attackDamage = 
		rand() % (attackNumberDie * attackDieSize) + attackNumberDie;

	return attackDamage;
}

int Creature::defend()
{
	defenseDamage = 
		 rand() % (defenseNumberDie * defenseDieSize)+ defenseNumberDie;

	return defenseDamage;
}

void Creature::reduceStrengthPoint(int damage)
{
	if((damage-armor) > 0)
	{
		damageDealt = damage - armor;
		strengthPoints = strengthPoints - damageDealt;
		return;
	}
	else
	{
		damageDealt = 0;
		return;
	}
}

