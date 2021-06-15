/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will implement a class QueueStack and its methods
utilizing the StackList class*/

#include "QueueStack.h"

/// <summary>
/// default ctor fot queuestack class
/// </summary>
QueueStack::QueueStack() {
	m_data = new StackList();
}

/// <summary>
/// method to clear contents of "queue"
/// </summary>
void QueueStack::clear() {
	m_data->clear(); //calling clear for stacklist
}

/// <summary>
/// method to return and remove first element inserted into "queue"
/// </summary>
/// <returns>int</returns>
int QueueStack::dequeue() {
	return m_data->pop(); //calling pop on stacklist and returning value
}

/// <summary>
/// method to insert element into "queue"
/// </summary>
/// <param name="value"></param>
void QueueStack::enqueue(int value) {
	Stack* helperStack = new StackList(); //creating helper stack to allow us to enter a new element to bottom of stack to act like a queue
	
	//going through original stack and removing each element and then inserting it into 
	//the helper stack, essentially spilling 1 into the other
	while (!m_data->isEmpty()) {
		int temp = m_data->pop();
		helperStack->push(temp);
	}
	m_data->push(value); //now stack is empty so insert new element and now it will be last to go out (FIFO)

	//putting original elements of stack back into original stack from helper stack
	//on top of the newly inserted element
	while (!helperStack->isEmpty()) {
		int temp = helperStack->pop();
		m_data->push(temp);
	}
	//Note to grader: I attemped to make a helper method for the 2 while loops but it got complicated 
	//because the code snippet given to us had data as Stack* and I would have needed it to be StackList
}


/// <summary>
/// method to return first element in the "queue"
/// </summary>
/// <returns></returns>
int QueueStack::front() {
	return m_data->top(); //getting top value of stacklist
}

/// <summary>
/// method to check if "queue" is empty
/// </summary>
/// <returns>bool</returns>
bool QueueStack::isEmpty() const {
	return m_data->isEmpty(); //calling isempty for stacklist
}

