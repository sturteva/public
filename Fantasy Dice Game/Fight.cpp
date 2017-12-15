/*******************************************************************************
**Program: CS162-400 Project 3
**Author: Andrew P. Sturtevant
**Date: 31 July 2017
**Description: This is the class initialization for the Fight class, pelase see
**Fight.hpp for a full description. 
*******************************************************************************/

#include "Fight.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"
#include "Menus.hpp"
#include <iostream>


using std::cout;
using std::endl;

void Fight::attack(Creature* attacker, Creature* defender,int player)
{
	int total;
	int attack;
	int defense = defender->defend();
	if(defense == 9999)
	{
		return;
	}
	else
	{
		 attack = attacker->attack();
		if(attack == 9999)
		{
			int report;
			total = attack - defense;
			defender->reduceStrengthPoint(total);
			report = defender->getStrengthPoints();
	 	 	if(report <= 0 && player == 1)
			{
				player1Win = true;
				return;
			}
			else if (report <= 0 && player == 2) 
			{
				player2Win = true;
				return;
			}
			else
			{
				return;
			}
		}
		
		
	
		else if(attack > defense)
		{
			total = attack - defense;
			defender->reduceStrengthPoint(total);
			int defStrPts = defender->getStrengthPoints();
			if(defStrPts <= 0 && player == 1 )
			{
				player1Win = true;
				return;
			}
			else if(defStrPts <= 0 && player == 2)
			{
				player2Win = true;
			}
				
			else
			{
				return;
			}
		}

		else
		{
			return;
		} 		
	}

}

void Fight::fullAttack()
{
	Creature* player1;
	Creature* player2; 
	Menus menu;
	cout << "Player 1 Choose your Creature" << endl;
	int player1Choice = menu.multiMenu();
	if(player1Choice == 1)
	{
		 player1 = new Vampire();
	}

	else if(player1Choice == 2)
	{
		player1 = new Barbarian();
	}

	else if(player1Choice == 3)
	{
		player1 = new Blue_Men();
	}	 
	
	else if(player1Choice == 4)
	{
		player1 = new Medusa();
	}

	else
	{
		player1 = new Harry_Potter();
	}

	cout << "Player 2 Choose your Creature" << endl;
	int player2Choice = menu.multiMenu();

	if(player2Choice == 1)
	{
		player2 = new Vampire();
	}

	else if(player2Choice == 2)
	{
		player2 = new Barbarian();
	}

	else if(player2Choice ==3 )
	{
		player2 = new Blue_Men();
	}
	
	else if(player2Choice == 4)
	{
		player2 = new Medusa();
	}

	else
	{
		player2 = new Harry_Potter();
	}		 
	
	srand(time(NULL));
	int playerFirst = rand() % 2 + 1;
	int counter = 1;
	 	
	while (!player1Win && !player2Win)
	{
		//Resets all Damage values to zero for each round. 
		player1->setAttackDamage(0);
		player1->setDefenseDamage(0);
		player2->setAttackDamage(0);
		player2->setDefenseDamage(0);
		player1->setDamageDealt(0);
		player2->setDamageDealt(0);

		cout << "#########Round " <<counter<< "###############" << endl;

		if(playerFirst == 1)
		{
			cout << "---------Player 1 Attack-------------" << endl;
			cout << "Player 2 (" <<player2->getName() << ")"
                                << " Strength Points Before being Attacked: "
                                << player2->getStrengthPoints()<< endl;
			attack(player1,player2,1);
			cout << "Player 1(" << player1->getName() << ")"
				<< "Attack Damage: " 
				<< player1->getAttackDamage() << endl;
  
			cout << "Player 2 (" <<player2->getName()<<") Defense: "
				<< player2->getDefenseDamage() << endl;
			cout << "Player 2 (" <<player2->getName()<<") Armor: "
				 << player2->getArmor() << endl;
			cout << "Player 1 dealt " << player2->getDamageDealt()
				<< " damage to Player 2" << endl;
			cout << "Player 2 (" <<player2->getName() << ")"
                                << " Strength Points: "
                                << player2->getStrengthPoints()<<endl;

			if(!player1Win)
			{
			cout << "---------Player 2 Attack-------------" << endl;

				cout << "Player 1 (" <<player1->getName() << ")"
                                << " Strength Points Before being Attacked: "
                                << player1->getStrengthPoints()<< endl;
	
				attack(player2,player1,2);
				cout << "Player 2(" << player2->getName() << ")"
                                	<< "Attack Damage: "
                                	<< player2->getAttackDamage() << endl;
							
                        	cout << "Player 1 (" <<player1->getName() 
					<< ") Defense: "
	                                << player1->getDefenseDamage() << endl;
				cout << "Player 1 (" <<player1->getName()<<")"
					<< "Armor: "
                                 	<< player1->getArmor() << endl;
        	                cout << "Player 2 dealt " 
					<< player1->getDamageDealt()
                                	<< " damage to Player 1" << endl; 
			 	cout << "Player 1 (" <<player1->getName() << ")"
                                	<< " Strength Points: "
                                	<< player1->getStrengthPoints()<< endl;
	
			}
		}

		else if(playerFirst == 2)
                {
			cout << "---------Player 2 Attack-------------" << endl;
                        
			 cout << "Player 1 (" <<player1->getName() << ")"
                                << " Strength Points Before being Attacked: "
                                << player1->getStrengthPoints()<< endl;

			attack(player2,player1,2);
                        cout << "Player 2(" << player2->getName() << ")"
                                << "Attack Damage: "
                                << player2->getAttackDamage() << endl;
			
                        cout << "Player 1 (" <<player1->getName()<<") Defense: "
                                << player1->getDefenseDamage() << endl;
			cout << "Player 1 (" <<player1->getName()<<")"
                                        << "Armor: "
                                        << player1->getArmor() << endl;
                        cout << "Player 2 dealt " << player1->getDamageDealt()
                                << " damage to Player 1" << endl;
			cout << "Player 1 (" <<player1->getName() << ")"
                                << " Strength Points: "
                                << player1->getStrengthPoints()<< endl;

                        if(!player2Win)
                        {
			cout << "---------Player 1 Attack-------------" << endl;

				cout << "Player 2 (" <<player2->getName() << ")"
                                << " Strength Points Before being Attacked: "
                                << player2->getStrengthPoints()<< endl;

                                attack(player1,player2,1);
                                cout << "Player 1(" << player1->getName() << ")"
                                        << "Attack Damage: "
                                        << player1->getAttackDamage() << endl;
				

                                cout << "Player 2 (" <<player2->getName()
                                        << ")  Defense: "         
                                        << player2->getDefenseDamage() << endl;
				cout << "Player 2 (" <<player2->getName()<<")"
                                        << "Armor: "
                                        << player2->getArmor() << endl;

                                cout << "Player 1 dealt "
                                        << player2->getDamageDealt()
                                        << " damage to Player 2" << endl;
				cout << "Player 2 (" <<player2->getName() << ")"
        	                        << " Strength Points: "
 	                               << player2->getStrengthPoints() << endl;

                        }
                }
	counter ++;
	}

	winner(player1,player2);
	delete player1;
	delete player2;	
	return;	
}

void Fight::winner(Creature* player1, Creature* player2)
{
	if(player1Win)
	{
		cout << "Player 1 (" << player1->getName() << ") is the winner!"
			<< endl;
		return;
	}

	else if (player2Win)
	{
		cout << "Player 2 (" << player2->getName() << ") is the winner!"
			<< endl;
		return;
	} 	
}	
