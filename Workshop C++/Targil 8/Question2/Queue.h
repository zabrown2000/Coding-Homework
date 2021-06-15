/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 2
This program will define a pure abstract class Queue and its methods*/

#ifndef QUEUE
#define QUEUE

class Queue {

public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() const = 0;
};



#endif // !QUEUE


