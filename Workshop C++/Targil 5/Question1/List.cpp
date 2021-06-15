/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 5 Question 1
This program will implement a class List and its methods,
as well as a nested class Node and its methods*/

#include "List.h"

//note to self: switch to nullptr from NULL after submit to moodle

/// <summary>
/// default and parameter ctor for Node
/// </summary>
/// <param name="key">int</param>
/// <param name="next">Node*</param>
List::Node::Node(int key, Node* next) : m_key(key), m_next(next) {}

/// <summary>
/// copy ctor for Node
/// </summary>
/// <param name="source">const Node&</param>
List::Node::Node(const Node& source) : m_key(source.m_key), m_next(source.m_next) {}

/// <summary>
/// default ctor for List
/// </summary>
List::List() : m_head(NULL) {}

List::List(const List& L) {
	Node* src, * trg; //pointers used to track through both lists when copying

	if (L.m_head == NULL) {
		this->m_head = NULL; //nothing else to copy, because what copying from is empty
	}
	else {
		m_head = new Node((L.m_head)->m_key, NULL); //having the head dynamically create memory for a new Node by utilizing Node ctor
		src = L.m_head;
		trg = this->m_head;

		while (src->m_next != NULL) { //going through original list until hit null
			trg->m_next = new Node((src->m_next)->m_key, NULL); //creating new Node in target based on source list
			src = src->m_next; //incrementing both lists forward
			trg = trg->m_next;
		}
	}
}

List::~List() {
	clear(); //calling method clear which will do the work
}

///// <summary>
///// move ctor for List
///// </summary>
///// <param name="L">List&&</param>
//List::List(List&& L) noexcept {
//	
//	if (m_head != NULL) { //only want to delete if there is something there
//		delete m_head;
//	}
//	m_head = L.m_head;
//	L.m_head = NULL;
//}

/// <summary>
/// method to clear the contents of a list
/// </summary>
void List::clear() {
	
	List::Node* q = NULL; //want a pointer to actual node not just the head
	for (Node* p = m_head; p != NULL; p = q) {
		//will delete 1 node at a time, can't work backwords cause single-linked
		q = p->m_next;  //now we can delete p without losing next element
		p->m_next = NULL;
		delete p;
	}
	m_head = NULL; //now it's an empty list
}

/// <summary>
/// method to insert element to front of list
/// </summary>
/// <param name="value">int</param>
void List::add(int value) {
	m_head = new Node(value, m_head); //creating new node with value given and next of head, set it all to head
	
	if (!m_head) { //checking if returned address is nullptr
		throw "failed to allocate memory for new Node";
	}
}

/// <summary>
/// deletes fist node in list
/// </summary>
void List::removeFirst() {
	if (m_head != NULL) { //only want to remove from list that contains at least one node

		Node* temp = m_head->m_next; //so we don't lose the address of the node after the one we are deleting
		m_head->m_next = NULL; //so we when delete head don't lose entire list
		delete m_head;
		m_head = temp;
	}
}

/// <summary>
/// method to return key of first node in list
/// </summary>
/// <returns>int</returns>
int List::firstElement() const {
	
	if (isEmpty()) { //want to make sure not returning null
		throw "the List is empty, no first Element";
	}
	return m_head->m_key;
}

/// <summary>
/// method to check if list is empty
/// </summary>
/// <returns>bool</returns>
bool List::isEmpty() const {
	return (m_head == NULL); //will return true if head is null->an empty list
}

/// <summary>
/// searching for specific node key
/// </summary>
/// <param name="value">const int&</param>
/// <returns>Node*</returns>
List::Node* List::search(const int& value) const {	
	Node* p = m_head; //helper pointer to iterate through list

	while ((p != NULL) && (p->m_key != value)) { //as long as haven't reached end of list and haven't found the value
		p = p->m_next;
	}
	return p; //returns null if left loop because reached the end, an address to a node if found
}

/// <summary>
/// assignment operator overload method
/// </summary>
/// <param name="rhs">const List&</param>
/// <returns>List&</returns>
List& List::operator=(const List& rhs) {

	if (this == &rhs) { //checking for self-assignment
		return *this; //return itself
	}
	if (!isEmpty()) { //before copy over need to check if list has any nodes, need to get rid
		clear();
	}
	//next will do deep copy, utilizing code from copy ctor
	Node* src, * trg; //pointers used to track through both lists when copying

	if (rhs.m_head == NULL) {
		this->m_head = NULL; //nothing else to copy, because what copying from is empty
	}
	else {
		m_head = new Node((rhs.m_head)->m_key, NULL); //having the head dynamically create memory for a new Node by utilizing Node ctor
		src = rhs.m_head;
		trg = this->m_head;

		while (src->m_next != NULL) { //going through original list until hit null
			trg->m_next = new Node((src->m_next)->m_key, NULL); //creating new Node in target based on source list
			src = src->m_next; //incrementing both lists forward
			trg = trg->m_next;
		}
	}

	return *this; //new list with contents of sent list copied in
}

/// <summary>
/// method to insert number at correct spot in decreasing order
/// </summary>
/// <param name="value">int</param>
void List::insert(int value) {
	
	Node* p = m_head; //to iterate through list

	if (value > m_head->m_key) { //case when value is greater than 1st element, can just insert it now
		Node* temp = m_head;
		m_head = new List::Node(value, temp); //setting head to be new node with value and pointing to previous head node
		return;
	}
	
	while ((p->m_next != NULL) && (value < p->m_next->m_key)) { //keep advancing until value is greater than key of node after p
		p = p->m_next;
	}
	Node* temp = p->m_next; //so don't lose it when insert new node
	p->m_next = new List::Node(value, temp); //now new node placed in correct location
}

/// <summary>
/// method to remove the element given to the function
/// </summary>
/// <param name="value">int</param>
void List::remove(int value) {
	
	if (value == m_head->m_key) {
		Node* temp = m_head->m_next; //so we don't lose the address of the node after the one we are deleting
		m_head->m_next = NULL; //so we when delete head don't lose entire list
		delete m_head;
		m_head = temp;
		return;
	}

	Node* p = m_head; //to iterate through list
	while ((p->m_next != NULL) && (p->m_next->m_key != value)) { //keep checking until get to end of list or found value
		p = p->m_next;
	}
	if (p == NULL) { //left loop because reached end and didn't find
		throw "value not found";
	}
	Node* temp = p->m_next;
	p->m_next = temp->m_next; //current node now points to node after one want to remove
	delete temp; //now can delete the node, no need for it anymore
}

/// <summary>
/// cout operator overload method, friend to List and Node
/// </summary>
/// <param name="os">ostream&</param>
/// <param name="L">const List&</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, const List& L) {
	/*if (L.m_head == NULL) {
		throw string("list is empty, nothing to print");
	}*/
	List::Node* p = L.m_head;
	while (p != NULL) {
		os << p->m_key << " ";
		p = p->m_next;
	}
	return os;
}

/// <summary>
/// cin operator overload method, friend to List and Node
/// </summary>
/// <param name="is">istream&</param>
/// <param name="L">List&</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, List& L) {
	if (L.m_head != NULL) {
		L.clear(); //will be putting new values in that will overwrite, this way don't lose memory
	}
	int temp;
	is >> temp;

	L.add(temp); //adding in first element
	List::Node* p = L.m_head; //pointer to go through list
	is >> temp;

	while (temp < p->m_key) { //will only insert new element if in strictly decreasing order
		p->m_next = new List::Node(temp, NULL);
		p = p->m_next;
		is >> temp;
	}

	return is;
}
