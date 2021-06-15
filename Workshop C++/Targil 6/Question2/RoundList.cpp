/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 2
This program will implement an inherited class RoundList and its methods*/

#include "RoundList.h"

/// <summary>
/// default ctor for RoundList
/// </summary>
RoundList::RoundList() {                                         
	List();
}

///// <summary>
///// copy ctor for RoundList
///// </summary>
///// <param name="rl"></param>
//RoundList::RoundList(const RoundList& rl) {
//	List::List(rl); //calling list copy ctor 
//
//	Node* p = rl.m_head;
//	while (p->m_next != NULL) { //going to end of list
//		p = p->m_next;
//	}
//	p->m_next = m_head; //making it a circular list
//}

/// <summary>
/// dtor for RoundList
/// </summary>
RoundList::~RoundList() {
	clear();
}

/// <summary>
/// method to clear contents of a round list
/// </summary>
void RoundList::clear() {
	
	Node* p = m_head, *nextNode;
	for (Node* q = m_head; q != p; q = nextNode) { //because it's a circular list, keep going until reach head again, not null
		nextNode = q->m_next;
		q->m_next = NULL;
		delete q;
	}
	m_head = NULL; //now it's an empty list
}

/// <summary>
/// overload method for = operator
/// </summary>
/// <param name="rhs">const RoundList&</param>
/// <returns>RoundList&</returns>
RoundList& RoundList::operator=(const RoundList& rhs) {
	
	List::operator=(rhs); //calling list =method to do the heavy work
	Node* p = rhs.m_head;
	while (p->m_next != NULL) { //going to end of list
		p = p->m_next;
	}
	p->m_next = m_head; //making it a circular list

	return *this;
}

/// <summary>
/// method to insert element to front of list
/// </summary>
/// <param name="value">int</param>
void RoundList::add(int value) {

	Node* p = m_head;
	if ((p != NULL) && (p->m_next != NULL)) { //checking for end of list, if empty, p stays at head
		while (p->m_next != m_head) {
			p = p->m_next;
		}
	}
	m_head = new Node(value, m_head); //creating new node with value given and next of head, set it all to head

	if (p != NULL) { //meaning we added in a node to a non-empty list
		p->m_next = m_head; //making it circular
	}
	if (!m_head) { //checking if returned address is nullptr
		throw "failed to allocate memory for new Node";
	}
}

/// <summary>
/// method to delete first node in a list
/// </summary>
void RoundList::removeFirst() {
	if (!isEmpty()) { //won't do anything if list is empty

		if (m_head == m_head->m_next) { //case where the round list has only 1 node, which essentially points to itself
			delete m_head;
			m_head = NULL;
			return;
		}
		else {
			Node* p = m_head, * temp;

			while (p->m_next != m_head) { //getting to end of list, since with round list when dealing with head more complicated
				p = p->m_next;
			}
			temp = m_head->m_next; //can't use code snippet from reguar List method because it's a drop different here
			delete m_head;
			m_head = temp;
			p->m_next = m_head; //since temporarily deleting what head points to, need end of list to point to new head of list
		}
	}
}

/// <summary>
/// method to add node to end of list
/// </summary>
/// <param name="value">int</param>
void RoundList::addToEnd(int value) {
	if (isEmpty()) {
		add(value); //if list is empty, adding to the end is just like adding to the front
		return;
	}
	Node* p = m_head;
	if (p->m_next == NULL) { //needed to add in this bloc, got exception thrown without it
		p->m_next = new Node(value, m_head);
		return;
	}
	while (p->m_next != m_head) { //getting to end of list
		p = p->m_next;
	}
	p->m_next = new Node(value, m_head); //inserting element to the end of the list
}

/// <summary>
/// method to search for the nth element in a round list
/// </summary>
/// <param name="n">int</param>
/// <returns>int</returns>
int RoundList::search(int n) const {
	if (m_head == NULL) { //list is empty, nothing to search for
		return -1;
	}

	Node* p = m_head;
	for (int i = 0; i < n; i++) { //moving around list until get to nth place
		p = p->m_next;
	}
	return p->m_key;
}
