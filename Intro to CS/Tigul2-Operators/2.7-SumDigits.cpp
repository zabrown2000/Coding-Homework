#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take a 3 digit number and calculate the sum of the digits and print
*/

int main() {
	int num1, ones, tens, hundreds, sum;
	cout << "enter a three digit number:" << endl;
	cin >> num1;
	hundreds = num1 / 100; //will give answer without remainder
	tens = (num1 / 10) % 10; //get the tens as 2 digit # and then get just the remainder
	ones = num1 % 10; //will get remainder of divided by 10
	sum = hundreds + tens + ones;
	cout << "the sum is: " << sum << endl;
	return 0;
}

/*

enter a three digit number:
715
the sum is: 13

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.7\Debug\Homework1.7.exe (process 22392) exited with code 0.
Press any key to close this window . . .
*/
