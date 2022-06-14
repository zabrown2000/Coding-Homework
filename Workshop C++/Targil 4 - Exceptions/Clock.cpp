/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 4 Question 1
This program will implement a class Clock and its methods*/

#include "Clock.h"
//using namespace std;

/// <summary>
/// default constructor that sets the time to 00:00:00 
/// </summary>
Clock::Clock() { 
	m_hour = 00;
	m_minute = 00;
	m_second = 00;
}

/// <summary>
/// constructor that accepts parameters
/// </summary>
/// <param name="hour">int</param>
/// <param name="min">int</param>
/// <param name="sec">int</param>
Clock::Clock(int hour, int min, int sec) : m_hour(hour), m_minute(min), m_second(sec) {
	
	try {
		if ((m_hour > 23) || (m_hour < 0)) {
			throw 'h'; //throwing error for invalid hour input
		}
		if ((m_minute > 59) || (m_minute < 0)) {
			throw 'm'; //throwing error for invalid minute input
		}
		if ((m_second > 59) || (m_second < 0)) {
			throw 's'; //throwing error for invalid second input
		}
	}
	catch (char c) { //catching errors for invalid time input
		//will go through all possible error types and provide the correct error message
		if (c == 'h') {
			if (m_hour > 23) { 
				cout << "Invalid time – more than 24 hours\n";
			}
			if (m_hour < 0) {
				cout << "Invalid time – negative number of hours\n";
			}
		}
		if (c == 'm') {
			if (m_minute > 60) {
				cout << "Invalid time – more than 60 minutes\n";
			}
			if (m_minute < 0) {
				cout << "Invalid time – negative number of minutes\n";
			}
		}
		if (c == 's') {
			if (m_second > 60) {
				cout << "Invalid time – more than 60 seconds\n";
			}
			if (m_second < 0) {
				cout << "Invalid time – negative number of seconds\n";
			}
		}
		m_hour = m_minute = m_second = 00; //default time set to if 1 of inputed values was invalid
	}
}

/// <summary>
/// copy contructor
/// </summary>
/// <param name="time">clock&</param>
Clock::Clock(Clock& time) {
	this->m_hour = time.m_hour;
	this->m_minute = time.m_minute;
	this->m_second = time.m_second;
}

/// <summary>
/// setter method for hour field
/// </summary>
/// <param name="hour">int</param>
void Clock::setHour(int hour) {            
	try {
		if ((hour > 23) || (hour < 0)) throw hour; //if user entered invalid hour input, throw the value to catch
		m_hour = hour;
	}
	catch (int x) { //now checking which error message to execute
		if (x > 23) {
			cout << "Invalid time – more than 24 hours\n";
		}
		if (x < 0) {
			cout << "Invalid time – negative number of hours\n";
		}
		m_hour = m_minute = m_second = 00; //default time set to if 1 of inputed values was invalid
	}
}

/// <summary>
/// setter method for minute field
/// </summary>
/// <param name="min">int</param>
void Clock::setMin(int min) {
	try {
		if ((min > 59) || (min < 0)) throw min; //if user entered invalid minute input, throw the value to catch
		m_minute = min;
	}
	catch (int x) { //now checking which error message to execute
		if (x > 60) {
			cout << "Invalid time – more than 60 minutes\n";
		}
		if (x < 0) {
			cout << "Invalid time – negative number of minutes\n";
		}
		m_hour = m_minute = m_second = 00; //default time set to if 1 of inputed values was invalid
	}
}


/// <summary>
/// setter method for second field
/// </summary>
/// <param name="sec">int</param>
void Clock::setSec(int sec) {
	try {
		if ((sec > 59) || (sec < 0)) throw sec; //if user entered invalid second input, throw the value to catch
		m_second = sec;
	}
	catch (int x) { //now checking which error message to execute
		if (x > 60) {
			cout << "Invalid time – more than 60 seconds\n";
		}
		if (x < 0) {
			cout << "Invalid time – negative number of seconds\n";
		}
		m_hour = m_minute = m_second = 00; //default time set to if 1 of inputed values was invalid
	}
}

/// <summary>
/// getter method for hour field
/// </summary>
/// <returns>int</returns>
int Clock::getHour() const {
	return m_hour;
}

/// <summary>
/// getter method for minute field
/// </summary>
/// <returns>int</returns>
int Clock::getMin() const {
	return m_minute;
}

/// <summary>
/// getter method for second field
/// </summary>
/// <returns>int</returns>
int Clock::getSec() const {
	return m_second;
}

/// <summary>
/// add immediate operation overload method
/// </summary>
/// <param name="secs">int</param>
/// <returns>Clock</returns>
Clock Clock::operator+=(int secs) { 
	m_second += secs; 

	if (m_second > 59) { //if new value for seconds is too big
		++m_minute; 
		m_second -= 60; //gave excess seconds to minute so can get rid of them

		if (m_minute > 59) { //if value for minutes is too big
			++m_hour;
			m_minute -= 60; //gave excess minutes to hour so can get rid of them

			if (m_hour > 23) { //if new value for hours is too big 
				m_hour = 00; //sending hour back to 0 because it was at 24
			}
		}
	}
	return *this;
}

/// <summary>
/// friend operation overload method for cout
/// </summary>
/// <param name="os">ostream&</param>
/// <param name="time">Clock</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, const Clock &time) {

	if (time.m_hour < 10) os << 0;
	os << time.m_hour << ":";
	if (time.m_minute < 10) os << 0;
	os << time.m_minute << ":";
	if (time.m_second < 10) os << 0;
	os << time.m_second;

	return os;
}

/// <summary>
/// friend operation overload method for cin
/// </summary>
/// <param name="is">istream&</param>
/// <param name="time">Clock</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, Clock &time) {
	char c;
	int x;
	try {
		is >> time.m_hour;
		

		is >> c;
		if (c != ':') { //user didn't enter colon so sending message that it's wrong format
			throw string("Wrong time format\n");
		}

		is >> time.m_minute;

		is >> c;
		if (c != ':') { //user didn't enter colon so sending message that it's wrong format
			throw string("Wrong time format\n");
		}

		is >> time.m_second;
	}
	catch (string s) { //printing exception message and setting to default time
		cout << s;
		
		time.m_hour = time.m_minute = time.m_second = 0;
	}
	return is;
}
