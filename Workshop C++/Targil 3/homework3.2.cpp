/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 2
This program will perform actions on a date using a 
class and operation overload methods*/

#include <iostream>
#include "Date.h"
using namespace std;

enum Actions { SET_DATE = 1, PRE_ADD, POST_ADD, ADD_EQUAL, GREATER_THAN, LESS_THAN, IS_EQUAL };

int main() {

	int day, month, year, choice, num;
	char ch;

	cout << "Enter a date\n";
	cin >> day >> ch >> month >> ch >> year;

	Date userDate(day, month, year); //initializing new object using values from user
	Date newDate; //for later use
	userDate.print(); //calling print method

	cout << "Enter an action code:\n";
	cin >> choice;

	while (choice != -1) { //loop will keep going until -1 is entered

		switch (choice) {

		case SET_DATE: //case when user enters a 1, to set the date of an object
			cout << "Enter a date:\n";
			cin >> day >> ch >> month >> ch >> year;
			userDate.setDate(day, month, year); //sending new values to update the date and printing it
			userDate.print();
			break;
		
		case PRE_ADD: //case when user enters 2, calling pre-increment operator
			(++userDate).print(); //printing result
			break;

		case POST_ADD: //case when user enters 3, calling post-increment operator
			(userDate++).print(); //printing result
			break;

		case ADD_EQUAL: //case where user enters 4, calling += operator
			cout << "Enter # days\n";
			cin >> num;
			(userDate += num).print(); //using += operator to add days to a date and printing result
			break;

		case GREATER_THAN: //case where user enters 5, calling > operator on 2 dates      
			cout << "Enter a date\n";
			cin >> day >> ch >> month >> ch >> year;
			newDate.setDate(day, month, year); //creating new date to compare
			cout << ">: "; //will check if one date is later than other
			(userDate > newDate) ? cout << "true" : cout << "false"; cout << endl; //using shorthand if to print true or false
			break;

		case LESS_THAN: //case where user enters 6, calling < operator on 2 dates 
			cout << "Enter a date\n";
			cin >> day >> ch >> month >> ch >> year;
			newDate.setDate(day, month, year); //creating new date to compare
			cout << "<: "; //will check if one date is earlier than other
			(userDate < newDate) ? cout << "true" : cout << "false"; cout << endl; //using shorthand if to print true or false
			break;

		case IS_EQUAL: //case where user enters 7, calling == operator on 2 dates
			cout << "Enter a date\n";
			cin >> day >> ch >> month >> ch >> year;
			newDate.setDate(day, month, year); //creating new date to compare
			cout << "==: "; //will check if one date is equal to other
			(userDate == newDate) ? cout << "true" : cout << "false"; cout << endl; //using shorthand if to print true or false
			break;

		default:
			cout << "ERROR\n";
			break;
		}

		cout << "Enter an action code:\n";
		cin >> choice;
	}

	return 0;
}
/*Enter a date
-5/1/2012
Error day
1/1/2012
Enter an action code:
1
Enter a date:
5/7/2010
5/7/2010
Enter an action code:
2
6/7/2010
Enter an action code:
3
6/7/2010
Enter an action code:
4
Enter # days
7
14/7/2010
Enter an action code:
5
Enter a date
14/7/2010
>: false
Enter an action code:
7
Enter a date
14/7/2010
==: true
Enter an action code:
-1

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.2\Debug\Homework3.2.exe (process 38440) exited with code 0.
Press any key to close this window . . .
*/