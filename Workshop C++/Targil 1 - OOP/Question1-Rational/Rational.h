#pragma once
class Rational {

	//private fields by default
	int numerator;
	int denominator;

public:

	void setNumerator(int userNumerator); //function to set value of numerator field
	int getNumerator(); //function to get the value of numerator field

	void setDenominator(int userDenominator); //function to set the value of the denominator
	int getDenominator(); //function to get the value of the denominator

	void print(); //function to print the rational
	Rational add(Rational fraction); //function to add to rationals (fractions) together
	bool equal(Rational fraction1); //function to check if 2 rationals (fractions) are equal

private:
	//functions can only be used in the above methods, not available in the main
	Rational reduction(Rational fraction); //function to reduce a rational (fraction) to simplest form
	Rational negative(Rational fraction); //checks if value of a fraction should be made positive (top and bottom negative)
};

