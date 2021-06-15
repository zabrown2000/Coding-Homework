/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will implement a derived class Rectangle and its methods*/

#include "Rectangle.h"

/// <summary>
/// default ctor for rectangle class
/// </summary>
Rectangle::Rectangle() : Shape(4) {}

/// <summary>
/// method to calculate area of rectangle
/// </summary>
/// <returns>float</returns>
float Rectangle::area() const {
	//getting length of 2 adjacent sides
	float side1 = m_points[0].distance(m_points[1]);
	float side2 = m_points[1].distance(m_points[2]);

	return (side1 * side2);
}

/// <summary>
/// method for checking if rectangle is a square
/// </summary>
/// <returns>bool</returns>
bool Rectangle::isSpecial() const {
	//getting length of 2 adjacent sides (by definition rectangles have opposite equal sides so side3=side1 and side4=side2)
	float side1 = m_points[0].distance(m_points[1]);
	float side2 = m_points[1].distance(m_points[2]);

	if (side1 == side2) {
		return true;
	}
	return false; //adjacent sides aren't equal
}

/// <summary>
/// method for printing info of a special rectangle
/// </summary>
void Rectangle::printSpecial() const {
	float side = m_points[0].distance(m_points[1]); //getting length of 1 of sides
	cout << "Square with side length " << side << endl;
}
