/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 1
This program will define a class rational and its methods*/

#ifndef RATIONAL_H 
#define RATIONAL_H
class Rational {
	int m_num;
	int m_den;

public:
	Rational(int num = 0, int den = 1); //constructor with default values set
	Rational(const Rational& fraction); //copy constructor
	
	//operation overload methods
	Rational operator+(Rational fraction); //addtion operation overload method
	Rational operator-(Rational fraction); //subtraction operation overload method
	Rational operator*(Rational fraction); //multiplication operation overload method
	Rational operator/(Rational fraction); //division operation overload method
	Rational operator++(); //pre-increment operation overload method
	Rational operator++(int u); //post-increment operation overload method
	Rational operator--(); //pre-decrement operation overload method
	Rational operator--(int u); //post-decrement operation overload method
	bool operator==(const Rational& fraction) const; //is equal operation overload method
	bool operator!=(const Rational& fraction) const; //is not equal operation overload method
	bool operator<(Rational fraction2); //less than operation overload method
	bool operator<=(Rational fraction2); //less than or equal operation overload method
	bool operator>(Rational fraction2); //greater than operation overload method
	bool operator>=(Rational fraction2); //greater than or equal operation overload method

	void print(); //method to print a rational
	
private: 
	//methods below can only be accesed by above, not from main
	Rational negative(Rational fraction); //method to check if rational side needs to be made positive
	Rational reduce(Rational fraction); //method to reduce a rational to simplest form
	int findGCF(int x, int y); //method to find gcf of 2 numbers
	void expand(Rational& fraction1, Rational& fraction2); //method to set 2 rationals to equal denominators
};

#endif //!RATIONAL_H

