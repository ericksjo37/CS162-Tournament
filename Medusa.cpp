/*
Name: Josh Erickson
Description: Source file for Medusa class
*/

#include "Medusa.hpp"


Medusa::Medusa(string name)	//Constructor
{
	setCreatureName(name);
	setCreatureType(MEDUSA);	//Setting the type of creature
	setStrPts(8);	//Medusa has 8 starting strength
	setArmorPts(3);	//Medusa has 3 armor
	setAttackDieSides(6);	//Medusa uses a 6 sided die for attack rolls
	setNumAttackDice(2);	//Medusa uses a 2 die for attack rolls
	setDefenseDieSides(6);	//Medusa uses a 6 sided die for defense rolls
	setNumDefenseDice(1);	//Medusa uses 1 die for defense rolls
}

int Medusa::attack()
{
	int attack = rollAtk();

	return attack;
}

int Medusa::defend()
{
	int defend = rollDef();
	return defend;
}

void Medusa::updateStr(int defenseRolled, int attackRolled)
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

std::string Medusa::getCreatureName()
{
	return creatureName;
}

void Medusa::setCreatureName(std::string name)
{
	creatureName = name;
}