/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 4 Question 1
This program will perform like an ATM, allowing the user to input
data and do functions that one would do at an ATM*/

#include "Clock.h"
#include "Account.h"
#include <iostream>
using namespace std;

enum action { stop, balance, deposit, withdraw, sumDeposit, sumWithdraw };

action menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl << endl;

	int x;
	try {  //need to check if user entered valid menu option
		cin >> x;
		if (x < 0 || x > 5) {
			throw string("ERROR: choose an option between 0 and 5");
		}
		return (action)x;
	}
	catch (string s) {
		cout << s << endl;
		return (action)x;
	}
}

int findAccount(Account* bank, int size) {
	int number, code;
	cout << "please enter account number: \n";
	cin >> number;
	int i = 0;

	 //put loop in try in case tries to access invalid account (acc # not found because it doesn't exist)
	while (i < size && bank[i].getAccNum() != number) {
		i++;
	}
	if (bank[i].getAccNum() != number)
		throw "ERROR: no such account number!\n";

	cout << "please enter the code: \n";
	cin >> code;
	if (bank[i].getCode() == code) {
		return i;
	}
	else { //in cases when account number doesn't match code
		throw "ERROR: wrong code!\n";
	}
}

void printTransaction(Account a, action ac, Clock& c) {
	cout << c << "\t";
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccNum() << "\t";
		cout << "balance: " << a.getBal() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccNum() << "\t";
		cout << "new balance: " << a.getBal() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	}
}

void getBalance(Account* bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}

void cashDeposit(Account* bank, int size, Clock& c) {
	int i;
	try {
		i = findAccount(bank, size);
	}
	catch (const char* msg) { //catching error from find account, problem with acc number or code
		throw msg; //sending to function call in main
	}

	float amount;
	cout << "enter the amount of the check: \n";
	cin >> amount;
	try {
		bank[i].deposit(amount, c);
	}
	catch (string s) { //above deposit limit
		cout << c << '\t' << s << endl;
		return;
	}
	c += 30;
	printTransaction(bank[i], deposit, c);
}

void cashWithdraw(Account* bank, int size, Clock& c) {
	int i;
	try {
		i = findAccount(bank, size);
	}
	catch (const char* msg) { //catching error from find account, problem with acc number or code
		throw msg; //sending to function call in main
	}

	float amount;
	cout << "enter the amount of money to withdraw: \n";
	cin >> amount;
	try {
		bank[i].withdraw(amount, c);
	}
	catch (int x) { //above overdraft limit or user wants to withdraw more than 2500
		if (x == 2500) {
			cout << c << '\t' << "ERROR: cannot withdraw more than 2500 NIS!" << endl;
			return;
		}
		if (x == 6000) {
			cout << c << '\t' << "ERROR: cannot have less than - 6000 NIS!" << endl;
			return;
		}
	}
	c += 50;
	printTransaction(bank[i], withdraw, c);
}


int main() {
	Clock c(8,0,0);
	Account bank[10];
	cout << "enter account number, code and email for 10 accounts:\n";
	for (int i = 0; i < 10; i++) {
		try {
			try {
				cin >> bank[i];
			}
			catch (string s) { //catching any errors when reading in details: code not 4 digits, no @ in email, end of email invalid
				cout << c << '\t' << s << endl;;
				i--;
				continue;
			}

			for (int j = 0; j < i; j++)
				if (bank[i].getAccNum() == bank[j].getAccNum())                   
					throw "ERROR: account number must be unique!\n";

		}
		catch (const char* msg) { //catching wrong account number
			cout << c << '\t' << msg;
			i--;
			continue;
		}
	}
	action ac = menu();

	while (ac != 0) {

		switch (ac) {
		case balance:
			getBalance(bank, 10, c);
			break;
		case withdraw:
			try {
				cashWithdraw(bank, 10, c);
			}
			catch (const char* msg) { //catching error from cashWithdraw function which caught from findAccount
				cout << c << "\t" << msg;
			}
			break;
		case deposit:
			try {
				cashDeposit(bank, 10, c);
			}
			catch (const char* msg) { //catching error from cashDeposit function which caught from findAccount
				cout << c << "\t" << msg;
			}

			break;
		case sumWithdraw:
			c += 60;
			printTransaction(bank[0], sumWithdraw, c);
			break;
		case sumDeposit:
			c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		}
		ac = menu();
	}

	return 0;
}

/*enter account number, code and email for 10 accounts:
1 1111 aaa@gmail.com
2 222 bbb@gmail.com
08:00:00        ERROR: code must be of 4 digits!
2 2222 bbb@gmail.com
2 3333 ccc@gmail.com
08:00:00        ERROR: account number must be unique!
3 3333 ccc@gmail.com
4 4444 dddgmail.com
08:00:00        ERROR: email must contain @
4 4444 ddd@gmail.co
08:00:00        ERROR: email must end at .com or .co.il!
4 4444 ddd@gmail.com
5 5555 eee@gmail.com
6 6666 fff@gmail.co.il
7 7777 ggg@gmail.com
8 8888 hhh@gmail.com
9 9999 iii@gmail.com
10 1010 jjj@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
4
please enter the code:
444
08:00:00        ERROR: wrong code!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
11
08:00:00        ERROR: no such account number!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
4
please enter the code:
4444
enter the amount of the check:
11000
08:00:00        ERROR: cannot deposit more than 10000 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
4
please enter the code:
4444
enter the amount of the check:
5000
08:00:30        account #: 4    new balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

3
please enter account number:
4
please enter the code:
4444
enter the amount of money to withdraw:
3000
08:00:30        ERROR: cannot withdraw more than 2500 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

1
please enter account number:
4
please enter the code:
4444
08:00:50        account #: 4    balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

3
please enter account number:
4
please enter the code:
4444
enter the amount of money to withdraw:
12000
08:00:50        ERROR: cannot have less than - 6000 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

1
please enter account number:
4
please enter the code:
4444
08:01:10        account #: 4    balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
2
please enter the code:
2222
enter the amount of the check:
1500
08:01:40        account #: 2    new balance: 1500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

2
please enter account number:
10
please enter the code:
1010
enter the amount of the check:
9000
08:02:10        account #: 10   new balance: 9000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

3
please enter account number:
2
please enter the code:
2222
enter the amount of money to withdraw:
2000
08:03:00        account #: 2    new balance: -500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

3
please enter account number:
10
please enter the code:
1010
enter the amount of money to withdraw:
600
08:03:50        account #: 10   new balance: 8400
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

4
08:04:50        sum of all deposits: 15500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

5
08:05:50        sum of all withdraws: 2600
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.1\Debug\Homework4.1.exe (process 27032) exited with code 0.
Press any key to close this window . . .
*/
