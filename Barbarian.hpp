/*
Name: Josh Erickson
Description: Header file for Barbarian class
*/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian : public Creature
{
private:
	std::string creatureName;
public:
	Barbarian(string name);
	int attack();
	int defend();
	void updateStr(int defenseRolled, int attackRolled);
	std::string getCreatureName();
	void setCreatureName(std::string name);
};

#endif