/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will define a derived class Triangle and its methods*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {

public:
	Triangle(); //default ctor

	float area() const override; //method to calculate area of triangle
	bool isSpecial() const override; //method for checking if triangle is equilateral
	void printSpecial() const override; //method for printing info of a special triangle

	friend ostream& operator<<(ostream& os, const Shape& shape); //overload cout method for shape class

};

#endif // !TRIANGLE_H


/*•	default constructor which constructs the vertices of the triangle (using its base class’s constructor)
•	special attribute: equilateral triangle (when the 3 sides are equal). The print of such a triangle is 
	An equilateral triangle with a side length # where # is the length of the sides.
*/
