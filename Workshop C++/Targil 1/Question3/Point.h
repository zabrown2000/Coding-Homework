/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 3
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
};

#endif // !POINT_H



