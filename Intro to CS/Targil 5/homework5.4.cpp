#include <iostream>
#include <cstdlib>
#include <ctime> //so we can produce random numbers later on
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take an input from the user and using 2 fuctions (1 will be nested) will print out 
the next prime number that is greater than or equal to the input */

bool isPrime(int num1); 
//function to check if number is prime or not
//takes in 1 int parameter
//returns boolean value

int findPrime(int num2); 
//function that produces the next prime number (or the same number)
//takes in 1 int parameter
//returns int value

int main() {
	
	int numInput, tableSize;
	srand( (unsigned)time(NULL) ); //setting up the random numbers to be generated

	cout << "enter number of values:\n";
	cin >> numInput;

	if (numInput < 0) { //if the user entered a negative number
		
		numInput = (rand() % 91 + 10); //set the numInput to a random number from 10-100
	}

	tableSize = findPrime(numInput); //calling on function findPrime with numInput as the parameter to find the lowest prime number

	cout << "table size: " << tableSize << endl;

	return 0;
}

bool isPrime(int num1) {
	bool prime;
	
	if (num1 == 1 || num1 == 2) { //before checking the number in the loop, if it's 1 or 2 then we know it's prime and no further action is needed
		prime = true;
	}
	else { //otherwise we need to further investigate the status of this number
		for (int i = 2; i < num1; i++) { //the loop will now divide the number starting from 2 up to the number itself
			if (num1 % i == 0) { //if the number is able to be divided by another number with no remainder then we know it's not prime
				prime = false; 
				break; //no need to keep checking because once there is one instance of the number having a factor then we know it's not prime
			}
			else {
				prime = true; //if there is a remainder then the number is prime, and as long as that stays true for all values of i then it will be prime
			}
		}
	}
	return prime;
}

int findPrime(int num2) {
	
	int lowestPrime;
	bool prime;

	do { //using do-while so the fuction will run at least once with the number it received
		prime = isPrime(num2); //calling on the function prime to check if num2 is prime and storing the return to prime
		if (prime == true) { //if the function returns a true value
			lowestPrime = num2; //set lowestPrime to num2, because we are looking for the smallest prime number >= num2, and here it's equal
		}
		else { //otherwise set prime to false so the loop will keep going
			prime = false;
			++num2; //increment num2 by 1 so it will keep checking the next higher number until it reaches a prime number
		}
	} while (prime == false); //loop will continue as long as prime is false
	
	return lowestPrime; //return the lowest prime number
}

/*
enter number of values:
-8
table size: 17

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework5.4\Debug\Homework5.4.exe (process 25832) exited with code 0.
Press any key to close this window . . .
*/