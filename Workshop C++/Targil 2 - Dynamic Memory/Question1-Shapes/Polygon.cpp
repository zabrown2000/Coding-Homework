/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 1
This program will define the methods for class Polygon */

#include "Polygon.h"
#include<iostream>
using namespace std;

/// <summary>
/// getter method for m_vertices
/// </summary>
/// <returns>Point*</returns>
Point* Polygon::getVertices() {
	return m_vertices;
}

/// <summary>
/// constructor for class Polygon
/// </summary>
/// <param name="size">int</param>
Polygon::Polygon(int size) {
	cout << "in constructor\n";

	m_size = size;
	m_vertices = new Point[m_size]; //creating array of points based on size passed to method
}

/// <summary>
/// copy constructor, deep copy for class Polygon
/// </summary>
/// <param name="shape">Polygon const by reference</param>
Polygon::Polygon(const Polygon& shape) {
	cout << "in copy-constructor\n";
	
	this->m_size = shape.m_size; //copy size of passed object to current object
	this->m_vertices = new Point[m_size]; //creating array in current object of same size as passed object
	
	for (int i = 0; i < m_size; i++) { //copying over elements of array from passed object to array in current object
		m_vertices[i] = shape.m_vertices[i];
	}
}

/// <summary>
/// destructor for class Polygon
/// </summary>
Polygon::~Polygon() {
	cout << "in destructor\n";
	
	if (m_size) { //as long as size isn't 0, because would be deleting something that doesn't exist
		delete[] m_vertices;
		m_vertices = NULL;
	}
}

/// <summary>
/// method to add a point to a specific index in the array of points
/// </summary>
/// <param name="index">int</param>
/// <param name="vertex">Point</param>
void Polygon::addItem(int index, Point vertex) {
	// if given index exists and is empty, insert it, otherwise find next empty place if not make new array with extra spot at end for this one
	if (index < m_size) {
		m_vertices[index].setX(vertex.getX()); //setting x-value of point at spot index in the array to be the x-value from the passed Point
		m_vertices[index].setY(vertex.getY()); //setting y-value of point at spot index in the array to be the y-value from the passed Point
	}
}

/// <summary>
/// method to calculate the perimeter of a given polygon shape by finding the distance between each of the points
/// </summary>
/// <param name="shape">Polygon</param>
/// <returns>float</returns>
float Polygon::perimeter() {
	
	float perimeter = 0;
	for (int i = 0; i < (m_size - 1); i++) { //only going to m_size-1 because doing i+1
		
		perimeter += m_vertices[i].distance(m_vertices[i + 1]); //adding distance between each point and the one after it to the perimeter
	}
	perimeter += m_vertices[0].distance(m_vertices[m_size - 1]); //finally adding distance between first and last points

	return perimeter;
}

/// <summary>
/// method to discover if 2 polygons are equivalent
/// </summary>
/// <param name="polygon1">Polygon</param>
/// <param name="polygon2">Polygon</param>
/// <returns>bool</returns>
bool Polygon::equal(Polygon polygon1, Polygon polygon2) {
	bool pointExists;
	
	if (polygon1.m_size != polygon2.m_size) { //1 of criteria is that the 2 shapes need to have same amount of vertices, so if they aren;t can return false
		return false; 
	}
	for (int i = 0; i < polygon1.m_size; i++) { 

		pointExists = findPoint(polygon1.m_vertices[i], polygon2); //will now send each point from polygon1 to see if it can be found in polygon2
		
		if (!pointExists) { //if function returned false, 1 point was found so can return false
			return false;
		}
	}
	return true; //made it through loop with all points found so the shapes are equal
}

/// <summary>
/// method to check if 1 point is a vertex of a given polygon
/// </summary>
/// <param name="vertex">Point</param>
/// <param name="shape">Polygon</param>
/// <returns>bool</returns>
bool Polygon::findPoint(Point vertex, Polygon shape) {

	//getting x and y values of Point passed to function
	int x = vertex.getX();
	int y = vertex.getY();
	
	for (int i = 0; i < shape.m_size; i++) {
		
		if ((x == shape.m_vertices[i].getX()) && (y == shape.m_vertices[i].getY())) { //comparing the x and y values of vertex to each point in the polygon
			return true; //found the point, so no need to continue, return true
		}
	}
	return false; //went through all vertices in the polygon, and couldn't find the given vertex
}
