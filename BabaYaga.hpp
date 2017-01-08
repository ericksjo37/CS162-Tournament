/*
Name: Josh Erickson
Description: Header file for BabaYaga class
*/

#ifndef BABYAGA_HPP
#define BABAYAGA_HPP

#include "Creature.hpp"

class BabaYaga : public Creature
{
private:
	std::string creatureName;
public:
	BabaYaga(string name);	//Constructor
	int attack();
	int defend();
	void updateStr(int defenseRolled, int attackRolled);
	std::string getCreatureName();
	void setCreatureName(std::string name);
};

#endif