/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will define a derived class Rectangle and its methods*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {

public:
	Rectangle(); //default ctor

	float area() const override; //method to calculate area of rectangle
	bool isSpecial() const override; //method for checking if rectangle is a square
	void printSpecial() const override; //method for printing info of a special rectangle

	friend ostream& operator<<(ostream& os, const Shape& shape); //overload cout method for shape class
};

#endif // !RECTANGLE_H


/*•	default constructor which constructs the vertices of the rectangle (using its base class’s constructor)
•	special attribute: square (when the 4 sides are equal). The print of such a rectangle is 
	Square with a side length # where # is the length of the sides.
*/

