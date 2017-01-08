/*
Name: Josh Erickson
Description: Header file for BlueMen class
*/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <iostream>

#include "Creature.hpp"

class Medusa : public Creature
{
private:
	std::string creatureName;
public:
	Medusa(string name);	//Constructor
	int attack();
	int defend();
	void updateStr(int defenseRolled, int attackRolled);
	std::string getCreatureName();
	void setCreatureName(std::string name);
};

#endif