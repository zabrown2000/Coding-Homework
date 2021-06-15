/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 2
This program will compare fields of employees using
classes and methods*/

#include <iostream>
#include "Employees.h"
using namespace std;

//bool checkSsid(int id);
////function to check if an id number is not 9 digits
////takes in 1 int value
////returns true if id number is > or < 9 digits and false if = 9 digits

int main() {
	
	Employees tempEmp, minSumEmp, maxSalEmp;
	float maxSalary = 0, tempSalary;
	minSumEmp.setCollMoneyParm(9999999); //setting the min sum to default value so can compare it below

	cout << "enter details, to end enter 0:\n";

	do {
		//will call all setter methods to read in inputs for fields from user
		tempEmp.setSsid();
		if (tempEmp.getSsid() == 0) { //if user entered 0 then leave loop
			break;
		}
		tempEmp.setName();
		tempEmp.setWage();
		tempEmp.setHours();
		tempEmp.setCollMoney();

		//if ((checkSsid(tempEmp.getSsid())) || (tempEmp.getWage() < 0) || (tempEmp.getHours() < 0) || (tempEmp.getCollMoney() < 0)) {
		if ((tempEmp.getWage() < 0) || (tempEmp.getHours() < 0) || (tempEmp.getCollMoney() < 0)) {
			
			cout << "ERROR\n";    //checking that user entered all legal values, 9 digit ssid and no negatives
			continue; //if even 1 field has an error, ignore all inputs and move to next iteration
		}
		tempSalary = tempEmp.calcSalary(); //getting the total salary based on wages and hours and tempEmp

		if (tempSalary > maxSalary) { //if the temp salary is greater then current max salary then 

			maxSalEmp = tempEmp; //set fields of max salary employee to be equal to fields of tempEmp
			maxSalary = tempSalary;
		}
		if (tempEmp.getCollMoney() < minSumEmp.getCollMoney()) { //if the the amount collected is less than the current minimum then

			minSumEmp = tempEmp; //set fields of minimum sum employee to be equal to fields of tempEmp
		}

	} while (tempEmp.getSsid() != 0); //once user enters a 0 instead of ssid then stop reading in values and comparing
	
	cout << "minimum sum: " << minSumEmp.getCollMoney() << " " << minSumEmp.getName() << " " << minSumEmp.getSsid() << endl;
	cout << "highest salary: " << maxSalary << " " << maxSalEmp.getName() << " " << maxSalEmp.getSsid() << endl;

	return 0;
}

//bool checkSsid(int id) {
//	int counter = 1; //start counter at 1 to take into account 1 digit id that won't enter loop
//
//	while ((id / 10) != 0) { //as long as numbers remain when knock off the last digit, enter the loop
//		counter++; //increment amount of digits
//		id /= 10; //knock off the right most digit of the id
//	}
//	if (counter == 9) { //if the amount of digits is 9, return false, looking for when not 9
//		return false;
//	}
//	return true; //digits not equal to 9 so return true
//}

/*
enter details, to end enter 0:
111111111 doron 35 120 6000
222222222 tal 50 55 1400
444444444 levi 45 -4 100
ERROR
333333333 naomi 30 120 800
0
minimum sum: 800 naomi 333333333
highest salary: 5550 doron 111111111

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.2\x64\Debug\Homework1.2.exe (process 7760) exited with code 0.
Press any key to close this window . . .
*/