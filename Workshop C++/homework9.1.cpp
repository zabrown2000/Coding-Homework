/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 1
This program will perform actions on a binary search tree*/

#include <iostream>
using namespace std;
#include "SearchTree.h"
enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
	SearchTree<int> T1;
	cout << "enter 10 numbers:\n";
	int x, y, z;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-8:\n";
	cin >> x;
	while (x != END)
	{
		switch (x)
		{
		case ADD: cout << "enter a number: \n";
			cin >> y;
			T1.add(y);
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
			break;
		case SEARCH: cout << "enter a number: \n";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "no exist" << endl;
			break;
		case REMOVE:cout << "enter a number: \n";
			cin >> y;
			try
			{
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.inOrder();
				cout << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case BREADTHSCAN: cout << "breadth scan: ";
			T1.breadthScan();
			cout << endl;
			break;
		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;
		case SUCCESSOR:cout << "enter a number: \n";
			cin >> y;
			try
			{
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case DELETEDUP: cout << "after delete duplicate: ";
			T1.deleteDuplicates();
			T1.inOrder();
			cout << endl;
			break;
		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}
		cout << "enter 0-8:\n";
		cin >> x;
	}
	return 0;
}

/*enter 10 numbers:
6 9 5 4 7 9 2 5 56 0
inorder: 0 2 4 5 5 6 7 9 9 56
enter 0-8:
1
enter a number:
42
after adding 42: 0 2 4 5 5 6 7 9 9 42 56
enter 0-8:
2
enter a number:
20
no exist
enter 0-8:
2
enter a number:
9
exist
enter 0-8:
3
enter a number:
7
after removing 7: 0 2 4 5 5 6 9 9 42 56
enter 0-8:
4
breadth scan: 6 5 9 4 9 56 2 5 42 0
enter 0-8:
5
height of tree: 4
enter 0-8:
6
enter a number:
56
no successor
enter 0-8:
6
enter a number:
9
successor of 9 is: 42
enter 0-8:
7
after delete duplicate: 0 2 4 5 6 9 42 56
enter 0-8:
8
reflected tree: 56 42 9 6 5 4 2 0
enter 0-8:
0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework9.1\Debug\Homework9.1.exe (process 13852) exited with code 0.
Press any key to close this window . . .
*/