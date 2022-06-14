/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 2
This program will define an inherited class RoundList and its methods*/

#include "List.h"

#ifndef ROUNDLIST_H
#define ROUNDLIST_H

class RoundList : public List {

public:
	
	//constructors
	RoundList(); //default ctor
	//RoundList(const RoundList& rl); //copy ctor
	~RoundList(); //dtor

	//overload list methods
	void clear(); //method to clear contents of a round list
	void add(int value); //method to insert element to front of list
	void removeFirst(); //method to delete first node in a list
	RoundList& operator=(const RoundList& rhs); //overload method for = operator

	//new operations
	void addToEnd(int value); //method to add node to end of list
	int search(int n) const; //method to search for the nth element in a round list
};


#endif // !ROUNDLIST_H

