/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 3
This program will       */

#include "Circle.h"
#include <cmath>

const float PI = 3.14;

/// <summary>
/// method to set the value of the center point
/// </summary>
/// <param name="x">int</param>
/// <param name="y">int</param>
void Circle::setCenter(int x, int y) { 
	
	m_center.setX(x);  //setting each part of the point center
	m_center.setY(y);
}

/// <summary>
/// method to set the value of radius
/// </summary>
/// <param name="radius">int</param>
void Circle::setRadius(int radius) {
	m_radius = radius;
}

/// <summary>
/// method to get value of the center point 
/// </summary>
/// <returns>Point</returns>
Point Circle::getCenter() {
	//call getX and getY and set equal to new Point and return that
	//Point tempCenter; //making new point to return
	//tempCenter.setX(m_center.getX()); 
	//tempCenter.setY(m_center.getY());
	//return tempCenter;
	return m_center;  //same as above?
}

/// <summary>
/// method to get value of radius 
/// </summary>
/// <returns>int</returns>
int Circle::getRadius() {
	return m_radius;
}

/// <summary>
/// method to calculate area of a circle
/// </summary>
/// <returns>float</returns>
float Circle::area() {
	
	return PI * pow(m_radius, 2); //returning pi * r^2
}

/// <summary>
/// method to calculate circumference of a circle
/// </summary>
/// <returns>float</returns>
float Circle::circumference() {
	
	return 2 * PI * m_radius;
}

/// <summary>
/// method to locate where a point lies in respect to a circle
/// </summary>
/// <param name="point">Point</param>
/// <returns>int</returns>
int Circle::findPoint(Point point) {
	
	float length;
	length = distance(point, m_center); //calculating length between point given and center of circle

	float radius = (float)m_radius; //getting radius from circle and casting to float so can compare with length

	if (length == radius) { //since they are equal the point lies on the circle
		return 0;
	}
	if (length < radius) { //point is inside the circle
		return -1;
	}
	if (length > radius) { //point is outside the circle
		return 1;
	}
}

/// <summary>
/// method to find the distance between 2 points
/// </summary>
/// <param name="point1">Point</param>
/// <param name="point2">Point</param>
/// <returns>float</returns>
float Circle::distance(Point point1, Point point2) {
	
	float distance;
	int x1, y1, x2, y2;

	//getting values of the points passed to the function
	x1 = point1.getX();
	y1 = point1.getY();
	x2 = point2.getX();
	y2 = point2.getY();

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); //calculating distance using formula for distance between 2 points using sqrt and pow functions
	
	return distance;
}
