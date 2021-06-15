/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 2
This program will act as a library using a BST of type book*/

#include "SearchTree.h"
#include "Book.h"
#include <iostream>
using namespace std;

enum {ADD = 'a', REMOVE = 'b', SEARCH = 'c', PRINT = 'd', EXIT = 'e' };

int main() {

	SearchTree<Book> Library;
	Book inBook;
	char choice;
	bool exists;

	cout << "enter a-e:\n";
	cin >> choice;

	while (choice != EXIT) {

		switch (choice) {

		case ADD:
			cout << "enter a book\n";
			cin >> inBook;
			Library.add(inBook);
			break;

		case REMOVE:
			cout << "enter a book\n";
			cin >> inBook;
			try {
				Library.remove(inBook);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;

		case SEARCH:
			cout << "enter a book\n";
			cin >> inBook;
			exists = Library.search(inBook);
			cout << (exists) ? "exist\n" : "not exist\n";
			break;

		case PRINT:
			Library.inOrder(); //books entered into tree lexigraphically so in order should print in right order
			break;

		default:
			cout << "error\n";
			break;
		}
		cout << "enter a-e:\n";
		cin >> choice;
	}

	return 0;
}

/*enter a-e:
a
enter a book
2 b b
enter a-e:
a
enter a book
5 e e
enter a-e:
a
enter a book
1 a a
enter a-e:
a
enter a book
4 d d
enter a-e:
a
enter a book
7 g g
enter a-e:
a
enter a book
3 c c
enter a-e:
b
enter a book
5 e e
enter a-e:
d
1 a a
 2 b b
 3 c c
 4 d d
 7 g g
 enter a-e:
e

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework9.2\Debug\Homework9.2.exe (process 24620) exited with code 0.
Press any key to close this window . . .
*/