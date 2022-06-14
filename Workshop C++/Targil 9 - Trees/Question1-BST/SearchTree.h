/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 1
This program will define and implement a derived template class SearchTree*/

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value) { return search(Tree<T>::root, value); }
	T successor(T val); //method to return value of successor of node=val
	void remove(T val); //method to delete node whose value=val from tree
	void deleteDuplicates() { deleteDupes(Tree<T>::root); } //method to delete duplicate values in a tree

private:
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* searchNode(T val, typename Tree<T>::Node* current); //helper method to return a pointer to a node containing value (or null)
	typename Tree<T>::Node* minimum(typename Tree<T>::Node* current); //helper method to find minimum value for a given rooted tree
	typename Tree<T>::Node* findParent(typename Tree<T>::Node* current, typename Tree<T>::Node* child); //helper method to find parent of a given node
	void remove(typename Tree<T>::Node* tRoot, T val); //helper method to remove node from a tree
	void deleteDupes(typename Tree<T>::Node*& current); //helper method for deleting duplicates
};


//----------------------------------------------------------
//  class SearchTree implementation
//----------------------------------------------------------


template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

/// <summary>
/// method to return value of successor of node=val
/// </summary>
/// <typeparam name="T">template class searchtree</typeparam>
/// <param name="val">T</param>
/// <returns>T</returns>
template<class T>
T SearchTree<T>::successor(T val) {
	//getting pointer to node whose value is val
	typename Tree<T>::Node* current = searchNode(val, Tree<T>::root); 
	if (current == nullptr) {
		throw "no successor";
	}

	//if node has a right son, find minimum
	if (current->right != nullptr) {
		return minimum(current->right)->value;
	}

	//otherwise need to climb up tree until on left subtree of a father, and return the father
	typename Tree<T>::Node* temp = findParent(Tree<T>::root, current);
	while ((temp != nullptr) && (current == temp->right)) {
		current = temp;
		temp = findParent(Tree<T>::root, current);
	}
	if (!temp) {
		throw "no successor";
	}
	return temp->value;
}

/// <summary>
/// method to delete node whose value=val from tree
/// </summary>
/// <typeparam name="T">template class searchtree</typeparam>
/// <param name="val">T</param>
template<class T>
void SearchTree<T>::remove(T val) {
	typename Tree<T>::Node* tempRoot = searchNode(val, Tree<T>::root); //getting pointer to first occurence of node with value want to delete
	if (!tempRoot) {
		throw "value not found";
	}
	remove(tempRoot, val); //calling recursive remove to go through all possible cases
	
}


template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

/// <summary>
/// method to search for node in tree and return pointer to it if found
/// </summary>
/// <typeparam name="T">template class searchtree</typeparam>
/// <param name="val">T</param>
/// <returns>Node*</returns>
template<class T>
typename Tree<T>::Node* SearchTree<T>::searchNode(T val, typename Tree<T>::Node* current) {

	typename Tree<T>::Node* p = current;
	while (p) { //will keep searching tree as long as havne't reached null node
		if (p->value == val) {
			return p;
		}
		else { //current node pointed to by p is not val, so check left and right
			if (val <= p->value) {
				p = p->left; //its a bst, so values lower than or equal node will be on left
			}
			else { //greater value will go on the right
				p = p->right;
			}
		}
	}
	return nullptr; //didn't find node in tree
}

/// <summary>
/// helper method to find minimum value for a given rooted tree
/// </summary>
/// <typeparam name="T">template class searchtree</typeparam>
/// <param name="current">Node*</param>
/// <returns>Node*</returns>
template<class T>
typename Tree<T>::Node* SearchTree<T>::minimum(typename Tree<T>::Node* current) {
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}

/// <summary>
/// helper method to find parent of a given node
/// </summary>template class searchtree</typeparam>
/// <param name="current">Node*</param>
/// <param name="child">Node*</param>
/// <returns>Node*</returns>
template<class T>
typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* current, typename Tree<T>::Node* child) {   //make find parent find address rather than value?
	if (current == nullptr) return nullptr; //empty tree								//and then fix all places that use to make sure still works

	if ((current->left == nullptr) && (current->right == nullptr)) { //leaf node
		return nullptr;
	}
										                                       
	if (((current->left != nullptr) && (current->left == child)) || ((current->right != nullptr) && (current->right == child))) {
		return current; //1 of sons of current has value looking for
	}

	if (current->value >= child->value) { //current root is greater than or equal to searching value so look to left
		return findParent(current->left, child);
	}
	if (current->value < child->value) { //current root is less than searching value so look to right
		return findParent(current->right, child);
	}
}

/// <summary>
/// helper method to remove node from a tree
/// </summary>
/// <typeparam name="T">template class searchtree</typeparam>
/// <param name="tRoot">Node*</param>
/// <param name="val">T</param>
template<class T>
void SearchTree<T>::remove(typename Tree<T>::Node* tRoot, T val) {
	
	// Case 1: node to be deleted is a leaf
	if (tRoot->left == nullptr && tRoot->right == nullptr) {

		if (tRoot != Tree<T>::root) {
			typename Tree<T>::Node* parent = findParent(Tree<T>::root, tRoot);


			if (parent->left == tRoot) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
		}
		else {
			Tree<T>::root = nullptr;
		}
		delete tRoot;
	}

	// Case 2: node to be deleted has two children
	else if (tRoot->left && tRoot->right) {
		
		typename Tree<T>::Node* succ = minimum(tRoot->right); // find its successor node(has right son, so just minimum)
		tRoot->value = succ->value; // copy value of the successor to the current node

		if ((succ->left == nullptr && succ->right == nullptr) && (tRoot->right == succ)) { //when have leaf duplicate on right
			delete tRoot->right;
			tRoot->right = nullptr;
			return;
		}
		remove(succ, succ->value);
	}
	// Case 3: node to be deleted has only one child
	else {

		typename Tree<T>::Node* temp = nullptr, *parent = findParent(Tree<T>::root, tRoot);
		char child = (parent->left == tRoot) ? 'L' : 'R'; //determining which son tRoot is for later

		//getting child of node to delete and then deleting node
		if (tRoot->right == nullptr) {
		temp = tRoot->left;
		delete tRoot;
		}
		else if (tRoot->left == nullptr) {
		temp = tRoot->right;
		delete tRoot;
		}
		//assigning parent to point to child found above
		if (child == 'L') {
			parent->left = temp;
		}
		else {
			parent->right = temp;
		}
	}
}

template<class T>
void SearchTree<T>::deleteDupes(typename Tree<T>::Node*& current) {
	
	if (current == nullptr) {
		return;
	}
	typename Tree<T>::Node* temp = searchNode(current->value, current->left); //finding node that is a duplicate

	if (temp) { //if returned a node will remove the duplicate
		remove(temp, temp->value);
		deleteDupes(current); //keep going to check if any more duplicates from current root
	}
	else { //check for duplicates in left and right subtrees
		deleteDupes(current->left); 
		deleteDupes(current->right);
	}
	
	

}



#endif // !SEARCHTREE_H

