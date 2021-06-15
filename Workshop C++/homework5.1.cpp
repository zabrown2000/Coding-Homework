/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 5 Question 1
This program will insert and remove elements to/from 
a linked list*/

#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char* msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		
		//try {
		//	cout << lst << endl;
		//}
		//catch (string s) { //catching error when trying to print empty list
		//	cout << s << endl;
		//}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}

/*enter the list values
3 2 1 1
choose 0-2
2
enter a value to remove
2
3 1
choose 0-2
1
enter a value to insert
4
4 3 1
choose 0-2
1
enter a value to insert
2
4 3 2 1
choose 0-2
0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework5.1\Debug\Homework5.1.exe (process 30968) exited with code 0.
Press any key to close this window . . .
*/