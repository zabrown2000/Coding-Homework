/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 2
This program will perform actions on a circular linked list
utilizing inheritance with classes*/

#include "RoundList.h"
#include <iostream>
using namespace std;

enum CHOICES { EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY };
int main() {

	RoundList ls1;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != EXIT) {
		int num;
		switch (choice) {
		case ADD: 	
			cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++) {
				cin >> num;
				try {
					ls1.add(num);
				}
				catch (const char* msg){
					cout << msg << endl;
				}
			}
			break;

		case ADD_TO_END:
			cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++) {
				cin >> num;
				ls1.addToEnd(num);
			}
			break;

		case REMOVE_FIRST: 
			ls1.removeFirst();
			break;

		case SEARCH: 
			cout << "Enter a number: ";
			cin >> num;
			cout << ls1.search(num) << endl;									  
			break;

		case CLEAR: 
			ls1.clear();
			break;

		case EMPTY: 
			if (ls1.isEmpty()) {
				cout << "Empty" << endl;
			}
			else {
				cout << "Not empty" << endl;
			}
			break;

		default: 
			cout << "ERROR!" << endl;
		}
		cout << "Enter your choice: ";
		cin >> choice;
	}
	return 0;
}

/*Enter your choice: 1
Enter 5 numbers: 1 2 3 4 5
Enter your choice: 2
Enter 5 numbers: 5 4 3 2 1
Enter your choice: 3
Enter your choice: 4
Enter a number: 2
2
Enter your choice: 3
Enter your choice: 4
Enter a number: 2
1
Enter your choice: 4
Enter a number: 6
2
Enter your choice: 0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.2\Debug\Homework6.2.exe (process 25584) exited with code 0.
Press any key to close this window . . .
*/
