/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 1
This program will define a derived class FullTime 
and its methods*/

#ifndef FULLTIME_H
#define FULLTIME_H

#include "Employee.h"

class FullTime : public Employee {

	float m_annualSalary;

public:
	//constructors
	FullTime(string name, int id, int seni, float annualSal); //ctor with parameters
	FullTime(); //default ctor

	//setter and getter
	void setAnnualSalary(float sal);
	float getAnnualSalary() const;

	float salary(); //method to calculate monthly salary 
	float salaryAfterBonus(); //method to update a salary according to bonus guidelines

	//friend functions
	friend istream& operator>>(istream& is, FullTime& worker); //friend overloading function for cin for FullTime
	friend ostream& operator<<(ostream& os, FullTime& worker); //friend overloading function for cout for FullTime
};

#endif //!FULLTIME_H

