/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will define an inherited class StackList and its methods*/

#ifndef STACKLIST
#define STACKLIST

#include "List.h"
#include "Stack.h"

class StackList : public Stack {

protected:
	List m_data;

public:
	//constructors
	StackList(); //default ctor
	StackList(const StackList& sl); //copy ctor

	//stack operations
	void clear() override; //clear contents of stack
	bool isEmpty() const override; //checks if stack is empty
	int pop() override; //returns and removes top element of stack
	int top() override; //returns top element of stack (without removing)
	void push(int value) override; //inserts element to top of stack
};


#endif // !STACKLIST


