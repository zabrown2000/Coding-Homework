/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 1
This program will implement a derived class FullTime
and its methods*/

#include "FullTime.h"

/// <summary>
/// ctor with parameters for class FullTime
/// </summary>
/// <param name="name">string</param>
/// <param name="id">int</param>
/// <param name="seni">int</param>
/// <param name="annualSal">float</param>
FullTime::FullTime(string name, int id, int seni, float annualSal) : m_annualSalary(annualSal) {
	Employee(name, id, seni); //calling ctor for employee to set all the values besides for new one for fulltime
}

/// <summary>
/// default ctor for class FullTime
/// </summary>
FullTime::FullTime() {
	Employee(); //calling ctor to set values to default
	/*setName("");
	setId(0);
	setSeniority(0);
	setPay(0);*/
	m_annualSalary = 0;
}

/// <summary>
/// setter method for annual salary field
/// </summary>
/// <param name="sal">float</param>
void FullTime::setAnnualSalary(float sal) {
	m_annualSalary = sal;
}

/// <summary>
/// getter method for annual salary field
/// </summary>
/// <returns>float</returns>
float FullTime::getAnnualSalary() const {
	return m_annualSalary;
}

/// <summary>
/// method to calculate monthly salary 
/// </summary>
/// <returns></returns>
float FullTime::salary() {
	return (m_annualSalary / 12); //returning monthly salary based on annual salary
}

/// <summary>
/// method to update a salary according to bonus guidelines
/// </summary>
/// <returns>float</returns>
float FullTime::salaryAfterBonus() {
	float monthSal = salary(); //getting monthly salary since no field for it
	//
	//if (m_seniority <= 5) {
	//	return (monthSal + 500); //returning monthly pay + 500
	//}
	//if (m_seniority > 5) {
	//	return (monthSal + (0.25 * monthSal)); //returning monthly pay + 25% of monthly pay
	//}
	setPay(monthSal); //employee method uses m_pay field, so setting it so can call employee method
	return Employee::salaryAfterBonus(); //returning whatever the employee method returns
}

/// <summary>
/// friend overloading function for cin - rewrote because too complicated with extra field
/// </summary>
/// <param name="is">istream&</param>
/// <param name="worker">FullTime&</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, FullTime& worker) {

	cout << "Enter employee details:\n";

	is >> worker.m_name >> worker.m_id >> worker.m_seniority >> worker.m_annualSalary;
	if (worker.m_id <= 0) { //if user enters negative value for id
		throw "ERROR";
	}
	if (worker.m_seniority < 0) { //if user enters negative value for number of years
		throw "ERROR";
	}
	if (worker.m_annualSalary < 0) { //if user enters negative value for salary
		throw "ERROR";
	}
	return is;
}

/// <summary>
/// friend overloading function for cout - rewrote, got exception errors when tried to call employee's in this one
/// </summary>
/// <param name="os">ostream&</param>
/// <param name="worker">FullTime&</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, FullTime& worker) {

	os << "Employee: " << worker.m_name << endl;
	os << "Employee ID: " << worker.m_id << endl;
	os << "Years Seniority: " << worker.m_seniority << endl;
	os << "Salary per Month: " << worker.salary() << endl;

	return os;
}