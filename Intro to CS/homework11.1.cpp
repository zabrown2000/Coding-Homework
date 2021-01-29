/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 11 Question 1
This program will print the letter 'a' followed by the letter 'b' n times,
which will be defined by the user-using a recursive function*/ 

#include <iostream>
using namespace std;

void printABs(int n);
//this function will print 'a' n times followed by 'b' n times
//takes in 1 parameter, n, to determine amount of times to print
//returns no value as it is printing directly

int main() {
	int numTimes;
	
	cout << "enter a number:" << endl;
	cin >> numTimes;

	while (numTimes < 0) { //checking to make sure user didn't enter negative input
		cout << "ERROR\n";
		cin >> numTimes;
	}
	
	printABs(numTimes); //calling recursive function to print the a's and b's
	
	return 0;
}

void printABs(int n) {
	if (n == 0) {
		return;
	} 
	cout << "a"; //printing out a the first time
	printABs(n - 1); //will print a n-1 times since did it once already
	cout << "b"; //after all the function calls are done for a, b will get printed n times
	
}

/*enter a number:
5
aaaaabbbbb
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework11.1\Debug\Homework11.1.exe (process 32760) exited with code 0.
Press any key to close this window . . .
*/
