#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 3 numbers from the user and then print them out in order
of least to greatest
*/

int main() {

	int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;

	if (num1 > num2) {  //situations when num1 is more than num2
		if (num2 > num3) { //when num1 is more than num2 and num2 is more than num3
			biggest = num1;
			middle = num2;
			smallest = num3;
		}
		else if (num3 < num1 && num3 > num2) { //when num1 and num3 are more than num2 and num3 is less than num1
			biggest = num1;
			middle = num3;
			smallest = num2;
		}
		else if (num3 > num1) { //when num1 is more than num2 and num3 is more than num1
			biggest = num3;
			middle = num1;
			smallest = num2;
		}
	}
	else {    //num1 is not greater than num2 = num2 > num1
		if (num1 > num3) { //when num2 is more than num1 and num1 is more than num3
			biggest = num2;
			middle = num1;
			smallest = num3;
		}
		else if (num2 > num3 && num3 > num1) { //when num2 and num3 are more than num1 and num2 is more than num3
			biggest = num2;
			middle = num3;
			smallest = num1;
		}
		else {        //when num2 is more than num1 and num3 is more than num2
			biggest = num3;
			middle = num2;
			smallest = num1;
		}
	}

	cout << smallest << " " << middle << " " << biggest << endl;
	return 0;

}

/*
enter 3 numbers:
9
4
2
2 4 9

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.5\Debug\Homework3.5.exe (process 21780) exited with code 0.
Press any key to close this window . . .

*/

	