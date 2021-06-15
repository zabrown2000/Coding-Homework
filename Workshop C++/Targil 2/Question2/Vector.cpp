/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 2
This program will define the methods for the class Vector*/

#include "Vector.h"
#include<iostream>
using namespace std;

/// <summary>
/// default constructor for Vector, makes capacity 2 if no value given
/// </summary>
/// <param name="capacity">int</param>
Vector::Vector(int capacity) {

	m_capacity = capacity;
	m_data = new int[m_capacity];
	m_size = 0;
}

/// <summary>
/// copy constructor - deep copy
/// </summary>
/// <param name="vec">Vector& const</param>
Vector::Vector(const Vector& vec) {
	this->m_capacity = vec.m_capacity;
	this->m_size = vec.m_size;
	this->m_data = new int[m_capacity]; //making new array of same capacity as given object

	for (int i = 0; i < m_capacity; i++) { //copying over the actual elements in array from given object to new array
		m_data[i] = vec.m_data[i];
		if (i == (m_size - 1)) {
			break; //done copying actual elements in the array (in cases where array not filled to max)
		}
	}
}

/// <summary>
/// destuctor for Vector
/// </summary>
Vector::~Vector() {
	//if capacity>0, delete m_vertices and set it =NULL
	if (m_capacity) { //as long as capacity isn't 0, because would be deleting something that doesn't exist
		delete[] m_data;
		m_data = NULL;
	}
}

/// <summary>
/// getter method for m_capacity
/// </summary>
/// <returns>int</returns>
int Vector::getCapacity() {
	return m_capacity;
}

/// <summary>
/// getter method for m_size
/// </summary>
/// <returns>int</returns>
int Vector::getSize() {
	return m_size;
}

/// <summary>
/// method to print contents of objects
/// </summary>
void Vector::print() {
	
	cout << "capacity: " << m_capacity << " size: " << m_size << " values: ";

	for (int i = 0; i < m_size; i++) {
		cout << m_data[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// method to assign contents of 1 object to another
/// </summary>
/// <param name="vec">const Vector&</param>
void Vector::assign(const Vector& vec) {
	if (this->m_data) {
		delete[] this->m_data; //need to delete what current object points to before assigning to point to something else
	}
	this->m_capacity = vec.m_capacity;
	this->m_size = vec.m_size;
	//this->m_data = vec.m_data; //shallow copy, having calling object point to same thing as given object

	m_data = new int[vec.m_capacity];
	for (int i = 0; i < vec.m_capacity; i++) { //copying over the actual elements in array from given object to new array
		m_data[i] = vec.m_data[i];
		if (i == (vec.m_size - 1)) {
			break; //done copying actual elements in the array (in cases where array not filled to max)
		}
	}
}

/// <summary>
/// method to check if 2 vectors are equal to each other
/// </summary>
/// <param name="vec1">Vector</param>
/// <returns>bool</returns>
bool Vector::isEqual(Vector vec1) {
	
	if (this->m_size != vec1.m_size) { //if the number of elements inside the vectors aren't the same then for sure they are not equal
		return false; 
	}
	for (int i = 0; i < this->m_size; i++) {
		
		if (this->m_data[i] != vec1.m_data[i]) { //checking if any case where elements are not the same
			return false; //can return false no need to keep going
		}
	}
	return true; //made it through all the checks so the 2 vectors are equal
}

/// <summary>
/// method to retrieve address of value from vector at given index
/// </summary>
/// <param name="index">int</param>
/// <returns>int&</returns>
int& Vector::at(int index) {
	
	if (index >= m_capacity || index < 0) { //checking if index given is out range of array
		cout << "ERROR\n";
		return m_data[0];
	}
	return m_data[index]; //returning value at index passed to method
}

/// <summary>
/// method to calculate dot product of 2 vectors
/// </summary>
/// <param name="vec">Vector</param>
/// <returns>int</returns>
int Vector::strcatcat(Vector vec) {
	
	if (this->m_size != vec.m_size) { //needs to be same amount of elements in both vectors, if not leave function
		cout << "ERROR\n";
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < m_size; i++) { //looping through both vectors and adding the products of each corresponding elements from both 
		sum += this->m_data[i] * vec.m_data[i];
	}
	return sum;
}

/// <summary>
/// method to concatenate 1 vector to the end of the other
/// </summary>
/// <param name="vec">Vector</param>
/// <returns>Vector</returns>
Vector Vector::strnewcat(Vector vec) {
	
	Vector newVec(this->m_capacity + vec.m_capacity); //creating new object with a vector of max size the sum of the 2 given vectors
	newVec.m_size = this->m_size + vec.m_size;
	int i = 0; //so can use index for both loops
	//copying elements from this->vector into new vector
	for (; i < this->m_size; i++) {
		newVec.m_data[i] = this->m_data[i];
	}
	//copying elements from passed vector to new vector, starting from index of where left off in previous loop
	for (; i < newVec.m_size; i++) {
		newVec.m_data[i] = vec.m_data[i - vec.m_size]; //getting data from i-size because i isn't starting at 0
	}
	return newVec;
}

/// <summary>
/// method to clear the contents of the vector
/// </summary>
void Vector::clear() {
	
	if (m_capacity) { //precaution in case method called for vector with 0 capacity
		this->~Vector(); //calling destructor for this vector
		//delete[] m_data; //delete the contents of m_data
		//m_data = NULL; //so don't have a dangling vector
		m_size = 0; //change size to 0 because no actual elements in array now
	}
	
}

/// <summary>
/// method to delete last element in the vector
/// </summary>
void Vector::delLast() {
	
	if (!m_size) { //if there are no elements in vector, end methos, nothing to do
		cout << "ERROR\n";
		return;
	}
	int* tempVec = new int[m_capacity];
	if (m_size <= m_capacity) { //preventing potential overflow 
		
		for (int i = 0; i < m_size - 1; i++) { //will copy over all but the last existing element to the temp vector
			tempVec[i] = m_data[i];
		}
		delete[] m_data; //deleting current vector being pointed to
		m_data = tempVec; //now it points to the same vector sans the last element
		--m_size; //decrease size because deleted 1 of actual elements inside
	}
	
}

/// <summary>
/// method to add element to next open space in vector
/// </summary>
/// <param name="val">int</param>
void Vector::insert(int val) {
	//If the vector was full it expands the vector dynamically by making it twice the size, 
	//and copy the values etc, release the memory. Of old vector

	if (m_size == m_capacity) { //if all spaces in vector in use
		int* tempVec = new int[2 * m_capacity]; //create new vector with double the max size
		int i = 0;
		for (; i < m_capacity; i++) { //copy over all elements currently in vec to tempVec
			tempVec[i] = m_data[i];
		}
		tempVec[i] = val; //adding in value passed to function
		++m_size; //updating size and capacity
		m_capacity *= 2;

		delete[] m_data;
		m_data = tempVec; //now vector in object contains value to be inserted
		return; //can end here, no need to continue
	}
	m_data[m_size] = val; //putting value at index after lest element in vector
	++m_size; //updating size because added in element
}
