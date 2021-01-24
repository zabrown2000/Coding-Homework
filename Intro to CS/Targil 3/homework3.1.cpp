#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in a 2 digit number from the user (check that it's a valid number) and will check whether 
the digits are even, odd, or mixed and will give an output based on the result
*/

int main() {

	int num, digit1, digit2;
	cout << "enter a number:" << endl;
	cin >> num;

	if ((num >= 10) && (num < 100)) {   //determining if number entered fit the parameters of a positive 2-digit number
		
		digit1 = (num / 10) % 10; //if the number fits then divide the number into 2 separate digits so we can compare them
		digit2 = num % 10;
	}
	else {
		cout << "ERROR\n"; //if it doesn't fit, it prints an error
	}

	if ((digit1 % 2 == 0) && (digit2 % 2 == 0)) { //number is even
		cout << "even digits only\n";
		cout << digit1 * digit2 << endl;
	}
	else if ((digit1 % 2 != 0) && (digit2 % 2 != 0)) { //number is odd
		cout << "odd digits only\n";
		cout << digit1 + digit2 << endl;
	}
	else { //mixed number, 1 is odd and 1 is even
		cout << "mixed number\n";
	}
	return 0;
}

/*
enter a number:
84
even digits only
32

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.1\Debug\Homework3.1.exe (process 20980) exited with code 0.
Press any key to close this window . . .

*/
