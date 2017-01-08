/*
Name: Josh Erickson
Description: Source file for Barbarian class
*/

#include "Barbarian.hpp"

Barbarian::Barbarian(string name)	//Constructor
{
	setCreatureName(name);
	setCreatureType(BARBARIAN);	//Setting the type of creature
	setStrPts(12);	//Barbarians have 12 starting strength
	setArmorPts(0);	//Barbarians have no armor
	setAttackDieSides(6);	//Barbarians use 6 sided dice for attack rolls
	setNumAttackDice(2);	//Barbarians use 2 dice for attack rolls
	setDefenseDieSides(6);	//Barbarians use 6 sided dice for defense rolls
	setNumDefenseDice(2);	//Barbarians use 2 dice for defense rolls
}

int Barbarian::attack()
{
	int attack = rollAtk();
	return attack;
}

int Barbarian::defend()
{
	int defend = rollDef();
	return defend;
}

void Barbarian::updateStr(int defenseRolled, int attackRolled)
{
	int strength = getStrPts();
	int armor = getArmorPts();
	int damage = attackRolled - (defenseRolled + armor);

	if (damage > 0)
	{
		setStrPts(strength - damage);
	}

	if (getStrPts() <= 0)
	{
		setLife(false);	//If the creature has 0 or less strength, set life to false
	}
}

std::string Barbarian::getCreatureName()
{
	return creatureName;
}

void Barbarian::setCreatureName(std::string name)
{
	creatureName = name;
}