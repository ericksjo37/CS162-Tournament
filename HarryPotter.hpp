/*
Name: Josh Erickson
Description: Header file for HarryPotter class
*/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <iostream>

#include "Creature.hpp"

class HarryPotter : public Creature
{
private:
	std::string creatureName;
	bool beenRevived = false;
public:
	HarryPotter(string name);	//Constructor
	int attack();
	int defend();
	void updateStr(int defenseRolled, int attackRolled);
	std::string getCreatureName();
	void setCreatureName(std::string name);
	void setBeenRevived(bool revived);
};

#endif