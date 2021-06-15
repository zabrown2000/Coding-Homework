/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 2
This program will define a class date and its methods*/

#ifndef DATE_H
#define DATE_H

class Date {
	
	int m_day;
	int m_month;
	int m_year;

public:
	Date(int day = 1, int month = 1, int year = 1920); //constructor with default values built in
	Date(const Date& date); //copy constructor
	
	void setDate(int day, int month, int year); //method to update the entire date (all fields)
	Date operator++(); //pre-increment operation overload method
	Date operator++(int u); //post-increment operation overload method
	Date operator+=(int add); //add immediate operation overload method
	bool operator>(const Date& date) const; //greater than operation overload method (to find if left date is later than right)
	bool operator<(const Date& date) const; //less than operation overload method (to find if left date is earlier than right)
	bool operator==(const Date& date) const; //is equal operation overload method
	void print() const; //method to print the object

private:
	//below method only accessible by above methods
	Date adjustDate(Date date); //helper method to take into account overflow of date when day>30
};

#endif //!DATE_H