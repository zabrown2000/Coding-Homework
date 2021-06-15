/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will define a class QueueStack and its methods*/

#ifndef QUEUESTACK
#define QUEUESTACK

#include "StackList.h"
#include "Queue.h"

class QueueStack : public Queue {

protected:
	Stack* m_data;

public:
	QueueStack(); //default ctor 
	void clear() override; //method to clear contents of "queue"
	int dequeue() override; //method to return and remove first element inserted into "queue"
	void enqueue(int value) override; //method to insert element into "queue"
	int front() override; //method to return first element in the "queue"
	bool isEmpty() const override; //method to check if "queue" is empty
};


#endif // !QUEUESTACK



