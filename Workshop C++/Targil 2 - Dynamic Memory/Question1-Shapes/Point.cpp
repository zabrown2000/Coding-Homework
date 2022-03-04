/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 1
This program will define the methods for class Point */

#include "Point.h"
#include<cmath>

/// <summary>
/// method to set the value of x
/// </summary>
/// <param name="x">int</param>
void Point::setX(int x) {
	m_x = x;
}

/// <summary>
/// method to set the value of y
/// </summary>
/// <param name="y">int</param>
void Point::setY(int y) {
	m_y = y;
}

/// <summary>
/// method to get value of x
/// </summary>
/// <returns>int</returns>
int Point::getX() {
	return m_x;
}

/// <summary>
/// method to get value of y
/// </summary>
/// <returns>int</returns>
int Point::getY() {
	return m_y;
}

/// <summary>
/// method to calculate distance between 2 points (1 called and 1 passed)
/// </summary>
/// <param name="point">Point</param>
/// <returns>float</returns>
float Point::distance(Point point) {
	
	float distance;
	int x1, y1, x2, y2;

	x1 = m_x;
	y1 = m_y;
	x2 = point.m_x;
	y2 = point.m_y;

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); //calculating distance using formula for distance between 2 points using sqrt and pow functions

	return distance;

}
