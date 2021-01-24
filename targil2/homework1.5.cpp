#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 2 inputs from the user 
and print them in 2 directions
*/

int main() {
	int x, y;
	cout << "enter two numbers:" << endl;
	cin >> x >> y;
	cout << "x=" << x << ", y=" << y << endl;
	x = x + y; //if x=3 and y=5, then x=8 and y=5
	y = x - y; //x=8 and y=3
	x = x - y; //x=5 and y=3
	cout << "x=" << x << ", y=" << y << endl;
	return 0;
}

/*
enter two numbers:
3
5
x=3, y=5
x=5, y=3

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.5\Debug\Homework1.5.exe (process 14192) exited with code 0.
Press any key to close this window . . .
*/