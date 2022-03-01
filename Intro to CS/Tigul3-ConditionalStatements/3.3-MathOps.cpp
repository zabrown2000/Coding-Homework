#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 2 numbers from the user and perform 1 of the 4 
math operators on the 2 numbers based on the operator the user enters
*/

int main() {
	double num1, num2;
	char opInput;

	cout << "enter 2 numbers:\n";
	cin >> num1 >> num2;
	cout << "enter an operator:\n";
	cin >> opInput;

	switch (opInput) {          //a switch statement to determine which operation will be perfored on the 2 numbers
	case '+': 
		cout << num1 << " " << opInput << " " //when the user inputs a + sign, addition is performed on the 2 numbers
			<< num2 << " = " << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 << " " << opInput << " "  //when the user inputs a - sign, subtraction is performed on the 2 numbers
			<< num2 << " = " << num1 - num2 << endl;
		break;
	case '*': 
		cout << num1 << " " << opInput << " "  //when the user inputs a * sign, multiplication is performed on the 2 numbers
			<< num2 << " = " << num1 * num2 << endl;
		break;
	case '/':
		cout << num1 << " " << opInput << " "  //when the user inputs a / sign, division is performed on the 2 numbers
			<< num2 << " = " << num1 / num2 << endl;
		break;
	default:
		cout << "ERROR\n";
	}

	return 0;
}

/*
enter 2 numbers:
5
6
enter an operator:
/
5 / 6 = 0.833333

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.3\Debug\Homework3.3.exe (process 22604) exited with code 0.
Press any key to close this window . . .

*/
