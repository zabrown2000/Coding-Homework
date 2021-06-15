/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 3
This program will the methods for class Point */

#include "Point.h"

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
