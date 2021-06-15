/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 1
This program will implement a derived class PartTime
and its methods*/

#include "PartTime.h"

/// <summary>
/// default ctor for Parttime class
/// </summary>
PartTime::PartTime() : m_hoursWorked(0), m_rateHour(0) {
	/*setName("");
	setId(0);
	setSeniority(0);
	setPay(0);*/
	Employee(); //calling ctor to set default values
}

/// <summary>
/// ctor with parameters for PartTime class
/// </summary>
/// <param name="name">string</param>
/// <param name="id">int</param>
/// <param name="seni">int</param>
/// <param name="hours">int</param>
/// <param name="rate">float</param>
PartTime::PartTime(string name, int id, int seni, int hours, float rate) : m_hoursWorked(hours), m_rateHour(rate) {
	Employee(name, id, seni); //calling ctor to set values to fields that overlap
}

/// <summary>
/// setter method for hours worked field
/// </summary>
/// <param name="hours">int</param>
void PartTime::setHoursWorked(int hours) {
	m_hoursWorked = hours;
}

/// <summary>
/// setter method for rate hour field
/// </summary>
/// <param name="rate">float</param>
void PartTime::setRate(float rate) {
	m_rateHour = rate;
}

/// <summary>
/// getter method for hours worked field
/// </summary>
/// <returns>int</returns>
int PartTime::getHoursWorked() const {
	return m_hoursWorked;
}

/// <summary>
/// getter method for rate hour field
/// </summary>
/// <returns>float</returns>
float PartTime::getRate() const {
	return m_rateHour;
}

/// <summary>
/// method to calculate monthly salary 
/// </summary>
/// <returns>float</returns>
float PartTime::salary() {
	return (m_hoursWorked * m_rateHour); //returning hourly wage * amount of hours worked that month
}

/// <summary>
/// method to update a salary according to bonus guidelines
/// </summary>
/// <returns>float</returns>
float PartTime::salaryAfterBonus() {
	float monthSal = salary(); //getting monthly salary since no field for it
	
	setPay(monthSal); //employee method uses m_pay field, so setting it so can call employee method
	return Employee::salaryAfterBonus(); //returning whatever the employee method returns
}

/// <summary>
/// friend overloading function for cin - rewrote because too complicated with extra fields
/// </summary>
/// <param name="is">istream&</param>
/// <param name="worker">PartTime&</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, PartTime& worker) {
	
	cout << "Enter employee details:\n";

	is >> worker.m_name >> worker.m_id >> worker.m_seniority >> worker.m_hoursWorked >> worker.m_rateHour;

	if (worker.m_id <= 0) { //if user enters negative value for id
		throw "ERROR";
	}
	if (worker.m_seniority < 0) { //if user enters negative value for number of years
		throw "ERROR";
	}
	if (worker.m_rateHour < 0) {
		throw "ERROR";
	}
	if (worker.m_hoursWorked < 0) { //if user enters negative value for salary
		throw "ERROR";
	}

	return is;
}

/// <summary>
/// friend overloading function for cout - rewrote, got exception errors when tried to call employee's in this one
/// </summary>
/// <param name="os">ostrem&</param>
/// <param name="worker">PartTime</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, PartTime& worker) {
	
	os << "Employee: " << worker.m_name << endl;
	os << "Employee ID: " << worker.m_id << endl;
	os << "Years Seniority: " << worker.m_seniority << endl;
	os << "Hours: " << worker.m_hoursWorked << endl;
	os << "Salary per Month: " << worker.salary() << endl;

	return os;
}