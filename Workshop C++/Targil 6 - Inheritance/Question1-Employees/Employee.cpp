/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 1
This program will implement a  base class Employee and its methods*/

#include "Employee.h"
#include "FullTime.h"
#include "PartTime.h"

/// <summary>
/// constructor for class employee
/// </summary>
/// <param name="name">string</param>
/// <param name="id">int</param>
/// <param name="seni">int</param>
Employee::Employee(string name, int id, int seni, float pay) : m_name(name), m_id(id), m_seniority(seni), m_pay(pay) {}

/// <summary>
/// setter method for name field
/// </summary>
/// <param name="name">string</param>
void Employee::setName(string name) {
	m_name = name;
}

/// <summary>
/// setter emthod for id field
/// </summary>
/// <param name="id">int</param>
void Employee::setId(int id) {
	m_id = id;
}

/// <summary>
/// setter method for seniority field
/// </summary>
/// <param name="seni">int</param>
void Employee::setSeniority(int seni) {
	m_seniority = seni;
}

/// <summary>
/// setter method for pay field
/// </summary>
/// <param name="pay">flaot</param>
void Employee::setPay(float pay) {
	m_pay = pay;
}

/// <summary>
/// getter method for name field
/// </summary>
/// <returns>string</returns>
string Employee::getName() const {
	return m_name;
}

/// <summary>
/// getter method for id field
/// </summary>
/// <returns>int</returns>
int Employee::getId() const {
	return m_id;
}

/// <summary>
/// getter method for seniority field
/// </summary>
/// <returns>int</returns>
int Employee::getSeniority() const {
	return m_seniority;
}

/// <summary>
/// getter method for pay field
/// </summary>
/// <returns>float</returns>
float Employee::getPay() const {
	return m_pay;
}

/// <summary>
/// method to update a salary according to bonus guidelines
/// </summary>
/// <returns></returns>
float Employee::salaryAfterBonus() {
	
	if (m_seniority <= 5) {
		//m_pay += 500; //don't know if want to change it or just return it
		return (m_pay + 500); //returning current pay + 500
	}
	if (m_seniority > 5) {
		return (m_pay + (0.25 * m_pay)); //returning current pay + 25% of current pay
	}
}

/// <summary>
/// friend overloading function for cin
/// </summary>
/// <param name="is">istream&</param>
/// <param name="worker">Employee&</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, Employee& worker) {
	
	cout << "Enter employee details:\n";

	is >> worker.m_name >> worker.m_id >> worker.m_seniority >> worker.m_pay;

	if (worker.m_id <= 0) { //if user enters negative value for id
		throw "ERROR";
	}
	if (worker.m_seniority < 0) { //if user enters negative value for number of years
		throw "ERROR";
	}
	if (worker.m_pay < 0) { //if user enters negative value for salary
		throw "ERROR";
	}

	return is;
}

ostream& operator<<(ostream& os, const Employee& worker) {
	
	os << "Employee: " << worker.m_name << endl;
	os << "Employee ID: " << worker.m_id << endl;
	os << "Years Seniority: " << worker.m_seniority << endl;

	return os;
}


