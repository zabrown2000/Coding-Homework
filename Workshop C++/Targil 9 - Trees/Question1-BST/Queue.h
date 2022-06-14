/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 1
This program will define a pure abstract template class Queue*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
template<class T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() const = 0;
};


#endif // !QUEUE_H
