/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will implement a base class Soldier and its methods*/

#include "Soldier.h"

/// <summary>
/// ctor for soldier class
/// </summary>
/// <param name="id">int</param>
/// <param name="first">string</param>
/// <param name="last">string</param>
/// <param name="ops">int</param>
Soldier::Soldier(int id, string first, string last, int ops) : m_id(id), m_firstName(first), m_lastName(last), m_numOps(ops) {}

/// <summary>
/// dtor for soldier class
/// </summary>
Soldier::~Soldier() {}

/// <summary>
/// method for printing soldier data
/// </summary>
void Soldier::print() { 
	cout << "ID: " << m_id << "\nfirst name: " << m_firstName << "\nlast name: " << m_lastName << "\nnum operations: " << m_numOps << endl;
}

/// <summary>
/// getter method for id field
/// </summary>
/// <returns>int</returns>
int Soldier::getID() const {
	return m_id;
}

/// <summary>
/// getter method for first name field
/// </summary>
/// <returns>string</returns>
string Soldier::getFirst() const {
	return m_firstName;
}

/// <summary>
/// getter method for last naem field
/// </summary>
/// <returns>string</returns>
string Soldier::getLast() const {
	return m_lastName;
}

/// <summary>
/// getter method for num of operations field
/// </summary>
/// <returns>int</returns>
int Soldier::getOps() const {
	return m_numOps;
}

/// <summary>
/// method to get grades for private or commander, throws for all other soldier types
/// </summary>
/// <returns>float*</returns>
float* Soldier::getGrades() const {
	throw "ERROR: this function is just for private and commander soldiers";
}

/// <summary>
/// method to get isCombat for commander, throws for all other soldier types
/// </summary>
/// <returns>bool</returns>
bool Soldier::getCombat() const {
	throw "ERROR: this function is just for commander soldier";
}

/// <summary>
/// method to get score for an officer, throws for all other soldier types
/// </summary>
/// <returns>int</returns>
int Soldier::getSociometric() const {
	throw "ERROR: this function is just for officer soldier";
}

/// <summary>
/// method to set grades for private or commander, throws for all other soldier types
/// </summary>
void Soldier::setGrades() {
	throw "ERROR: this function is just for private and commander soldiers";
}

void Soldier::setCombat(bool combat) {
	throw "ERROR: this function is just for commander soldier";
}
