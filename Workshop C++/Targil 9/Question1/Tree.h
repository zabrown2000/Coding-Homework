/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 1
This program will define and implement an abstract template class Tree*/

#ifndef TREE_H
#define TREE_H

#include "QueueVector.h"
#include <iostream>
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
		Node(Node&& n) noexcept {
			if (left) {
				delete left;
				left = n.left;
			}
			if (right) {
				delete right;
				right = n.right;
			}
			value = n.value;
		}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int height() { return height(root); }; //method to get height of tree
	void reflect() { reflect(root); }; //method to swap values of tree so get mirror image of original
	void breadthScan(); //method to print nodes of tree according to level

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;
	


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int height(Node* current); //recursive helper function for public height method
	void reflect(Node* current); //recursive helper function for public reflect method

};







//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

/// <summary>
/// method to print nodes of tree according to level
/// </summary>
/// <typeparam name="T">template class tree</typeparam>
template<class T>
void Tree<T>::breadthScan() {
	
	QueueVector<Node*> queue(11); //want queue to hold pointers to nodes
	Node* p;
	//algorithm:
	//1. enqueue root to queue
	queue.enqueue(root);
	//2. while queue not empty do following:
	while (!(queue.isEmpty())) {

		try {
		//		a. dequeue and print element
			p = queue.dequeue(); 
			cout << p->value << " ";
		//		b. for element just removed, add its sons to queue (if it has)
			if (p->left) {
				queue.enqueue(p->left);
			}
			if (p->right) {
				queue.enqueue(p->right);
			}
		}
		catch (const char* msg) {
			cout << msg;
		}
		
	}
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

/// <summary>
/// recursive method to find height of tree
/// </summary>
/// <typeparam name="T">template tree class</typeparam>
/// <param name="current">Node*</param>
/// <returns>int</returns>
template<class T>
int Tree<T>::height(Node* current) {
	if (current == nullptr) {
		return -1; //empty tree
	}
	if ((current->left == nullptr) && (current->right == nullptr)) {
		return 0; //single node tree
	}
	//more than 1 node in tree:
	int leftHeight = height(current->left); //getting height of left subtree
	int rightHeight = height(current->right); //getting height of right subtree

	return ((leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1); //returns max height of 2 subtrees, and adding 1 to account for height of zero
}

/// <summary>
/// method to swap nodes of tree to make a reflection
/// </summary>
/// <typeparam name="T">template class tree</typeparam>
/// <param name="current">Node*</param>
template<class T>
void Tree<T>::reflect(Node* current) {

	if (!current) {
		return; //hit end of tree, no more swapping needed
	}
	//will work down from root and swap nodes on each side
	Node* temp = current->left;
	current->left = current->right;
	current->right = temp;

	//recursive calls to go further down tree
	reflect(current->left);
	reflect(current->right);
}


#endif // !TREE_H


