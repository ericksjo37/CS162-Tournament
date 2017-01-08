/*
Name: Josh Erickson
Description: Header file for FightingQueue class
*/

#ifndef FIGHTINGQUEUE_HPP
#define FIGHTINGQUEUE_HPP

#include "Creature.hpp"
#include <string>

struct FighterQueue
{
	Creature *fighter;
	FighterQueue *next;
	FighterQueue *previous;
};

class FightingQueue
{
private:
	FighterQueue *current;
	std::string teamName;
public:
	FightingQueue(std::string name);	//Constructor
	void add(Creature* fighter);	//Add the passed parameter to queue
	Creature* remove();	//Remove an item from the queue and return the creature that was removed
	std::string getTeamName();		//Getter for the team name
	void setTeamName(std::string name);	//Setter for the team name
	FighterQueue* getCurrentFighter();	//Getter for the current fighter
	void setCurrentFighter(FighterQueue * curr);		//Setter for the current fighter
};

#endif