/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will implement an inherited class StackList and its methods,
utilizing the List class and its methods*/

#include "StackList.h"

/// <summary>
/// default contstructor
/// </summary>
StackList::StackList() : m_data() {}

/// <summary>
/// copy ctor for StackList
/// </summary>
/// <param name="sl"></param>
StackList::StackList(const StackList& sl) : m_data(sl.m_data) {}

/// <summary>
/// method to clear contents of stack
/// </summary>
void StackList::clear() {
	m_data.clear(); // clear all elements from Stack, by setting delete all values from List
}

/// <summary>
/// method that checks if stack is empty
/// </summary>
/// <returns>bool</returns>
bool StackList::isEmpty() const {
	return m_data.isEmpty(); // returns true if Stack is empty

}

/// <summary>
/// method that returns and removes top element of stack
/// </summary>
/// <returns>int</returns>
int StackList::pop() {
	int result = m_data.firstElement(); //getting top element of stack
	m_data.removeFirst(); //removes first element from List

	return result;
}

/// <summary>
/// method that returns top element of stack (without removing)
/// </summary>
/// <returns>int</returns>
int StackList::top() {
	return m_data.firstElement();
}

/// <summary>
/// inserts element to top of stack
/// </summary>
void StackList::push(int value) {

	m_data.add(value); //adds element to stack
}