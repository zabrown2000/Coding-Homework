/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 1
This program will implement methods for the rational class*/

#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// constructor with default values set for the data members and check for invalid input
/// </summary>
/// <param name="num">int</param>
/// <param name="den">int</param>
Rational::Rational(int num, int den) {
	m_num = num;
	m_den = den;
	
	if (!den) { //if user entered 0 for denominator
		cout << "ERROR\n"; 
		m_den = 1;
	}
}

/// <summary>
/// copy constructor
/// </summary>
/// <param name="fraction">const cbr Rational</param>
Rational::Rational(const Rational& fraction) {
	m_num = fraction.m_num;
	m_den = fraction.m_den;
}

/// <summary>
/// addtion operation overload method
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::operator+(Rational fraction) {

	Rational temp; //making new rational to store sum
	temp.m_num = ((m_num * fraction.m_den) + (fraction.m_num * m_den)); //calculating numerator
	temp.m_den = m_den * fraction.m_den; //calculating denominator
	temp = negative(temp); //taking care of numerator and denominator being negative->make positive
	return reduce(temp); //returning reduced value of fraction
}

/// <summary>
/// subtraction operation overload method
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::operator-(Rational fraction) {
	 
	Rational temp; //making new rational to store difference
	temp.m_num = ((m_num * fraction.m_den) - (fraction.m_num * m_den)); //calculating numerator
	temp.m_den = m_den * fraction.m_den; //calculating denominator

	temp = negative(temp); //taking care of numerator and denominator being negative->make positive
	return reduce(temp); //returning reduced value of fraction;
}

/// <summary>
/// multiplication operation overload method
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::operator*(Rational fraction) {
	
	Rational temp; //making new rational to store product
	temp.m_num = m_num * fraction.m_num; //calculating numerator
	temp.m_den = m_den * fraction.m_den; //calculating denominator

	temp = negative(temp); //taking care of numerator and denominator being negative->make positive
	return reduce(temp); //returning reduced value of fraction;
}

/// <summary>
/// division operation overload method
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Ratioanl</returns>
Rational Rational::operator/(Rational fraction) {
	
	Rational temp; //making new rational to store quotient
	temp.m_num = m_num * fraction.m_den; //calculating numerator
	temp.m_den = m_den * fraction.m_num; //calculating denominator

	temp = negative(temp); //taking care of numerator and denominator being negative->make positive
	return reduce(temp); //returning reduced value of fraction;
}

/// <summary>
/// pre-increment operation overload method
/// </summary>
/// <returns>Rational</returns>
Rational Rational::operator++() {
	
	m_num += m_den; //only changing numerator
	return *this; //returning same rational after incremented
}

/// <summary>
/// post-increment operation overload method
/// </summary>
/// <param name="u">int</param>
/// <returns>Rational</returns>
Rational Rational::operator++(int u) {

	Rational temp = *this; //since post, want to return the rational before it was incremented
	m_num += m_den; //only changing numerator
	return temp; //still incremented, but not what's being returned
}

/// <summary>
/// pre-decrement operation overload method
/// </summary>
/// <returns>Rational</returns>
Rational Rational::operator--() {
	
	m_num -= m_den; //only changing numerator
	return *this; //returning same rational after decremented
}

/// <summary>
/// post-decrement operation overload method
/// </summary>
/// <param name="u">int</param>
/// <returns>Rational</returns>
Rational Rational::operator--(int u) {
	
	Rational temp = *this; //since post, want to return the rational before it was decremented
	m_num -= m_den; //only changing numerator
	return temp; //still decremented, but not what's being returned
}

/// <summary>
/// is equal operation overload method
/// </summary>
/// <param name="fraction">const cbr Rational</param>
/// <returns>bool</returns>
bool Rational::operator==(const Rational& fraction) const{ //if wants 1/2==2/4 need to make temp and reduce it before compare
	
	return((m_num == fraction.m_num) && (m_den == fraction.m_den)); //returns true if the numerators are same and if denominators are same
}

/// <summary>
/// is not equal operation overload method
/// </summary>
/// <param name="fraction">const cbr Rational</param>
/// <returns>bool</returns>
bool Rational::operator!=(const Rational& fraction) const{
	
	return ((m_num != fraction.m_num) || (m_den != fraction.m_num)); //returns true if either of numerators or denominators are not the same
}

/// <summary>
/// less than operation overload method
/// </summary>
/// <param name="fraction2">Rational</param>
/// <returns>bool</returns>
bool Rational::operator<(Rational fraction2) {
	
	Rational fraction1 = *this; //will be changing both fraction so don't want to change actual fraction in the main
	
	expand(fraction1, fraction2); //sending 2 fractions to be expanded so they can be compared
	if (fraction1.m_num < fraction2.m_num) { //now that denominators are the same can just compare numerators
		return true;
	}
	return false;
}

/// <summary>
/// less than or equal operation overload method
/// </summary>
/// <param name="fraction2">Ratioanl</param>
/// <returns>bool</returns>
bool Rational::operator<=(Rational fraction2) {
	
	Rational fraction1 = *this; //will be changing both fraction so don't want to change actual fraction in the main

	expand(fraction1, fraction2); //sending 2 fractions to be expanded so they can be compared
	if (fraction1.m_num <= fraction2.m_num) { //now that denominators are the same can just compare numerators
		return true;
	}
	return false;
}

/// <summary>
/// greater than operation overload method
/// </summary>
/// <param name="fraction2">Rational</param>
/// <returns>bool</returns>
bool Rational::operator>(Rational fraction2) {
	
	Rational fraction1 = *this; //will be changing both fraction so don't want to change actual fraction in the main

	expand(fraction1, fraction2); //sending 2 fractions to be expanded so they can be compared
	if (fraction1.m_num > fraction2.m_num) { //now that denominators are the same can just compare numerators
		return true;
	}
	return false;
}

/// <summary>
/// greater than or equal operation overload method
/// </summary>
/// <param name="fraction2"></param>
/// <returns></returns>
bool Rational::operator>=(Rational fraction2) {
	
	Rational fraction1 = *this; //will be changing both fraction so don't want to change actual fraction in the main

	expand(fraction1, fraction2); //sending 2 fractions to be expanded so they can be compared
	if (fraction1.m_num >= fraction2.m_num) { //now that denominators are the same can just compare numerators
		return true;
	}
	return false;
}

/// <summary>
/// method to print a rational
/// </summary>
void Rational::print() {

	if (m_num == m_den) { //if both are same then simplest form is 1
		cout << '1';
		return;
	}

	*this = reduce(*this);
	cout << m_num;
	if (m_den != 1) { cout << '/' << m_den; } //only printing denominator if not 1
}

/// <summary>
/// checks if value of a fraction should be made positive (top and bottom negative)
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::negative(Rational fraction) {

	if ((fraction.m_num < 0) && (fraction.m_den < 0)) { //if top and bottom are negative then result is positive
		fraction.m_num = abs(fraction.m_num);
		fraction.m_den = abs(fraction.m_den);
	}
	return fraction; //will return either the given fraction or the newly positive function if top and bottom are negative
}

/// <summary>
/// method to reduce a rational to simplest form
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::reduce(Rational fraction) {
	
	int gcf = findGCF(abs(fraction.m_num), abs(fraction.m_den)); //finding gcf for numerator and denominator
	fraction.m_num /= gcf; //dividing numerator and denominator by gcf
	fraction.m_den /= gcf;

	return fraction;
}

/// <summary>
/// method to find gcf of 2 numbers
/// </summary>
/// <returns>int</returns>
int Rational::findGCF(int x, int y) {
	
	int temp;

	while ((x % y) != 0) { //while x cannot be divided by y evenly
		x %= y; //x is becoming remainder of x/y
		if (x < y) {
			temp = y;
			y = x;
			x = temp;
		}
	}
	return y;
}

/// <summary>
/// method to set 2 rationals to equal denominators
/// </summary>
/// <param name="fraction1">Rational&</param>
/// <param name="fraction2">rational&</param>
void Rational::expand(Rational& fraction1, Rational& fraction2) {
	
	fraction1.m_num *= fraction2.m_den; //setting numerators to new expanded value
	fraction2.m_num *= fraction1.m_den;

	//now need to update denominators and set them to be the product of each other
	int temp = fraction1.m_den;
	fraction1.m_den *= fraction2.m_den;
	fraction2.m_den *= temp;
}
