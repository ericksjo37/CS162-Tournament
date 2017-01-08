/*
Name: Josh Erickson
Description: Header file for BlueMen class
*/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <iostream>

#include "Creature.hpp"

class BlueMen : public Creature
{
private:
	std::string creatureName;
public:
	BlueMen(string name);	//Constructor
	int attack();
	int defend();
	void updateStr(int defenseRolled, int attackRolled);
	std::string getCreatureName();
	void setCreatureName(std::string name);
};

#endif