/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 2
This program will implement the methods defined in the header file*/

#include "Employees.h"
#include <iostream>
using namespace std;

/// <summary>
/// method to set value for ssid, read in only
/// </summary>
void Employees::setSsid() {
	cin >> m_ssid;
}

/// <summary>
/// method to set value for name, read in only
/// </summary>
void Employees::setName() {
	cin >> m_name;
}

/// <summary>
/// method to set value for wage, read in only
/// </summary>
void Employees::setWage() {
	cin >> m_wage;
}

/// <summary>
/// method to set value for hours, read in only
/// </summary>
void Employees::setHours() {
	cin >> m_hours;
}

/// <summary>
/// method to set value for collected money, read in only
/// </summary>
void Employees::setCollMoney() {
	cin >> m_collMoney;
}

/// <summary>
/// method to set value for collected money by parameter
/// </summary>
/// <param name="collMoney">float</param>
void Employees::setCollMoneyParm(float collMoney) {
	m_collMoney = collMoney;
}

/// <summary>
/// method to get value of ssid
/// </summary>
/// <returns>int</returns>
int Employees::getSsid() {
	
	return m_ssid;
}

/// <summary>
/// method to get value of name
/// </summary>
/// <returns>char*</returns>
char* Employees::getName() {
	
	return m_name;
}

/// <summary>
/// method to get value of wage
/// </summary>
/// <returns>float</returns>
float Employees::getWage() {
	return m_wage;
}

/// <summary>
/// method to get value of hours
/// </summary>
/// <returns>int</returns>
int Employees::getHours() {
	return m_hours;
}

/// <summary>
/// method to get value of collMoney
/// </summary>
/// <returns>float</returns>
float Employees::getCollMoney() {
	return m_collMoney;
}

/// <summary>
/// method to calculate the full salary of an employee
/// </summary>
/// <returns>float</returns>
float Employees::calcSalary() {
	float totalSalary, baseSalary;

	baseSalary = m_wage * m_hours; //calculating base salary of just wages*hours
	totalSalary = baseSalary + calcBonus(m_collMoney); //calculating total salary that include the bonus based on the money collected

	return totalSalary;
}

/// <summary>
/// method to calculate the bonus to be added to the base salary
/// </summary>
/// <param name="wages">float</param>
/// <returns>float</returns>
float Employees::calcBonus(float wages) {
	float bonus = 0;

	if (wages > 5000) {             //calculating percentage for any wages over 5000 NIS
		bonus += (wages - 5000.0) * 0.4;  //need this up here because can't fit it in switch statement
		wages = 5000;
	}
	switch ((int)wages / 1000) { //dividing wages by 1000 to put it into categories for cases
		
	case 5: case 4: //case where wages are between 4000 and 5000 NIS
		bonus += (wages - 4000.0) * 0.3;
		wages = 4000;

	case 2: case 3: //case where wages are between 2000 and 4000 NIS
		bonus += (wages - 2000.0) * 0.2;
		wages = 2000;

	case 1:  //case where wages are between 1000 and 2000 NIS 
		bonus += (wages - 1000.0) * 0.15;
		wages = 1000;

	case 0: //case where wages are less than 1000 NIS
		bonus += wages * 0.1;
	}

	return bonus;
}
