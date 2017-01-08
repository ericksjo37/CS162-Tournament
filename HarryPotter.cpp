/*
Name: Josh Erickson
Description: Source file for HarryPotter class
*/

#include "HarryPotter.hpp"

HarryPotter::HarryPotter(string name) //Constructor
{
	setCreatureName(name);
	setCreatureType(HARRYPOTTER);	//Setting the type of creature
	setStrPts(10);	//Harry Potter has 10 starting strength
	setArmorPts(0);	//Harry Potter has no armor
	setAttackDieSides(6);	//Harry Potter uses a 6 sided die for attack rolls
	setNumAttackDice(2);	//Harry Potter uses a 2 die for attack rolls
	setDefenseDieSides(6);	//Harry Potter uses a 6 sided die for defense rolls
	setNumDefenseDice(2);	//Harry Potter uses 2 dice for defense rolls
}

int HarryPotter::attack()
{
	int attack = rollAtk();
	return attack;
}

int HarryPotter::defend()
{
	int defend = rollDef();
	return defend;
}

void HarryPotter::updateStr(int defenseRolled, int attackRolled)
{
	int strength = getStrPts();
	int armor = getArmorPts();
	int damage = attackRolled - (defenseRolled + armor);

	if (damage > 0)
	{
		setStrPts(strength - damage);
	}

	if (getStrPts() <= 0 && beenRevived == false)
	{
		setStrPts(10);	//If harry has not been revived once already and his strength is less than 0, revive him with 10 strength
		beenRevived = true;
		std::cout << "Harry will revive with 10 strength this turn!\n" << std::endl;
	}

	if (getStrPts() <= 0)
	{
		setLife(false);	//If the creature has 0 or less strength, set life to false
	}
}

std::string HarryPotter::getCreatureName()
{
	return creatureName;
}

void HarryPotter::setCreatureName(std::string name)
{
	creatureName = name;
}

void HarryPotter::setBeenRevived(bool revived)
{
	beenRevived = revived;
}