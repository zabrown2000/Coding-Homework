/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 6 Question 1

this program will take in 15 inputs from the user and through the use of 2 functions
will print out whether the numbers are between 1-15 (no doubles) (good or not good)*/

#include <iostream>
using namespace std;

void fillArray(int arr[], const int size);
//function to fill an array based on user input
//takes in 2 parameters, array and array size
//doesn't return a value--changes the array directly

bool checkNums(int arr2[], const int size);
//function to determine if the contents of an array are the digits 1 and 15
//takes in 2 parameters, array and array size
//returns a boolean value


int main() {
	int fifteenNum[15] = { 0 }, size = 15; //index will be 0-14
	bool isGood;

	cout << "enter 15 numbers:\n";

	fillArray(fifteenNum, size); //calling the function to fill up the array
	isGood = checkNums(fifteenNum, size); //calling the function to check if the contents of the array are between 1-15

	if (isGood == true) { //if return value from the function is true, then print good
		cout << "GOOD\n";
	}
	else { //the return value was false so print not good
		cout << "NOT GOOD\n";
	}
	return 0;
}


void fillArray(int arr[], const int size) {

	for (int i = 0; i < size; i++) 
		cin >> arr[i]; //filling each of the 15 inputs into the corresponding index
}

bool checkNums(int arr2[], const int size) {
	
	bool isFifteen = false;

	for (int i = 0; i < size; i++) { //needs to check that each digit is 1-15, no doubles
		
		
		if ((arr2[i] > 0) && (arr2[i] < 16)) { //first off, checking that the input is valid, between 1-15
			isFifteen = true;
		}
		else {
			isFifteen = false; //once there is a case of an invalid input, don't need to check anything else and can leave the loop
			break;
		}
		for (int j = i; j < size; j++) { //this loop will now check the current array value against the rest of the elements for a duplicate
			if (j != i) { //need this so the program doesn't check an element with itself, resulting in a false-false
				if (arr2[i] == arr2[j]) { //now checking if the actual element has an existing duplicate
					isFifteen = false;
				}
			}
			if (isFifteen == false) //leaving the j-loop once there is an instance of a duplicate
				break;
		}
		if (isFifteen == false) //leaving the i-loop if the j-loop ended because of a duplicate
			break;
	}

	return isFifteen;
}

/*
enter 15 numbers:
6 54 8 6 4 11 23 4 3 6 9 8 7 7 10
NOT GOOD

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.1\Debug\Homework6.1.exe (process 5624) exited with code 0.
Press any key to close this window . . .
*/