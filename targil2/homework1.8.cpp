#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in from the user 3 inputs for flight departure, 3 for flight duration 
and will compute and print out the time of arrival
*/

int main() {
	int takeHour, takeMin, takeSec; 
	int durHour, durMin, durSec; 
	int arrivalHour, arrivalMin, arrivalSec;
	
	cout << "enter flight takeoff:" << endl;
	cin >> takeHour >> takeMin >> takeSec;
	
	cout << "enter flight duration:" << endl;
	cin >> durHour >> durMin >> durSec;
	
	// combining totals for all 3 types
	arrivalSec = takeSec + durSec;
	arrivalMin = takeMin + durMin + (arrivalSec / 60); //adding an extra minute if the total seconds is >60
	arrivalHour = takeHour + durHour + (arrivalMin / 60); //adding an extra hour if the total hours is >60
	
	arrivalHour = arrivalHour % 24; //getting rid of problem if total hours is more than 24
	arrivalMin = arrivalMin % 60; //takes care of any extra minutes if the total is more than 60
	arrivalSec = arrivalSec % 60; //takes care of any extra seconds if the total is more than 60
	
	cout << "flight arrival is:" << endl;
	cout << arrivalHour << ":" << arrivalMin << ":" << arrivalSec << endl;
		
	return 0;
}

/*
enter flight takeoff:
15
20
25
enter flight duration:
20
10
15
flight arrival is:
11:30:40

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.8\Debug\Homework1.8.exe (process 5244) exited with code 0.
Press any key to close this window . . .
*/

//if (arrivalSec > 59) {           //need an if statement here and for min because time is only from 1-60 not 1-100
	//	++arrivalMin;
	//	arrivalSec = arrivalSec - 60;
	//}

	//if (arrivalMin > 59) {
	//	++arrivalHour;
	//	arrivalMin = arrivalMin - 60;
	//}

	//if (arrivalHour >= 24) {            //because output time is from 0-23 hours, need to take into account when the total hours is 24 or more
	//	arrivalHour = arrivalHour - 24;
	//}