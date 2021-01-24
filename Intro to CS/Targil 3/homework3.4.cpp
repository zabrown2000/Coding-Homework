#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 3 numbers from the user and compute which triangle (if 
at all) the numbers fit in to
*/

int main() {
	
	int side1, side2, side3;
	cout << "enter 3 numbers:\n";
	cin >> side1 >> side2 >> side3;

	if ((side1 <= 0) || (side2 <= 0) || (side3 <= 0)) {
		cout << "ERROR\n";
	}

	if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1)) {
		cout << "cannot form a triangle\n";   //if there is one circumstance where any 2 of the sides are less than or equal to the third, it's not a triangle
	}
	else {
		if (side1 == side2 && side2 == side3) {  //if all sides are equal then it's an equilateral triangle
			cout << "equilateral triangle\n";
		}
		else if ((side1 == side2) || (side1 == side3) || (side2 == side3)) { //if any 2 sides are equal then it's isosceles
			cout << "isosceles triangle\n";
		}
		else {
			cout << "scalene triangle"; //if none of the sides are equal then it's scalene
		}
	}

	return 0;
}

/*
enter 3 numbers:
7 3 9
scalene triangle
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework3.4\Debug\Homework3.4.exe (process 17572) exited with code 0.
Press any key to close this window . . .

*/