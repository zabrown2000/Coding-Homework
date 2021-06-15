/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will define a pure abstract class Stack and its methods*/

#ifndef STACK
#define STACK

class Stack {

public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual int pop() = 0;
	virtual void push(int value) = 0;
	virtual int top() = 0;
};

#endif // !STACK



