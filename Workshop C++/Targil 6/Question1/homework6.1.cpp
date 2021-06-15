/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 6 Question 1
This program will act as a database for different
types of employees using inheritance*/

#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main() {
	
	FullTime arrF[3];
	for (int i = 0; i < 3; i++) {
		try {
			cin >> arrF[i];
		}
		catch (const char* str) {
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++) {
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str) {
			cout << str << endl;
			i--;
		}
	}

	cout << endl;
	for (int i = 0; i < 3; i++) {
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl << endl;
	}


	for (int i = 0; i < 3; i++) {
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl << endl;
	}
	return 0;
}

/*Enter employee details:
aaa 1111 1 24000
Enter employee details:
bbb 2222 2 36000
Enter employee details:
ccc 3333 6 48000
Enter employee details:
ddd 4444 3 160 35
Enter employee details:
eee 5555 4 200 45
Enter employee details:
fff 6666 7 240 50

Employee: aaa
Employee ID: 1111
Years Seniority: 1
Salary per Month: 2000
After Bonus: 2500

Employee: bbb
Employee ID: 2222
Years Seniority: 2
Salary per Month: 3000
After Bonus: 3500

Employee: ccc
Employee ID: 3333
Years Seniority: 6
Salary per Month: 4000
After Bonus: 5000

Employee: ddd
Employee ID: 4444
Years Seniority: 3
Hours: 160
Salary per Month: 5600
After Bonus: 6100

Employee: eee
Employee ID: 5555
Years Seniority: 4
Hours: 200
Salary per Month: 9000
After Bonus: 9500

Employee: fff
Employee ID: 6666
Years Seniority: 7
Hours: 240
Salary per Month: 12000
After Bonus: 15000


C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.1\Debug\Homework6.1.exe (process 17556) exited with code 0.
Press any key to close this window . . .
*/