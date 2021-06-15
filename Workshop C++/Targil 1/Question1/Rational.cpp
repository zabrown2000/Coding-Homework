#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

/// <summary>
/// function to set value of numerator field
/// </summary>
/// <param name="userNumerator">int</param>
void Rational::setNumerator(int userNumerator) {
	this->numerator = userNumerator; //setting numerator field to the value sent to the function by the user
}

/// <summary>
/// function to get the value of numerator field
/// </summary>
/// <returns>int</returns>
int Rational::getNumerator() {
	
	return numerator; //returning the numerator to the function call
}

/// <summary>
/// function to set the value of the denominator
/// </summary>
/// <param name="userDenominator">int</param>
void Rational::setDenominator(int userDenominator) {

	if (userDenominator == 0) {  //if user entered a 0, default set to 0 
		this->denominator = 1;
	}
	else { //otherwise set denominator to what user entered
		this->denominator = userDenominator;
	}
}

/// <summary>
/// function to get the value of the denominator
/// </summary>
/// <returns>int</returns>
int Rational::getDenominator() {
	
	return denominator; //returning the denominator to the function call
}

/// <summary>
/// function to print the rational
/// </summary>
void Rational::print() {
	cout << numerator << "/" << denominator << " "; //printing the rational
}

/// <summary>
/// function to add to rationals (fractions) together
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::add(Rational fraction) {
	//using method -> a/b + p/q = (aq + bq) / bq
	Rational newFraction;
	newFraction.numerator = (numerator * fraction.denominator) + (denominator * fraction.numerator);
	newFraction.denominator = denominator * fraction.denominator;

	newFraction = negative(newFraction); //changing value of function to be positive if top and bottom are negative
	return reduction(newFraction); //now making sure the new fraction is in simplest form
}

/// <summary>
/// function to check if 2 rationals (fractions) are equal
/// </summary>
/// <param name="fraction1">Rational</param>
/// <returns>bool</returns>
bool Rational::equal(Rational fraction1) {

	Rational fraction2;     //making new rational for the object calling the function so can reduce it
	fraction2.numerator = numerator;
	fraction2.denominator = denominator;

	fraction1 = negative(fraction1);  //checking if the 2 fractions have to be made postive (top and bottom are negative)
	fraction2 = negative(fraction2);

	fraction1 = reduction(fraction1);  //reducing the 2 fractions so they can be compared
	fraction2 = reduction(fraction2);

	if ((fraction1.numerator == fraction2.numerator) && (fraction1.denominator == fraction2.denominator)) {
		return true;   //a/b and p/q in simplest form, if a=p and b=q then they are equal
	}
	return false; //fractions aren't equal
}

/// <summary>
/// function to reduce a rational (fraction) to simplest form
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::reduction(Rational fraction) {

	int posNum, largest, gcd = 0; 

	if (fraction.numerator < 0) { //getting the positive value of the numerator (if it's negative)
		posNum = fraction.numerator * -1;
	}
	else {
		posNum = fraction.numerator;
	}

	largest = posNum > fraction.denominator ? posNum : fraction.denominator; //setting largest to the greater of the 2 (num and den) ->why needed to get positive value of numerator

	for (int i = largest; i >= 2; i--) { //will now go through all possible divisors for numerator and denominator starting from greatest possible number
		if (fraction.numerator % i == 0 && fraction.denominator % i == 0) { //if both numerator and denominator are divisible by the same number
			gcd = i;
			break; //found gcd (greatest common denominator) no need to keep checking, then won't be in simplest form
		}
	}
	if (gcd) { //if gcd isn't default of 0 (if it was it means rational already in simplest form)

		fraction.numerator /= gcd;     //changing values of rational to their simplest forms by dividing them by the gcd
		fraction.denominator /= gcd;
	}
	return fraction;
}

/// <summary>
/// checks if value of a fraction should be made positive (top and bottom negative)
/// </summary>
/// <param name="fraction">Rational</param>
/// <returns>Rational</returns>
Rational Rational::negative(Rational fraction) {
	
	if ((fraction.numerator < 0) && (fraction.denominator < 0)) { //if top and bottom are negative then result is positive
		fraction.numerator = abs(fraction.numerator);
		fraction.denominator = abs(fraction.denominator);
	}
	return fraction; //will return either the given fraction or the newly positive function if top and bottom are negative
}
