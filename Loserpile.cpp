/*
Name: Josh Erickson
Description: Source file for Loserpile class
*/

#include "Loserpile.hpp"

Loserpile::Loserpile()	//Constructor
{
	current = NULL;
}

void Loserpile::add(Creature *loser)	//Adds to the Losers stack
{
	Losers* stack = new Losers;
	Losers* currentLoser = current;
	stack->previous = currentLoser;
	stack->loser = loser;
	current = stack;
}

Creature* Loserpile::remove()		//Removes from the losers stack, returns the creature that was removed
{
	Losers* currentLoser = current;
	Losers* lastLoser = currentLoser->previous;
	current = lastLoser;
	Creature* loser = currentLoser->loser;
	delete currentLoser;
	return loser;
}


/*
Getters/Setters
*/


Losers* Loserpile::getCurrentLoser()	//Gets the current loser
{
	return current;
}

void Loserpile::setCurrentLoser(Losers* loser)	//To set the current loser
{
	current = loser;
}
