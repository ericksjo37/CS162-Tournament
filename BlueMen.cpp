/*
Name: Josh Erickson
Description: Source file for BlueMen class
*/

#include "BlueMen.hpp"

BlueMen::BlueMen(string name)	//Constructor
{
	setCreatureName(name);
	setCreatureType(BLUEMEN);	//Setting the type of creature
	setStrPts(12);	//Blue Men have 12 starting strength
	setArmorPts(3);	//Blue Men have 3 armor
	setAttackDieSides(10);	//Blue Men use 10 sided dice for attack rolls
	setNumAttackDice(2);	//Blue Men use 2 dice for attack rolls
	setDefenseDieSides(6);	//Blue Men use 6 sided dice for defense rolls
	setNumDefenseDice(3);	//Blue Men use 3 dice for defense rolls
}

int BlueMen::attack()
{
	int attack = rollAtk();
	return attack;
}

int BlueMen::defend()
{
	int defend = rollDef();
	return defend;
}

void BlueMen::updateStr(int defenseRolled, int attackRolled)
{
	int strength = getStrPts();
	int armor = getArmorPts();
	int damage = attackRolled - (defenseRolled + armor);

	if (damage > 0)
	{
		setStrPts(strength - damage);
	}

	if ((getStrPts() <= 8) && (getStrPts() >= 5))
	{
		setNumDefenseDice(2);	//If the Blue Men have between 5 and 8 strength, they only get two defense dice
		std::cout << "The Blue Men will have 2 defense dice left after this turn" << std::endl;
	}

	if ((getStrPts() <= 4) && (getStrPts() >= 0))
	{
		setNumDefenseDice(1);	//If the Blue Men have between 0 and 4 strength, they only get 1 defense die
		std::cout << "The Blue Men will have 1 defense die left after this turn" << std::endl;
	}

	if (getStrPts() <= 0)
	{
		setLife(false);	//If the creature has 0 or less strength, set life to false
	}
}

std::string BlueMen::getCreatureName()
{
	return creatureName;
}

void BlueMen::setCreatureName(std::string name)
{
	creatureName = name;
}