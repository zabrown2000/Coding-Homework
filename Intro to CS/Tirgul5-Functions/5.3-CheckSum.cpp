#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in the first 8 digits of an ID number from the user
and will print out the full ID number, with the check digit at the end*/

int sumID(int idNum); 
//function to calculate the weighted sum of an id number
//takes in 1 int parameter
//returns int value

int checkID(int weightSum, int userID); 
//function to calculate the check-sum based on the weighted sum, and then put together the whole ID number
//takes in 2 int parameters: sum from function sumID and id input from the user
//returns int value

int main() {
	
	int idInput, idSum, fullID;

	cout << "enter your ID:\n";
	cin >> idInput;

	while (idInput < 10000000 || idInput > 99999999) { //checking that the user entered an 8-digit number
		cout << "ERROR\n";
		cin >> idInput;
	}

	idSum = sumID(idInput); //getting the weighted sum of the id number by calling the function sumID
	fullID = checkID(idSum, idInput); //getting the full id number with the check digit by calling the funciton checkID

	cout << "your full ID is:" << endl << fullID << endl;
	
	return 0;
}

int sumID(int idNum) {
	
	int digit, sum = 0;

	for (int i = 0; i < 8; i++) { //loop will happen 8 times because the number sent to the funciton is 8 digits

		if (i != 7) { //we only want the division and modulo to happen if the number is 2 digits, at the last iteration it will be a 1 digit number
			digit = idNum % 10; //taking off the last number of idNum
			idNum /= 10; //reducing numId by 1 digit
		}
		else {
			digit = idNum % 10; //don't need to divide for last round
		}
		
		if (i % 2 == 0) { //if i is even, 0,2,4,6, then multiply the digit by 2
			digit *= 2; 
		}
		else { //the other times (1,3,5,7), multiply the digit by 1
			digit *= 1;
		}

		if ((digit / 10) != 0) { //when the result of the above step is a 2-digit number then we need to add the 2 digits together
			digit = (digit % 10) + 1; //adding the right digit to 1 because the 2 digit numbers can only be 10-18 so the left digit will always be a 1
		}
		sum += digit; //accumilating the sum
	}

	return sum;
	
}

int checkID(int weightSum, int userID) {
	
	int oneDigit, checkSum, fullID;

	oneDigit = weightSum % 10; //taking the one's place digit from the weighted sum
	checkSum = 10 - oneDigit; //subtracting the above digit from 10 to get the check sum
	fullID = (userID * 10) + checkSum; //adding on the check digit to the end of the user id

	return fullID;
}

/*
enter your ID:
123
ERROR
123456789
ERROR
12345678
your full ID is:
123456782

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework5.3\Debug\Homework5.3.exe (process 29500) exited with code 0.
Press any key to close this window . . .
*/
