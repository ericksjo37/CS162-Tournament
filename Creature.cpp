/*
Name: Josh Erickson
Description: Source file for the Creature class. This will be an abstract class.
*/

#include "Creature.hpp"

Creature::Creature()	//Constructor
{
	setLife(true);
}

int Creature::rollDie(int numSides)	//Rolls the dice that is passed to it, returns a random number in that range
{
	int roll;	//Integer to hold the roll that will be returned
	roll = (rand() % numSides) + 1;	//Get a random number from 0 - numSides and add 1
	return roll;
}

int Creature::rollAtk()	//Rolls for the attack value
{
	int roll = 0;	//Initializing this roll variable to 0 every time this function is called
	int numSides = getAttackDieSides();	//Set the number of sides for the die equal to the number specific for that creature
	int numDies = getNumAttackDice();	//Sets the number of dies equal to the number of attack dice specific for that creature

	for (int i = 0; i < numDies; i++)
	{
		roll += rollDie(numSides);
	}

	return roll;
}

int Creature::rollDef()	//Rolls for the defense value
{
	int roll = 0;	//Initializing this roll variable to 0 every time this function is called
	int numSides = getDefenseDieSides();	//Set the number of sides for the die equal to the number specific for that creature
	int numDies = getNumDefenseDice();		//Sets the number of dies equal to the number of defense dice specific for that creature

	for (int i = 0; i < numDies; i++)
	{
		roll += rollDie(numSides);
	}

	return roll;
}







/*
All get and set methods
*/

int Creature::getStrPts()	//Gets the strength points
{
	return strPts;
}

void Creature::setStrPts(int str)	//Sets the strength points
{
	strPts = str;
}

int Creature::getArmorPts()	//Gets the armor points
{
	return armorPts;
}

void Creature::setArmorPts(int armor)	//Sets the armor points
{
	armorPts = armor;
}

void Creature::setCreatureType(Creatures type)	//Sets the creature type
{
	creatureType = type;
}

Creatures Creature::getCreatureType()	//Returns the creature type
{
	return creatureType;
}

bool Creature::getLife()	//Returns the life status
{
	return life;
}

void Creature::setLife(bool status)	//Set the life status
{
	life = status;
}

int Creature::getNumAttackDice()		//Returns the number of attack dice
{
	return numAttackDice;
}

int Creature::getNumDefenseDice()	//Returns the number of defense dice
{
	return numDefenseDice;
}

void Creature::setNumAttackDice(int atkDice)	//Set the number of attack dice
{
	numAttackDice = atkDice;
}

void Creature::setNumDefenseDice(int defDice)	//Set the number of defense dice
{
	numDefenseDice = defDice;
}

int Creature::getAttackDieSides()	//Returns the number of sides on the attack die
{
	return attackDieSides;
}

int Creature::getDefenseDieSides()	//Returns the number of sides on the defense die
{
	return defenseDieSides;
}

void Creature::setAttackDieSides(int atkSides)	//Sets the number of sides on the attack die
{
	attackDieSides = atkSides;
}

void Creature::setDefenseDieSides(int defSides)	//Sets the number of sides on the defense die
{
	defenseDieSides = defSides;
}

string Creature::getCreatureName()	//Gets the creatures name
{
	return "";
}

void Creature::setCreatureName(string name)	//Set the creature name
{
	//
}



