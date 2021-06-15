/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 1
This program will define the class Polygon and its methods*/

//#pragma once
#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"

class Polygon {
	//private by default
	Point* m_vertices;
	int m_size;

public:

	Point* getVertices(); //getter method for m_vertices
	
	Polygon(int size); //constructor
	Polygon(const Polygon& shape); //copy constructor
	~Polygon(); //destructor

	void addItem(int index, Point vertex); //method to add a point to a specific index in the array of points
	float perimeter(); //method to calculate the perimeter of a given polygon shape
	bool equal(Polygon polygon1, Polygon polygon2); //method to discover if 2 polygons are equivalent

private: 
	//method can only be accessed by above methods, not in main
	bool findPoint(Point vertex, Polygon shape); //method to check if 1 point is a vertex of a given polygon
};

#endif // !POLYGON_H