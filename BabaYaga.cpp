/*
Name: Josh Erickson
Description: Source file for BabaYaga class
*/

#include "BabaYaga.hpp"

BabaYaga::BabaYaga(string name) //Constructor
{
	setCreatureName(name);
	setCreatureType(BABAYAGA);	//Setting the type of creature
	setStrPts(12);	//Baba Yaga has 12 starting strength
	setArmorPts(3);	//Baba Yaga has 3 armor
	setAttackDieSides(6);	//Baba Yaga uses a 6 sided die for attack rolls
	setNumAttackDice(2);	//Baba Yaga uses a 2 die for attack rolls
	setDefenseDieSides(10);	//Baba Yaga uses a 6 sided die for defense rolls
	setNumDefenseDice(1);	//Baba Yaga uses 1 die for defense rolls
}

int BabaYaga::attack()
{
	int attack = rollAtk();

	return attack;
}

int BabaYaga::defend()
{
	int defend = rollDef();
	return defend;
}

void BabaYaga::updateStr(int defenseRolled, int attackRolled)
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

std::string BabaYaga::getCreatureName()
{
	return creatureName;
}

void BabaYaga::setCreatureName(std::string name)
{
	creatureName = name;
}