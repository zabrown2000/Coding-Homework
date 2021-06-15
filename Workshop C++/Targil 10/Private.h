/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will define a derived class Private and its methods*/

#ifndef PRIVATE_H
#define PRIVATE_H

#include "Soldier.h"

class Private : public Soldier {

protected:
	float* m_grades;

public:
	//constrctors
	Private(int id = 0, string first = "", string last = "", int ops = 0); //ctor
	~Private(); //dtor
	Private(const Private& p); //copy ctor
	Private(Private&& p) noexcept; //move ctor

	string soldierType() override { return "Private"; } //method to return a soldier's type
	bool medal() override; //method that checks whether the soldier is entitled to a medal
	void print() override; //method for printing soldier data
	float* getGrades() const override; //method to get grades for a soldier
	void setGrades() override; //method to set grades for soldier

protected:
	float average(); //helper method to calculate average of grades
};

#endif // !PRIVATE_H




