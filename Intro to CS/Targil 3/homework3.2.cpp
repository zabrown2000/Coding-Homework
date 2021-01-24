#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 3 numbers and determine whether the 3rd is in the range of the others and print 
a statement stating where it falls
*/

int main() {

	int first, last, number;
	cout << "enter 3 numbers:\n";
	cin >> first >> last >> number;

	if ((number >= first) && (number <= last)) { //checking if the number is in the range-between-the 2 numbers
		cout << "between" << endl;
	}
	else if (number < first) {  //if number is less than smaller number, out of range-smaller
		cout << "smaller" << endl;
	}
	else {  //all other cases, which would be the number is more than the bigger number so it's out of range-bigger
		cout << "bigger" << endl;
	}

	return 0;
}

/*
enter 3 numbers:
10 15 20
bigger

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.2\Debug\Homework3.2.exe (process 20700) exited with code 0.
Press any key to close this window . . .

*/