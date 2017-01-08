/*
Name: Josh Erickson
Description: Main
*/

#include "Creature.hpp"
#include "BabaYaga.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "FightingQueue.hpp"
#include "Loserpile.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream> 
#include <string>

using std::string;

Creature* creatureCreate(int creatureChoice, string name);	//Function to create the creature specified by the user
string returnName(Creature* name);	//Function that prints out the name of the creature passed
void healCreature(Creature* fighter);	//Function to heal a creature back to max health
void printLosers(Loserpile* finishers, FightingQueue* winningteam);		//Print the other losers, deletes allocated memory



int main()
{
	int creatureChoice;		//To hold the integer with the choice of the creature
	int numPerTeam;			//To hold how many creatures the user wants per team
	string teamName1, teamName2;	//Hold the 2 team names
	string creatureName;		//Hold each creature name as they are named
	srand(time(NULL));	//Random seed
	Creature* fighter;
	std::cout << "Welcome to Fantasy Fight Club." << std::endl;
	std::cout << "Two teams made up of creatures of your choice will brawl it out to the death." << std::endl;
	std::cout << "How many creatures would you like per team?" << std::endl;
	std::cin >> numPerTeam;
	std::cout << "Please enter the name of the first team.\n(This team will attack first)" << std::endl;
	std::cin >> teamName1;
	std::cout << std::endl;
	std::cout << "Please enter the name of the second team." << std::endl;
	std::cin >> teamName2;
	std::cout << std::endl;

	FightingQueue *team1 = new FightingQueue(teamName1);		//Creating the first team
	FightingQueue *team2 = new FightingQueue(teamName2);		//Second team
	FightingQueue *teamArray[2] = { team1, team2 };				//Creating an array of the teams

	for (int i = 0; i < 2; i++)	//Loop thru the two teams to add in the creatures
	{
		FightingQueue *current = teamArray[i];
		std::cout << current->getTeamName() << " is picking the creatures in their team.\n" << std::endl;
		std::cout << std::endl;

		for (int j = 0; j < numPerTeam; j++)	//Add in the number of creatures specified by the user
		{
			std::cout << "What type of creature should fighter number " << j + 1 << " be?" << std::endl;
			std::cout << std::endl;
			std::cout << "Choices:\n1: Medusa\n2: Barbarian\n3: Baba Yaga\n4: Blue Men\n5: Harry Potter" << std::endl;
			std::cin >> creatureChoice;
			while (creatureChoice > 5 || creatureChoice < 1)
			{
				std::cout << "Please enter a number between 1 and 5" << std::endl;
				std::cin >> creatureChoice;
			}
			std::cout << "What would you like to name this fighter?" << std::endl;
			std::cin >> creatureName;
			std::cout << std::endl;
			fighter = creatureCreate(creatureChoice, creatureName);
			current->add(fighter);		//Adding the created fighter to the FightingQueue
		}
	}

	FighterQueue *team1Current = team1->getCurrentFighter();
	FighterQueue *team2Current = team2->getCurrentFighter();

	/*std::cout << "Fighter 1 inital combat stats\n" << std::endl;
	std::cout << returnName(fighter1) << " stats:" << std::endl;
	std::cout << "Attack: " << fighter1->getNumAttackDice() << " " << fighter1->getAttackDieSides() << "-sided dice or die." << std::endl;
	std::cout << "Defense: " << fighter1->getNumAttackDice() << " " << fighter1->getAttackDieSides() << "-sided dice or die." << std::endl;
	std::cout << "Armor: " << fighter1->getArmorPts() << std::endl;
	std::cout << "Strength Points: " << fighter1->getStrPts() << "\n" << std::endl;

	std::cout << "Fighter 2 inital combat stats\n" << std::endl;
	std::cout << returnName(fighter2) << " stats:" << std::endl;
	std::cout << "Attack: " << fighter2->getNumAttackDice() << " " << fighter2->getAttackDieSides() << "-sided dice or die." << std::endl;
	std::cout << "Defense: " << fighter2->getNumAttackDice() << " " << fighter2->getAttackDieSides() << "-sided dice or die." << std::endl;
	std::cout << "Armor: " << fighter2->getArmorPts() << std::endl;
	std::cout << "Strength Points: " << fighter2->getStrPts() << "\n\n" << std::endl;
	*/
	Creature *team1curr = team1->getCurrentFighter()->fighter;;
	Creature *team2curr = team2->getCurrentFighter()->fighter;;
	Loserpile *losers = new Loserpile;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	std::cin.ignore();
	while ((team1->getCurrentFighter() != NULL) && (team2->getCurrentFighter() != NULL))
	{
		team1curr = team1->getCurrentFighter()->fighter;
		team2curr = team2->getCurrentFighter()->fighter;
		int fighter1Def = team1curr->rollDef();
		int fighter1Atk = team1curr->rollAtk();
		int fighter2Def = team2curr->rollDef();
		int fighter2Atk = team2curr->rollAtk();
		int babaYagaHeal;
		int babaYagaHeal2;

		if (team1curr->getCreatureType() == BABAYAGA)
		{
			babaYagaHeal = ((fighter1Atk - fighter2Def - team2curr->getArmorPts()) / 3);	//If fighter1 is baba yaga, calculate the heal here and add it in after she attacks later
		}

		if (team2curr->getCreatureType() == BABAYAGA)
		{
			babaYagaHeal2 = ((fighter2Atk - fighter1Def - team1curr->getArmorPts()) / 3);	//If fighter2 is baba yaga, calculate the heal here and add it in after she attacks later
		}

		std::cout << team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " attacking:\n" << std::endl;

		team2curr->updateStr(fighter2Def, fighter1Atk);	//Fighter 1 attacking fighter 2

		if (team1curr->getCreatureType() == MEDUSA && fighter1Atk == 12)
		{
			team2curr->setLife(false);
			std::cout << team1curr->getCreatureName() << " of creature type Medusa used Glare! It's super effective. She wins.\n" << std::endl;
			fighter1Atk = 999;
			team2curr->setStrPts(0);
		}
		std::cout << team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " attacks " << team2curr->getCreatureName()
			<< " of creature type " << returnName(team2curr) << " for " << fighter1Atk << "\n" << std::endl;
		std::cout << team2curr->getCreatureName() << " of creature type " << returnName(team2curr) << " rolls a " << fighter2Def 
			<< " for defense and absorbs \nan additional " << team2curr->getArmorPts() << " with their armor\n" << std::endl;

		if (team1curr->getCreatureType() == BABAYAGA)
		{
			team1curr->setStrPts((team1curr->getStrPts() + babaYagaHeal));

			if (babaYagaHeal > 0)
			{
				std::cout << team1curr->getCreatureName() << " of creature type Baba Yaga heals for " << babaYagaHeal 
					<< " and has new strength amounting to " << team1curr->getStrPts() << "\n" << std::endl;
			}
		}

		std::cout << team2curr->getCreatureName() << " of creature type " << returnName(team2curr) << " is left with " 
			<< team2curr->getStrPts() << " strength.\n\n" << std::endl;

		if (team2curr->getLife() == true)
		{
			std::cout << team2curr->getCreatureName() << " of creature type " << returnName(team2curr) << " attacking:\n" << std::endl;
			team1curr->updateStr((fighter1Def), (fighter2Atk));	//If fighter 2 didn't die, fighter 2 attacks fighter 1 here
			if (team2curr->getCreatureType() == MEDUSA && fighter2Atk == 12)
			{
				team1curr->setLife(false);
				std::cout << team2curr->getCreatureName() << " of creature type Medusa used Glare! It's super effective. She wins.\n" << std::endl;
				fighter2Atk = 999;
				team1curr->setStrPts(0);
			}


			std::cout << team2curr->getCreatureName() << " of creature type " << returnName(team2curr) << " attacks " << 
				team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " for " << fighter2Atk << "\n" << std::endl;
			std::cout << team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " rolls a " << fighter1Def << 
				" for defense and absorbs an \nadditional " << team1curr->getArmorPts() << " with their armor\n" << std::endl;

			if (team2curr->getCreatureType() == BABAYAGA)
			{
				team2curr->setStrPts((team2curr->getStrPts() + babaYagaHeal2));
				if (babaYagaHeal2 > 0)
				{
					std::cout << team2curr->getCreatureName() << " of creature type Baba Yaga heals for " << babaYagaHeal2 << " and has new strength amounting to "
						<< team2curr->getStrPts() << "\n" << std::endl;
				}
			}

			std::cout << team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " is left with "
				<< team1curr->getStrPts() << " strength.\n\n" << std::endl;
		}
		std::cout << "Press enter to continue" << std::endl;
		std::cin.ignore();
		if (team1curr->getLife() == false)
		{
			std::cout << team2curr->getCreatureName() << " of creature type " << returnName(team2curr) << " won this fight!\n" << std::endl;
			std::cout << "Moving " << team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " to the loserpile.\n" << std::endl;
			team1->remove();
			losers->add(team1curr);
			std::cout << "Healing " << team2curr->getCreatureName() << " of creature type " << returnName(team2curr)
				<< " and moving them to the back of the lineup.\n" << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			healCreature(team2curr);
			if (team2->getCurrentFighter()->next != NULL)
			{
				team2->remove();
				team2->add(team2curr);
			}
			if (team1->getCurrentFighter() != NULL)
			{
				team1curr = team1->getCurrentFighter()->fighter;
			}
			if (team2->getCurrentFighter() != NULL)
			{
				team2curr = team2->getCurrentFighter()->fighter;
			}
			

		}

		if (team2curr->getLife() == false)
		{
			std::cout << team1curr->getCreatureName() << " of creature type " << returnName(team1curr) << " won this fight!\n" << std::endl;
			std::cout << "Moving " << team2curr->getCreatureName() << " of creature type " << returnName(team2curr)
				<< " to the loserpile.\n" << std::endl;

			team2->remove();
			losers->add(team2curr);
			std::cout << "Healing " << team1curr->getCreatureName() << " of creature type " << returnName(team1curr)
				<< " and moving them to the back of the lineup.\n" << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			healCreature(team1curr);
			if (team1->getCurrentFighter()->next != NULL)
			{
				team1->remove();
				team1->add(team1curr);
			}
			if (team1->getCurrentFighter() != NULL)
			{
				team1curr = team1->getCurrentFighter()->fighter;
			}
			if (team2->getCurrentFighter() != NULL)
			{
				team2curr = team2->getCurrentFighter()->fighter;
			}
		}
	}

	if (team1->getCurrentFighter() == NULL)
	{
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "The winning team was team " << team2->getTeamName() << " as they had the last surviving fighter." << std::endl;
		std::cout << "The 1st place winner, with the winning killshot, is " << team2curr->getCreatureName() << " of creature type "
			<< returnName(team2curr) << std::endl;
		team2->remove();
		printLosers(losers, team2);	//Printing the rest of the losers and taking care of memory leaks
		

	}
		
	else if (team2->getCurrentFighter() == NULL)
	{
		std::cout << "The winning team was team " << team1->getTeamName() << " as they had the last surviving fighter." << std::endl;
		std::cout << "The 1st place winner, with the winning killshot, is " << team1curr->getCreatureName() << " of creature type "
			<< returnName(team1curr) << std::endl;
		team1->remove();
		printLosers(losers, team1);	//Printing the rest of the losers and taking care of memory leaks
	}


	return 0;
}


void printLosers(Loserpile* finishers, FightingQueue* winningTeam)
{
	std::cout << "The creature(s) who did not make 1st place:" << std::endl;
	int place = 2;
	int choice;
	std::cout << "Would you like to print out the 2nd and 3rd place winners as well as the rest \nof the losers(Enter 1), or would you like to just see the \n2nd and 3rd place winners(Enter 2)?" << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > 2)
	{
		std::cout << "Please enter 1 or 2" << std::endl;
		std::cin >> choice;
	}
	if (choice == 1)
	{
		while (winningTeam->getCurrentFighter() != NULL)
		{
			std::cout << place << ": " << winningTeam->getCurrentFighter()->fighter->getCreatureName() << " of creature type " <<
				returnName(winningTeam->getCurrentFighter()->fighter) << " from team " << winningTeam->getTeamName() << std::endl;
			winningTeam->remove();
			place++;
		}
		while (finishers->getCurrentLoser() != NULL)
		{
			std::cout << place << ": " << finishers->getCurrentLoser()->loser->getCreatureName() << " of creature type "
				<< returnName(finishers->getCurrentLoser()->loser) << std::endl;
			finishers->remove();
			place++;
		}
	}
	else if (choice == 2)
	{
		while ((winningTeam->getCurrentFighter() != NULL) && (place < 4))
		{
			std::cout << place << ": " << winningTeam->getCurrentFighter()->fighter->getCreatureName() << " of creature type " <<
				returnName(winningTeam->getCurrentFighter()->fighter) << " from team " << winningTeam->getTeamName() << std::endl;
			winningTeam->remove();
			place++;
		}
		while ((finishers->getCurrentLoser() != NULL) && (place < 4))
		{
			std::cout << place << ": " << finishers->getCurrentLoser()->loser->getCreatureName() << " of creature type "
				<< returnName(finishers->getCurrentLoser()->loser) << std::endl;
			finishers->remove();
			place++;
		}
		while (winningTeam->getCurrentFighter() != NULL)	//Freeing memory
		{
			winningTeam->remove();
		}
		while (finishers->getCurrentLoser() != NULL)		//Freeing memory
		{
			finishers->remove();
		}
	}

}


void healCreature(Creature* fighter)
{
	if (fighter->getCreatureType() == MEDUSA)
	{
		fighter->setStrPts(8);
	}
	if (fighter->getCreatureType() == BARBARIAN)
	{
		fighter->setStrPts(12);
	}
	if (fighter->getCreatureType() == BABAYAGA)
	{
		fighter->setStrPts(12);
	}
	if (fighter->getCreatureType() == HARRYPOTTER)
	{
		fighter->setStrPts(10);
		fighter->setBeenRevived(false);
	}
	if (fighter->getCreatureType() == BLUEMEN)
	{
		fighter->setStrPts(12);
		fighter->setNumDefenseDice(3);
	}
}

Creature* creatureCreate(int creatureChoice, string name)
{
	Creature* tempCreature;
	if (creatureChoice == 1)
	{
		tempCreature = new Medusa(name);
		return tempCreature;
	}

	if (creatureChoice == 2)
	{
		tempCreature = new Barbarian(name);
		return tempCreature;
	}

	if (creatureChoice == 3)
	{
		tempCreature = new BabaYaga(name);
		return tempCreature;
	}

	if (creatureChoice == 4)
	{
		tempCreature = new BlueMen(name);
		return tempCreature;
	}

	if (creatureChoice == 5)
	{
		tempCreature = new HarryPotter(name);
		return tempCreature;
	}
}

string returnName(Creature* name)
{
	if (name->getCreatureType() == MEDUSA)
	{
		return "Medusa";
	}
	else if (name->getCreatureType() == BARBARIAN)
	{
		return "Barbarian";
	}
	else if (name->getCreatureType() == BABAYAGA)
	{
		return "Baba Yaga";
	}
	else if (name->getCreatureType() == BLUEMEN)
	{
		return "Blue Men";
	}
	else if (name->getCreatureType() == HARRYPOTTER)
	{
		return "Harry Potter";
	}
}