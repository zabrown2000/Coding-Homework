/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will define a derived class Officer and its methods*/

#ifndef OFFICER_H
#define OFFICER_H

#include "Soldier.h"

class Officer : public Soldier {

protected:
	int m_socioScore;

public:

	//constructors
	Officer(int id = 0, string first = "", string last = "", int ops = 0, int score = 0);

	bool medal() override; //method that checks whether the soldier is entitled to a medal
	string soldierType() override { return "Officer"; } //method to return a soldier's type
	void print() override; //method for printing soldier data
	int getSociometric() const override;
};

#endif // !OFFICER_H



