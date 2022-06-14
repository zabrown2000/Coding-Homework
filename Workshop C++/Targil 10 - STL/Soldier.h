/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will define a base class Soldier and its methods*/

#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include <iostream>
using namespace std;

class Soldier {

protected:
	int m_id;
	string m_firstName;
	string m_lastName;
	int m_numOps;

public:
	//constructors
	Soldier(int id = 0, string first = "", string last = "", int ops = 0);
	virtual ~Soldier(); 

	//pure virtuals to be implemented in each derived class
	virtual bool medal() = 0; //method that checks whether the soldier is entitled to a medal
	virtual string soldierType() = 0; //method to return a soldier's type
	
	virtual void print(); //method for printing soldier data

	//getters
		//non-virtuals because the same in all classes
	virtual int getID() const;
	virtual string getFirst() const;
	virtual string getLast() const;
	virtual int getOps() const;

		//virtuals for fields unique to some classes, will throw for classes without the fields
	virtual float* getGrades() const; //method to get grades for a soldier (overriden only in private and commander classes)
	virtual bool getCombat() const; //method to get isCombat for a soldier (overriden only in commander class)
	virtual int getSociometric() const; //method to get score for a soldier (overriden only in officer class)

	//setters
	virtual void setGrades(); //method to set grades for a soldier (overriden only in private and commander classes)
	virtual void setCombat(bool combat); // method to set isCombat for a soldier(overriden only in commander class)

	
};

#endif // !SOLDIER_H



