#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in a positive number and determine if each digit is less than the previous one*/

int main() {

	int userInput, digit, nextLeft;
	bool isLessThan = true;

	cout << "enter a number:\n";
	cin >> userInput;

	while (userInput <= 0) {
		
		cout << "ERROR\n";
		cin >> userInput;
	}
	
	digit = 0; //initializing so can be used later
	nextLeft = userInput % 10; //this gets the remainder of the number after divided by 10 which will be the right most digit
	userInput /= 10; //doing this once out of the loop so we can check if the input was a 1 digit number
	
	do {

		if (userInput == 0) { //off the bat we know if the answer to userInput/10 was 0 then it was a 1-digit number which was deemed to be true
			break; //leave the loop, there is nothing else to be done since it was a 1-digit number
		}
		
		digit = nextLeft; //setting digit to our first left digit so we can get the next one and compare them
		nextLeft = userInput % 10; //the next left number that we will then compare

		
		if (digit >= nextLeft) { //comparing the current left-most digit with the next left digit to check that it is less
			isLessThan = false; //if it's greater than or equal to the next left digit then it retains a false status which will be used later on
			break; //we can leave the loop because all digits have to be less than the one on its left, so once one is false, the whole thing is false
		}

	} while ((userInput /= 10) != 0); //loop will run as long as the answer to the new division isn't 0 (if it was 0 the first time it won't matter because we took care of it)
	

	if (isLessThan == true) { //if the value is true then all digits are less than the digit to the left, or it's a 1-digit number
		cout << "YES";
	}
	else {
		cout << "NO"; //there was at least one case where a digit was greater than or equal to its next-left digit
	}
	
	return 0;
}

/*
enter a number:
4321
YES
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.6\Debug\Homework4.6.exe (process 22460) exited with code 0.
Press any key to close this window . . .
*/


