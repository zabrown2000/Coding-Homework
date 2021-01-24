#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in a number from 1-12 from the user which 
will then be stored as an enum value with a month name and then the 
program will output the amount of days in the respective 
month using a switch statement
*/


int main() {
	
	int monthInput;

	enum MONTH {JAN = 1, FEB, MARCH, APRIL, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};

	cout << "enter a number:\n";
	cin >> monthInput;

	switch (monthInput) {  //the switch will now compare the input value to the values that the enum types were assigned to: 1-12
	case JAN:       //all the months that have 31 days will have the below statement printed
	case MARCH: 
	case MAY: 
	case JULY: 
	case AUG: 
	case OCT: 
	case DEC:
		cout << "31 days in the month" << endl;
		break;
	case APRIL:     //all the months that have 30 days will have the below statement printed
	case JUNE: 
	case SEPT: 
	case NOV:
		cout << "30 days in the month" << endl;
		break;
	case FEB:           //feb is by itself because no other months share the amount of days
		cout << "28 days in the month" << endl;
		break;
	default:
		break;
	}
 
	return 0;
}

/*
enter a number:
5
31 days in the month

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.6\Debug\Homework3.6.exe (process 5844) exited with code 0.
Press any key to close this window . . .

*/
