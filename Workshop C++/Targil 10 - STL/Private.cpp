/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will implement a derived class Private and its methods*/

#include "Private.h"

/// <summary>
/// ctor for private class
/// </summary>
/// <param name="size">int</param>
/// <param name="id">int</param>
/// <param name="first">string</param>
/// <param name="last">string</param>
/// <param name="ops">int</param>
Private::Private(int id, string first, string last, int ops) : Soldier(id, first, last, ops) {
	
	m_grades = (ops == 0) ? nullptr : new float[ops];
}

/// <summary>
/// dtor for private class
/// </summary>
Private::~Private() { 

	if (m_grades != nullptr) {
		delete[] m_grades;
		m_grades = nullptr;
	}
}

/// <summary>
/// copy ctor for Private class
/// </summary>
/// <param name="p">const private&</param>
Private::Private(const Private& p) {
	m_id = p.m_id;
	m_firstName = p.m_firstName;
	m_lastName = p.m_lastName;
	m_numOps = p.m_numOps;
	
	for (int i = 0; i < m_numOps; i++) { //deep copy
		m_grades[i] = p.m_grades[i];
	}
}

/// <summary>
/// move ctor for private class
/// </summary>
/// <param name="p">Private&&</param>
Private::Private(Private&& p) noexcept {
	m_id = p.m_id;
	m_firstName = p.m_firstName;
	m_lastName = p.m_lastName;
	m_numOps = p.m_numOps;

	m_grades = p.m_grades;
	p.m_grades = nullptr;
}

/// <summary>
/// method that checks whether the soldier is entitled to a medal
/// </summary>
/// <returns>bool</returns>
bool Private::medal() {
	float avg = average(); //getting average of scores

	if ((avg > 95) && (m_numOps >= 10)) {
		return true;
	} 
	return false;
}

/// <summary>
/// method for printing soldier data
/// </summary>
void Private::print() {
	
	cout << "private\n";
	Soldier::print(); //printing the attributes that already exist in soldier

	cout << "grades: ";
	for (int i = 0; i < m_numOps; i++) {
		cout << m_grades[i] << " ";
	}
	cout << endl;

}

/// <summary>
/// getter method for grades field
/// </summary>
/// <returns>float*</returns>
float* Private::getGrades() const {
	return m_grades;
}

/// <summary>
/// setter method for grades field
/// </summary>
void Private::setGrades() {
	for (int i = 0; i < this->m_numOps; i++) {
		cin >> m_grades[i];
	}
}

/// <summary>
/// helper method to calculate average of grades
/// </summary>
/// <returns>float</returns>
float Private::average() {
	float sum = 0;

	for (int i = 0; i < m_numOps; i++) {
		sum += m_grades[i];
	}
	return (sum / m_numOps);
}
