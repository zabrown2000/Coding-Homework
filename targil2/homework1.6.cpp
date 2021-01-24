#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 2 numbers and print out the values of the 4 basic math functions
*/

int main() {
	int num1, num2, numSum, numMinus, numMult;
	float numDivide; //made this a float so later on it can print a decimal if need be 
	cout << "enter two numbers:" << endl;
	cin >> num1 >> num2;
	numSum = num1 + num2;
	numMinus = num1-num2;
	numMult = num1 * num2;
	numDivide = (float)num1 / num2; //casted num1 to a float so the answer itself will result in a float-if whole number will print w/o .0
	cout << num1 << "+" << num2 << "=" << numSum << endl;
	cout << num1 << "-" << num2 << "=" << numMinus << endl;
	cout << num1 << "*" << num2 << "=" << numMult << endl;
	cout << num1 << "/" << num2 << "=" << numDivide << endl;
	return 0;
}

/*
enter two numbers:
8
4
8+4=12
8-4=4
8*4=32
8/4=2

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.6\Debug\Homework1.6.exe (process 14332) exited with code 0.
Press any key to close this window . . .
*/