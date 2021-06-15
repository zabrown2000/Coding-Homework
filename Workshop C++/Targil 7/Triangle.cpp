/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will implement a derived class Triangle and its methods*/

#include "Triangle.h"

/// <summary>
/// default ctor for triangle class
/// </summary>
Triangle::Triangle() : Shape(3) {}

/// <summary>
/// method to calculate area of triangle
/// </summary>
/// <returns>float</returns>
float Triangle::area() const {
	//getting sides for calculations below
	float sideA = m_points[0].distance(m_points[1]);
	float sideB = m_points[1].distance(m_points[2]);
	float sideC = m_points[2].distance(m_points[0]);

	//getting the value for cos of an angle
	float num = pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2); //getting a^2 + b^2 - c^2
	float den = (2 * sideA * sideB); //getting 2ac
	float cosAB = num / den;

	float angle = acos(cosAB); //getting angle itself

	float area = (sideA * sideB * sin(angle)) / 2; //calculating area (a*b*sin(x))/2
	return area;	
}

/// <summary>
/// method for checking if triangle is equilateral
/// </summary>
/// <returns>bool</returns>
bool Triangle::isSpecial() const {
	
	//getting length of each side
	float side1 = m_points[0].distance(m_points[1]);
	float side2 = m_points[1].distance(m_points[2]);
	float side3 = m_points[2].distance(m_points[0]);

	if (side1 == side2 == side3) {
		return true;
	}
	return false; //at least 1 of sides not equal to others
}

/// <summary>
/// method for printing info of a special triangle
/// </summary>
void Triangle::printSpecial() const {
	float side = m_points[0].distance(m_points[1]); //getting length of 1 of sides
	cout << "An equilateral triangle with a side length " << side << endl;
}

