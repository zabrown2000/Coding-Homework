/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 8 Question 1
This program will define a class List and its methods,
with a nested class Node and its methods*/

#ifndef LIST_H 
#define LIST_H

#include <iostream>
using namespace std;

class List {

protected:
	class Node {   //inner class that will be the contents of list

	public:
		int m_key;  //made public so can access in derived class
		Node* m_next;

		//constructors
		Node(int key = 0, Node* next = NULL); //default and parameter ctor
		Node(const Node& source); //copy ctor

	};
	Node* m_head;

public:
	//constructors and destructor
	List(); //default ctor                           
	List(const List& L); //copy ctor
	~List(); //dtor
	List(List&& L) noexcept; //move ctor - not valid on moodle

	//list operations
	void clear(); //method to clear the contents of a list
	void add(int value); //method to insert element to front of list
	void removeFirst(); //deletes fist node in list
	int firstElement() const; //method to return key of first node in list
	bool isEmpty() const; //method to check if list is empty
	List::Node* search(const int& value) const; //searching for specific node key

	//operator methods
	List& operator=(const List& rhs); //assignment operator overload method
	friend ostream& operator<<(ostream& os, const List& L); //cout operator overload method, friend to List and Node
	friend istream& operator>>(istream& is, List& L); //cin operator overload method, friend to List and Node

};

#endif // !LIST_H 

