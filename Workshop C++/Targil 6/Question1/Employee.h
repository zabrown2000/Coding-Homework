/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 1
This program will define a base class Employee and its methods*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee {

protected:
	string m_name;
	int m_id;
	int m_seniority;
	float m_pay;

public:
	//constructor
	Employee(string name = "", int id = 0, int seni = 0, float pay = 0); 

	//setters and getters (to be used by the inheriting classes)
	void setName(string name);
	void setId(int id);
	void setSeniority(int seni);
	void setPay(float pay);
	string getName() const;
	int getId() const;
	int getSeniority() const;
	float getPay() const;

	float salaryAfterBonus(); //method to update a salary according to bonus guidelines

	//friend functionss
	friend istream& operator>>(istream& is, Employee& worker); //friend overloading function for cin
	friend ostream& operator<<(ostream& os, const Employee& worker); //friend overloading function for cout
};

#endif //!EMPLOYEE_H

