/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will implement a derived class Circle and its methods*/

#include "Circle.h"

/// <summary>
/// ctor for circle class
/// </summary>
/// <param name="radius">float</param>
Circle::Circle(float radius) : m_radius(radius), Shape(1) {}   //prob with pure virtual

/// <summary>
/// method for calculating area of circle
/// </summary>
/// <returns>float</returns>
float Circle::area() const {
	const float PI = 3.14;
	return (m_radius * m_radius * PI);
}

/// <summary>
/// method for checking if circle is canonical
/// </summary>
/// <returns></returns>
bool Circle::isSpecial() const {
	//getting values of center to compare
	int x = m_points[0].getX();
	int y = m_points[0].getY();

	if (!x && !y) { //checking if x and y are 0
		return true;
	}
	return false; //either x, y, or both are not 0
}

/// <summary>
/// method for printing info of a special circle
/// </summary>
void Circle::printSpecial() const {
	cout << "A canonical circle with a radius " << m_radius << endl;
}

