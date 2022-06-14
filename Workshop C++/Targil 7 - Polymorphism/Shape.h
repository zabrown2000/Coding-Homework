/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will define a base class Shape and its methods*/

#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"


class Shape {
protected:
	int m_numOfPoints;
	Point* m_points;

public:
	//constructors
	Shape(); //default ctor
	Shape(int numPoints); //ctor with param
	Shape(const Shape& shape); //copy ctor
	Shape(Shape&& shape) noexcept; //move ctor

	virtual ~Shape(); //virtual dtor

	//getter methods
	Point* getPoints() const; 
	int getNum() const;
	
	//pure virtual methods
	virtual float area() const = 0; //calculates the area of the shape
	virtual bool isSpecial() const = 0; //method that returns true if the shape has a special attribute
	virtual void printSpecial() const = 0; //method that prints the special attribute

	friend ostream& operator<<(ostream& os, const Shape& shape); //overload cout method for shape class
};

#endif // !SHAPE_H




