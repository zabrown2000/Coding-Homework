#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 2 numbers and read in a list of numbers until their 
sum is greater than the first number or the number of numbers read is equal 
to the second number, and then prints out the final sum
*/

int main() {

	int num1, num2, amountLimit, sumLimit, numList, newSum, sum = 0, amountCheck = 0;

	cout << "enter 2 positive numbers:\n";
	
	cin >> num1;           //checking that the first input was valid
	while (num1 <= 0) {
		cout << "ERROR\n";
		cin >> num1;
	}

	cin >> num2;           //checking that the second number was valid
	while (num2 <= 0) {
		cout << "ERROR\n";
		cin >> num2;
	}

	sumLimit = num1;  //setting the limit for the sum to num1
	amountLimit = num2; //setting the limit for the amount of numbers to be taken in to num2

	cout << "enter a list of numbers:\n";
	
	while (amountCheck < amountLimit && sum <= sumLimit) { //loop will run until the the amountLimit or sumLimit are reached 
		
		cin >> numList; //each round of the loop the next number from the list will be taken in
		
		newSum = numList; //setting the current sum to the most recent number stored
		
		sum += newSum; //adding the most recent number to the final sum
		
		amountCheck++; //adding 1 for each time a new number is stored
	}

	cout << sum << endl;
	
	return 0;
}

/*
enter 2 positive numbers:
0
ERROR
7
9
enter a list of numbers:
1 2 3 4 5 6 7 8 9
10

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.2\Debug\Homework4.2.exe (process 15712) exited with code 0.
Press any key to close this window . . .

*/
