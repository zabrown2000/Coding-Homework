/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will define a derived class Circle and its methods*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
class Circle : public Shape {

	float m_radius;

public:
	//constructor
	Circle(float radius);

	float area() const override; //method for calculating area of circle
	bool isSpecial() const override; //method for checking if circle is canonical
	void printSpecial() const override; //method for printing info of a special circle

};

#endif // !CIRCLE_H



