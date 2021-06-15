/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 5 Question 2
This program will perform actions on a linked list
using the class List and its methods*/

#include "List.h"
#include<string>
#include <iostream>
using namespace std;

List merge(List L1, List L2);
//function to merge 2 sorted linked lists into one
//takes in 2 List parameters
//returns a newly merged list

void makeSet(List& L);
//function to get rid of duplicates in a sorted linked list
//takes in 1 parameter, a list as cbr
//does not return a value, changes list directly

void reverse(List& L);
//function to reverse the contents of a linked list
//takes in 1 parameter, a list as cbr
//does not return a value, changes list directly

int main() {
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}

List merge(List L1, List L2) {
    
	List L3 = L1; //putting values for first list into new one, and will use insert to put 2nd list in
	//insert try-catch when indexing
	int size = L2.listSize(); //getting size of 2nd list so have iteration boundry
	for (int i = 0; i < size; i++) {
		try {
			L3.insert(L2[i]); //inserting each element of l2 to l3 into proper place (non-ascending order)
		}
		catch (string s) { //catching if tried to index out of bounds
			cout << s;
			break;
		}
	}    //used insert because don't have tail to insert nodes at end of list
	return L3;
}

void makeSet(List& L) {
	int size = L.listSize(); 
	for (int i = 0; i < size - 1; i++) {
		//Check p->next->key, if equal to p->key, if so connect p->next to p->next->next
		if (L[i] == L[i + 1]) { //checking if key of current node is equal to key of next node
			L.remove(L[i]); //removing the node
			size--; //reducing size each time remove so don't exceed bounds
			i--; //indices change when remove an element
		}
	}
}

void reverse(List& L) {
	int size = L.listSize();
	
	int start = 0, end = size - 1;
	while (start < end) { //not actually changing list itself, just moving around the key values of all the nodes
		int temp = L[start];
		L[start] = L[end];
		L[end] = temp;
		start++; //keep moving closer to center as swapping values
		end--;
	}
}

/*enter sorted values for the first list:
6 5 4 3 2 1 9
enter sorted values for the second list:
7 5 4 3 9
the new merged list: 7 6 5 5 4 4 3 3 2 1
the new merged set: 7 6 5 4 3 2 1
the new merged reverse: 1 2 3 4 5 6 7

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework5.2\Debug\Homework5.2.exe (process 4180) exited with code 0.
Press any key to close this window . . .
*/