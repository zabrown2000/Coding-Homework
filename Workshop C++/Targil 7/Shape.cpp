/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will implement a base class Shape and its methods*/

#include "Shape.h"

/// <summary>
/// default ctor for shape class
/// </summary>
Shape::Shape() : m_numOfPoints(0), m_points(NULL) {}

/// <summary>
/// ctor with parameters
/// </summary>
/// <param name="numPoints">int</param>
Shape::Shape(int numPoints) : m_numOfPoints(numPoints) {
	m_points = new Point[numPoints];
	cout << "Enter values of " << m_numOfPoints << " points:\n";
	for (int i = 0; i < m_numOfPoints; i++) {
		cin >> m_points[i];
		
	}
}

/// <summary>
/// copy ctor for shape class
/// </summary>
/// <param name="shape">const shape&</param>
Shape::Shape(const Shape& shape) {
	this->m_numOfPoints = shape.m_numOfPoints;
	this->m_points = new Point[shape.m_numOfPoints];

	for (int i = 0; i < m_numOfPoints; i++) { //deep copy
		this->m_points[i] = shape.m_points[i];
	}
}

/// <summary>
/// move ctor for shape class
/// </summary>
/// <param name="shape">shape&&</param>
Shape::Shape(Shape&& shape) noexcept {
	m_points = shape.m_points;
	m_numOfPoints = shape.m_numOfPoints;
	shape.m_points = NULL;
}

/// <summary>
/// dtor for shape class (virtual)
/// </summary>
Shape::~Shape() {
	if (m_points != NULL) {
		delete[] m_points;
		m_points = NULL;
	}
}

/// <summary>
/// getter method for points field
/// </summary>
/// <returns>Point*</returns>
Point* Shape::getPoints() const {
	return m_points;
}

/// <summary>
/// getter method for num of points field
/// </summary>
/// <returns></returns>
int Shape::getNum() const {
	return m_numOfPoints;
}

/// <summary>
/// overload cout method for shape class
/// </summary>
/// <param name="os">ostream&</param>
/// <param name="shape">const shape&</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, const Shape& shape) {
	for (int i = 0; i < shape.m_numOfPoints; i++) {

		os << shape.m_points[i];
	}
	return os;
}
