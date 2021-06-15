#include "Point.h"

/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will the methods for class Point */

#include "Point.h"

/// <summary>
/// copy ctor for point class
/// </summary>
/// <param name="point">const point&</param>
Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y) {}

/// <summary>
/// default ctor for point class
/// </summary>
Point::Point() : m_x(0), m_y(0) {}

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

/// <summary>
/// overload cin operator for point class
/// </summary>
/// <param name="is">istream&</param>
/// <param name="point">Point&</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, Point& point) {
	char ch;
	is >> ch >> point.m_x >> ch >> point.m_y >> ch;
	return is;
}

/// <summary>
/// overload cout operator for point class
/// </summary>
/// <param name="os">ostream&</param>
/// <param name="point">const Point&</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, const Point& point) {
	os << "(" << point.m_x << "," << point.m_y << ") ";
	return os;
}
