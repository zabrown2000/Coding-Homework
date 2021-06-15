/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will define the class Point and its methods*/

#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>
using namespace std;

class Point {

	int m_x;
	int m_y;

public:
	//constructors
	Point();
	Point(const Point& point);

	//setter methods
	void setX(int x);
	void setY(int y);

	//getter methods
	int getX();
	int getY();

	float distance(Point point); //method to calculate distance between 2 points
	friend istream& operator>>(istream& is, Point& point); //overload cin operator for point class
	friend ostream& operator<<(ostream& os, const Point& point);
};

#endif // !POINT_H

