/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 5 Question 2
This program will define a class List and its methods,
with a nested class Node and its methods*/

#ifndef LIST_H 
#define LIST_H

#include <iostream>
using namespace std;

class List {

protected:
	class Node {   //inner class that will be the contents of list

		int m_key;
		Node* m_next;

	public:
		//constructors
		Node(int key = 0, Node* next = NULL); //default and parameter ctor
		Node(const Node& source); //copy ctor

		friend class List; //allowing List access to this inner class

		//need below methods here so function can access private data members
		friend ostream& operator<<(ostream& os, const List& L); //need here so function can access private data members
		friend istream& operator>>(istream& is, List& L);
	};
	Node* m_head;

public:
	//constructors and destructor
	List(); //default ctor                           
	List(const List& L); //copy ctor
	~List(); //dtor
	//List(List&& L) noexcept; //move ctor - not valid on moodle

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
	int& operator[](int index) const; //method allowing user to index through list (allows accessing node values in main)

	void insert(int value); //method to insert number at correct spot in decreasing order
	void remove(int value); //method to remove the element given to the function
	int listSize() const; //method to find size of list (allows for iterating in the main)
};

#endif // !LIST_H 

