/*
Name: Josh Erickson
Description: Header file for Loserpile class
*/

#include "Creature.hpp"

#ifndef LOSERPILE_HPP
#define LOSERPILE_HPP

struct Losers
{
	Creature* loser;
	Losers* previous;
};

class Loserpile
{
private:
	Losers* current;
public:
	Loserpile();	//Constructor
	void add(Creature *loser);	//Adds to the Losers stack
	Creature* remove();		//Removes from the losers stack, returns the creature that was removed
	Losers* getCurrentLoser();	//Gets the current loser
	void setCurrentLoser(Losers* loser);	//To set the current loser
};

#endif