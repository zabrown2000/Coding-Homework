/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will define a derived class Commander and its methods*/

#ifndef COMMANDER_H
#define COMMANDER_H

#include "Private.h"

class Commander : public Private {
protected:
	bool m_isCombat;

public:
	//constructors
	Commander(int id = 0, string first = "", string last = "", int ops = 0, bool combat = false);

	string soldierType() override { return "Commander"; } //method to return a soldier's type
	bool medal() override; //method that checks whether the soldier is entitled to a medal
	void print() override; //method for printing soldier data
	bool getCombat() const override; //method to get isCombat for a soldier
	void setCombat(bool combat) override; //method to set isCombat for a soldier
};

#endif // !COMMANDER_H



