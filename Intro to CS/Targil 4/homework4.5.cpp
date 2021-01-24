#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in a number from the user and print out the 
digits until that number in a triangle formation
*/

int main() {

	int numInput;

	cout << "enter a one digit number:\n";
	cin >> numInput;
	
	while (numInput <= 0 || numInput >= 10) { //when the input is illegal put in a new input
		cout << "ERROR\n";
		cin >> numInput;
	}


	for (int rowNum = numInput - 1; rowNum >= 0; rowNum--) { //outer loop prints out each row
		for (int i = numInput - 2; i >= rowNum; i--) { //prints out each column, set i = numInput-2 so it won't go the first time but will the other times
				cout << "   ";
		}
		int numOutput = rowNum; //the number that will be printed
			
		while (numOutput < numInput && numOutput >= 0) { //this loop will add a comma and space after each number
			cout << numOutput + 1; //added a 1 because rowNum is the input -1 and we want to start with the actual value of the input
				
			if (numOutput + 1 != 1) { //the comma and space will only print if we haven't gotten to the last number-->1
				cout << ", ";
			}
			else { //if it is =1 then we are at the last column in the row and need to move down to the next row
				cout << endl;
			}
			numOutput--; //decreasing so each iteration of the loop will print 1 less number
			} 
		}

	return 0;
}

/*
enter a one digit number:
7
7, 6, 5, 4, 3, 2, 1
   6, 5, 4, 3, 2, 1
	  5, 4, 3, 2, 1
		 4, 3, 2, 1
			3, 2, 1
			   2, 1
				  1

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.5\Debug\Homework4.5.exe (process 24432) exited with code 0.
Press any key to close this window . . .
*/