/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 1
This program will perform operations on rational numbers
using a class and methods*/

//#include"Rational.h"
#include <iostream>
#include "Rational.h"  //needed to move the decleration here because visual studio wasn't accepting the file otherwise
using namespace std;

int main()
{
	int numerator, denominator;
	char tav;
	cout << "enter two rational numbers:" << endl;
	cin >> numerator >> tav >> denominator;
	Rational r1;
	r1.setNumerator(numerator);
	r1.setDenominator(denominator);
	cin >> numerator >> tav >> denominator;
	Rational r2;
	r2.setNumerator(numerator);
	r2.setDenominator(denominator);
	Rational ans = r1.add(r2);
	r1.print();
	cout << "+ ";
	r2.print();
	cout << "= ";
	ans.print();
	cout << endl;
	if (r1.equal(r2))
		cout << "The two numbers are equal" << endl;
	else
	{
		cout << "The two numbers are different" << endl;
		r1.print();
		r2.print();
		cout << endl;
	}
	return 0;
}
/*enter two rational numbers:
1/2 3/6
1/2 + 3/6 = 1/1
The two numbers are equal

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.1\Debug\Homework1.1.exe (process 17132) exited with code 0.
Press any key to close this window . . .
*/