#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in a number from the user and through 2 functions (nested)
it will print out all the perfect numbers less than that number*/


bool perfect(int inputFactor); 
//function to determine if a number is perfect or not
//takes in 1 int parameter
//returns boolean value

void perfectCount(int num1 = 500); 
//function to print out all the perfect numbers below the input number
//takes in 1 int parameter, and if no input sent will default to 500
//returns no value (will print out instead)

int main() {
	
	int numInput;

	cout << "enter a number:\n";
	cin >> numInput;

	while (numInput <= 0) { //checking that the input was legal
		cout << "ERROR\n";
		cin >> numInput;
	}

	perfectCount(numInput); //calling the function perfectCount with parameter numInput
	perfectCount(); //calling the function perfectCount with no parameter
	
	return 0;
}

bool perfect(int inputFactor) {
	
	int sum = 0;
	bool isPerfect;

	for (int i = 1; i < inputFactor; i++) { //starting from 1, the loop will check which numbers less than the input are factors of the input

		if (inputFactor % i == 0) { //if the number divided by i has no remainder than it is a factor
			sum += i; //add the value of i to sum
		}
	}
	if (sum == inputFactor) { //once the loop finishes the sum is compared to the value of the input number
		isPerfect = true; //if the values are equal than the number is a perfect number
	}
	else {
		isPerfect = false; //if it's not equal then it's not a perfect number
	}

	return isPerfect; //return the value of isPerfect

}

void perfectCount(int num1) {

	bool isPerfect; 

	for (int i = 1; i < num1; i++) { //now the loop will call on funciton perfect to check if each number below num1 is a perfect number
		
		isPerfect = perfect(i);

		if (isPerfect == true) { //if i is a perfect number than print it out with a space after
			cout << i << " ";
		}
		
		if (i == (num1 - 1)) { //when we are in the last iteration of the loop go to a new line
			cout << endl; //this way whether or not any numbers were printed there will still be a new line
		}
	}

	//now calculating and printing out the perfect numbers below 500: 6 28 496
	for (int i = 1; i < 500; i++) { //now the loop will call on funciton perfect to check if each number below 500 is a perfect number

		isPerfect = perfect(i);

		if (isPerfect == true) { //if i is a perfect number than print it out with a space after
			cout << i << " ";
		}
	}
	cout << endl;
}
