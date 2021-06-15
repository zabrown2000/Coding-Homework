/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will implement a derived class Commander and its methods*/

#include "Commander.h"

/// <summary>
/// ctor for commander class
/// </summary>
/// <param name="id">int</param>
/// <param name="first">string</param>
/// <param name="last">string</param>
/// <param name="ops">int</param>
/// <param name="combat">bool</param>
Commander::Commander(int id, string first, string last, int ops, bool combat) : m_isCombat(combat), Private(id, first, last, ops) {}

/// <summary>
/// method that checks whether the soldier is entitled to a medal
/// </summary>
/// <returns>bool</returns>
bool Commander::medal() {
	
	float avg = Private::average();

	if ((avg > 90) && (m_numOps >= 7) && (m_isCombat)) {
		return true;
	}
	return false;
}

/// <summary>
/// method for printing soldier data
/// </summary>
void Commander::print() {

	cout << "commander\n";
	Soldier::print(); //printing everything that overlaps in the 2 classes (can't do private because printing type of soldier too)

	cout << "grades: ";
	for (int i = 0; i < m_numOps; i++) {
		cout << m_grades[i] << " ";
	}

	cout << "\ncombat: ";
	if (m_isCombat) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}
}

/// <summary>
/// getter method for combat field
/// </summary>
/// <returns></returns>
bool Commander::getCombat() const {
	return m_isCombat;
}

/// <summary>
/// setter method for combat field
/// </summary>
/// <param name="combat">bool</param>
void Commander::setCombat(bool combat) {
	this->m_isCombat = combat;
}
