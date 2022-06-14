/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 3
This program will perform actions on strings based 
on defined class String and operation overloads*/

#include <iostream>
#include<cstring>
#include "String.h"
using namespace std;

int main() {
	
	char* temp1 = new char[100]; //need to initialize memory so can read in from user
	char* temp2 = new char[100];
	char ch;
	int index;

	cin >> temp1 >> temp2;
	String a(temp1), b(temp2); //creating 2 new strings sending 2 words read in from user
	cin >> index;

	if (a < b) { //if string a comes before string b
		cout << "a<b" << endl;
	}
	if (a > b) { //if string a comes after string b
		cout << "a>b" << endl;
	}
	if (!(a != b)) { //if the 2 strings aren't not equal, meaning they are equal
		cout << "a=b" << endl;
	}
	
	String newStr = b.insert(index, temp1); //assigning the string returned from insert to the new string
	if (newStr != "") { //if a non-empty string was returned (no errors)
		newStr.print(); //printing new string that was created
	}

	cin >> ch >> index;
	if (index < 0 || index >= newStr.getLength()) { //checking uf user entered index out range, end program
		cout << "ERROR\n";
		delete[] temp1;
		delete[] temp2;
		return 0; //can end program down, error printed in function itself
	}
	newStr.getArray()[index] = ch; //updating element in string at given index to given char
	
	newStr.print(); //printing new result (no errors)

	delete[] temp1;
	delete[] temp2;
	return 0;
}

/*hello
hello
2
a=b
hehellollo
!
4
hehe!lollo

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.3\Debug\Homework3.3.exe (process 26280) exited with code 0.
Press any key to close this window . . .
*/
