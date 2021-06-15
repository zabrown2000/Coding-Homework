/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 2
This program will define a class Vector and its methods*/

//#pragma once
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
	//private by default
	int* m_data;
	int m_capacity;
	int m_size;

public:
	Vector(int capacity = 2); //default constructor
	Vector(const Vector& vec); //copy constructor
	~Vector(); //destructor

	//getter methods
	int getCapacity();
	int getSize();

	void print(); //prints contents of object
	void assign(const Vector& vec); //method to assign contents of 1 object to another
	bool isEqual(Vector vec1); //method to check if 2 vectors are equal to each other
	int& at(int index); //method to retrieve address of value from vector at given index
	int strcatcat(Vector vec); //method to calculate dot product of 2 vectors
	Vector strnewcat(Vector vec); //method to concatenate 1 vector to the end of the other
	void clear(); //method to clear the contents of the vector
	void delLast(); //method to delete last element in the vector
	void insert(int val); //method to add element to next open space in vector
};


#endif // !VECTOR_H


