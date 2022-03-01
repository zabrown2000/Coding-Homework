#include <iostream>
#include <ctime>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will produce 10 random numbers and then determine if they are in a sorted list or not
*/

int main() {
	
	int num1, num2;
	bool  isSorted = true;
	
	srand(unsigned int(time)); //initializing the random number function
	
	num1 = rand() % 1000 + 1; //establishing the first of the 10 random numbers
	cout << num1 << " "; //printing it out

	for (int i = 0; i < 9; i++) { //the loop will print out 9 more numbers as well as compare each new number to see if sorted
		
		num2 = rand() % 1000 + 1; //each loop a new number will be generated to num2
		cout << num2 << " "; //print out the new number

		if (num2 < num1) { //checking if the new number is less than the old, in which case we know off the bat it's not a sorted list

			isSorted = false;
			break;
		}

		num1 = num2; //setting num1 to the value of num2 to compare in the next loop
	}
	
	if (isSorted == true) {  //conditional statement to check which statement to print based on the boolean value from the loop
		cout << endl << "sorted list";
	}
	else {
		cout << endl << "not sorted list";
	}

	return 0;
}

/*
286 777 824 101 635 851 146 845 137 451
not sorted list
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.1\Debug\Homework4.1.exe (process 17876) exited with code 0.
Press any key to close this window . . .
*/



