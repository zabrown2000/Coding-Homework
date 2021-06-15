/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 4 Question 1
This program will define a class Clock and its methods*/

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
using namespace std;

class Clock {

	int m_hour;
	int m_minute;
	int m_second;

public:
	//constructors
	Clock(); //default ctor
	Clock(int hour, int min, int sec); //ctor
	Clock(Clock& time); //copy ctor

	//setters and getters
	void setHour(int hour);
	void setMin(int min);
	void setSec(int sec);
	int getHour() const;
	int getMin() const;
	int getSec() const;

	Clock operator+=(int secs); //add immediate operation overload method
	friend ostream& operator<<(ostream& os, const Clock &time);//friend operation overload method for cout
	friend istream& operator>>(istream& is, Clock &time); //friend operation overload method for cin
};

#endif // !CLOCK_H
