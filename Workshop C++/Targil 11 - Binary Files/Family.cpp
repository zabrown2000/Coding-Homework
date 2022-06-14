/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 11 Question 1
This program will implement a class Family and its methods*/

#include "Family.h"
#include <cstring>
#include <iostream>
using namespace std;

/// <summary>
/// ctor for family
/// </summary>
/// <param name="id">int</param>
/// <param name="last">char[]</param>
/// <param name="mems">int</param>
/// <param name="phone">int</param>
/// <param name="acts">bool[]</param>
Family::Family(int id, char* last, int mems, int phone, bool* acts) : m_id(id), m_members(mems), m_phone(phone) {
	if (last == nullptr) {
		m_lastName[0] = 0;
	}
	else {
		strcpy_s(m_lastName, last);
	}
	
	if (acts == nullptr) {
		m_activities[0] = m_activities[1] = m_activities[2] = m_activities[3] = m_activities[4] = m_activities[5] = false;
	}
	else {
		for (int i = 0; i < 6; i++) {
			m_activities[i] = acts[i];
		}
	}
}


//setters
void Family::setID(int id) {
	m_id = id;
}

void Family::setName(char* name) {
	strcpy_s(m_lastName, name);
}

void Family::setMems(int members) {
	m_members = members;
}

void Family::setPhone(int phone) {
	m_phone = phone;
}

void Family::setAct(int act, bool choice) {
	m_activities[act-1] = choice;
}

void Family::setActs(bool* acts) {
	for (int i = 0; i < 6; i++) {
		m_activities[i] = acts[i];
	}
}




//getters
int Family::getID() const {
	return m_id;
}

std::string Family::getName() const {
	return (std::string)m_lastName;
}


int Family::getMems() const {
	return m_members;
}

int Family::getPhone() const {
	return m_phone;
}

bool Family::getAct(int i) const {
	return m_activities[i];
}

void Family::print() {
	//last name, number of persons, telephone number and for each activity, 
	//if a child is registered for the class (Y or N).

	cout << m_lastName << " " << m_members << m_phone << " ";
	for (int i = 0; i < 6; i++) {
		cout << ((m_activities[i]) ? "Y " : "N ");
	}
}
