/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 2
This program will implement methods for the date class*/

#include "Date.h"
#include<iostream>
using namespace std;

/// <summary>
/// constructor with default values built in
/// </summary>
/// <param name="day">int</param>
/// <param name="month">int</param>
/// <param name="year">int</param>
Date::Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year){ //using parameter intialization

	if ((day < 1) || (day > 30)) { //checking if input from user falls in correct range of 1-30
		cout << "Error day\n";
		m_day = 1; //assigning default value
	}
	if ((month < 1) || (month > 12)) { //checking if input from user falls in correct range of 1-12
		cout << "Error month\n";
		m_month = 1; //assigning default value
	}
	if ((year < 1920) || (year > 2099)) { //checking if input from user falls in correct range of 1970-2099
		cout << "Error year\n";
		m_year = 1920; //assigning default value
	}
}

/// <summary>
/// copy constructor
/// </summary>
/// <param name="date">const cbr Date</param>
Date::Date(const Date& date) {
	this->m_day = date.m_day; //copying values over
	this->m_month = date.m_month;
	this->m_year = date.m_year;
}

/// <summary>
/// method to update the entire date (all fields)
/// </summary>
/// <param name="day">int</param>
/// <param name="month">int</param>
/// <param name="year">int</param>
void Date::setDate(int day, int month, int year) {

	//3 ifs to check if each parameter sent is valid, if even one is out of range the function ends
	if ((day < 1) || (day > 30)) { return; }
	if ((month < 1) || (month > 12)) { return; }
	if ((year < 1920) || (year > 2099)) { return; }

	//if got to this point all values are valid so can just assign them to the object
	m_day = day;
	m_month = month;
	m_year = year; 
}

/// <summary>
/// pre-increment operation overload method
/// </summary>
/// <returns>Date</returns>
Date Date::operator++() {
	
	if (m_day == 30) { //if the day is already 30 need to reset to 1 and add to month
		
		return adjustDate(*this); //sending object to have date adjusted accordingly and then returning value because did what needed to do
	}
	m_day++; //day is below 30 so can add 1 to it easily
	return *this;
}

Date Date::operator++(int u) {
	
	Date temp = *this; //since post, returning object as it was before incremented

	if (m_day == 30) { //if the day is already 30 need to reset to 1 and add to month
		
		*this = adjustDate(*this); //sending object to have date adjusted accordingly
		return temp; //can return now, did the necessary updates to actual object
	}
	m_day++; //day is below 30 so can add 1 to it easily
	return temp;
}

/// <summary>
/// add immediate operation overload method
/// </summary>
/// <param name="add">int</param>
Date Date::operator+=(int add) {
	
	if (add <= 0) {
		return *this; //invalid amount to add, leave function
	}
	//made while instead of if for cases when the amount of days to be added results in more than 1 month being added
	while ((m_day + add) > 30) { //as long as when add the days it's >30 need to adjust the date to accomodate the overflow
		int temp = m_day; 
		*this = adjustDate(*this); //sending object to have date adjusted accordingly
		m_day = (temp + add) - temp; //now that date is adjested can stick in the overflow days
		return *this; //updated the date so can leave now
	}
	
	m_day += add;
	return *this;
}

/// <summary>
/// greater than operation overload method (to find if left date is later than right)
/// </summary>
/// <param name="date">const cbr Date</param>
/// <returns>bool</returns>
bool Date::operator>(const Date& date) const {

	if (this->m_year == date.m_year) {
		
		if (this->m_month == date.m_month) {

			if (this->m_day <= date.m_day) { //if got to here that means the left date is earlier or the dates are equal
				return false;
			}
		}
		if (this->m_month < date.m_month) { //left month is earlier than right (same year)
			return false; 
		}
	}
	if (this->m_year < date.m_year) { //left year is earlier than right year
		return false; 
	}
	return true; //if got to this point then the entire left date is later than the right date
}

/// <summary>
/// less than operation overload method (to find if left date is earlier than right)
/// </summary>
/// <param name="date">const cbr Date</param>
/// <returns>bool</returns>
bool Date::operator<(const Date& date) const {
	
	if (this->m_year == date.m_year) {

		if (this->m_month == date.m_month) {

			if (this->m_day >= date.m_day) { //if got to here that means the left date is later or the dates are equal
				return false;
			}
		}
		if (this->m_month > date.m_month) { //left month is later than right (same year)
			return false;
		}
	}
	if (this->m_year > date.m_year) { //left year is later than right year
		return false;
	}
	return true; //if got to this point then the entire left date is earlier than the right date
}

bool Date::operator==(const Date& date) const {
	
	if (m_day == date.m_day) {
		if (m_month == date.m_month) {
			if (m_year == date.m_year) {
				return true; //all fields are equal so return true
			}
		}
	}
	return false; //at least one of fields not equal so return false
}

/// <summary>
/// method to print the object
/// </summary>
void Date::print() const {
	 
	cout << m_day << "/" << m_month << "/" << m_year << endl;
}

/// <summary>
/// helper method to take into account overflow of date when day>30
/// </summary>
/// <param name="date">Date</param>
/// <returns>Date</returns>
Date Date::adjustDate(Date date) {
	
	date.m_day = 1;
	date.m_month++;

	if (date.m_month > 12) { //now need to check if month>12, in which case would reset to 1 and add to year
		date.m_month = 1;
		date.m_year++;
	}
	return date;
}

