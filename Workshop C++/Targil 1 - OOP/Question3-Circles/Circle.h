/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 3
This program will define class Circle and its methods*/

//#pragma once
#ifndef CIRCLE_H 
#define CIRCLE_H

#include "Point.h"

class Circle {

	//private by default
	Point m_center;
	int m_radius;

public:
	//setter methods
	void setCenter(int x, int y);
	void setRadius(int radius);

	//getter methods
	Point getCenter();
	int getRadius();

	float area(); //method to calculate area of a circle
	float circumference(); //method to calculate circumference of a circle

	int findPoint(Point point); //method to locate where a point lies in respect to a circle

private:
	//method only available to above methods, not in main
	float distance(Point point1, Point point2); //method to find the distance between 2 points
};

#endif // !CIRCLE_H 



