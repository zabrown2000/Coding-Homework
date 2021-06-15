/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 1
This program will define the class Point and its methods*/

//#pragma once
#ifndef POINT_H
#define POINT_H

class Point {

	//private by default
	int m_x;
	int m_y;

public:
	//setter methods
	void setX(int x);
	void setY(int y);

	//getter methods
	int getX();
	int getY();

	float distance(Point point); //method to calculate distance between 2 points (1 called and 1 passed)
};

#endif // !POINT_H
