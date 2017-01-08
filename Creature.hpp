/*
Name: Josh Erickson
Description: Header file for the Creature class. This will be an abstract class.
*/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

using std::string;

enum Creatures { MEDUSA, BARBARIAN, BABAYAGA, BLUEMEN, HARRYPOTTER };

class Creature
{
protected:
	int strPts;	//Integer to hold the current strength variable
	int armorPts;	//Integer to hold the current armor variable
	int numAttackDice, numDefenseDice;	//Integers to hold the number of attack and defense dice for a creature
	int attackDieSides, defenseDieSides;	//Integers to hold the number of sides on the dice
	Creatures creatureType;	//Will hold the enum value for the creature type
	bool life = true;	//Variable to hold true for living, false for dead
	string creatureName;	//Hold the creature name
public:
	Creature();	//Constructor
	Creatures getCreatureType();	//Returns the creature type
	void setCreatureType(Creatures);	//Sets the creature type
	bool getLife();	//Returns the life status
	void setLife(bool life);	//Set the life status
	int getStrPts();	//Gets the strength points
	void setStrPts(int str);	//Sets the strength points
	int getArmorPts();	//Gets the armor points
	void setArmorPts(int armor);	//Sets the armor points
	int getNumAttackDice();		//Returns the number of attack dice
	int getNumDefenseDice();	//Returns the number of defense dice
	void setNumAttackDice(int atkDice);	//Set the number of attack dice
	void setNumDefenseDice(int defDice);	//Set the number of defense dice
	int getAttackDieSides();	//Returns the number of sides on the attack die
	int getDefenseDieSides();	//Returns the number of sides on the defense die
	void setAttackDieSides(int atkSides);	//Sets the number of sides on the attack die
	void setDefenseDieSides(int defSides);	//Sets the number of sides on the defense die
	virtual string getCreatureName();	//Gets the creatures name
	virtual void setCreatureName(string name);	//Set the creature name
	int rollDie(int numSides);	//Rolls the dice that is passed to it, returns a random number in that range
	int rollAtk();	//Rolls for the attack value
	int rollDef();	//Rolls for the defense value
	virtual int attack() = 0;	//Virtual attack function, setting to 0 here, for use in child classes
	virtual int defend() = 0;	//Virtual defense function, setting to 0 here, for use in child classes
	virtual void updateStr(int defenseRolled, int attackRolled) = 0;	//Virtual function to update the strength variable for each creature
	virtual void setBeenRevived(bool revived) {};

};

#endif
