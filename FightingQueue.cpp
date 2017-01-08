/*
Name: Josh Erickson
Description: Source file for FightingQueue class
*/

#include "FightingQueue.hpp"

FightingQueue::FightingQueue(std::string name)	//Constructor
{
	teamName = name;	//Setting the team name
	current = NULL;		//Initializing the queue with NULL
}

void FightingQueue::add(Creature* fighter)	//Add the passed parameter to queue
{
	FighterQueue* queue = new FighterQueue;	//New fighter structure
	queue->next = NULL;
	queue->previous = NULL;
	queue->fighter = fighter;

	FighterQueue* currentFighter = current;
	FighterQueue* lastFighter = currentFighter;
	if (currentFighter == NULL)
	{
		current = queue;
	}
	else
	{
		while (lastFighter->next != NULL)
		{
			lastFighter = lastFighter->next;
		}
		lastFighter->next = queue;
		queue->previous = lastFighter;
	}
}

Creature* FightingQueue::remove()	//Remove an item from the queue and return the creature that was removed
{
	FighterQueue *currentFighter = current;
	FighterQueue *nextFighter = currentFighter->next;
	current = nextFighter;

	Creature *fighter = currentFighter->fighter;
	delete currentFighter;
	return fighter;
}


/*
Getters/Setters
*/

std::string FightingQueue::getTeamName()		//Getter for the team name
{
	return teamName;
}

void FightingQueue::setTeamName(std::string name)	//Setter for the team name
{
	teamName = name;
}

FighterQueue* FightingQueue::getCurrentFighter()	//Getter for the current fighter
{
	return current;
}

void FightingQueue::setCurrentFighter(FighterQueue * curr)		//Setter for the current fighter
{
	current = curr;
}
