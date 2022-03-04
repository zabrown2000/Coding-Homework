/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 3
This program will take in data from the user for 3 circles
and will calculate their areas and circumferences. It will 
also determine where given points are located in respect to the 
3 circles. All will done using included classes and thier methods.*/

#include<iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

void checkPoint(Circle circle, Point point, int& counter);
//function to add to a counter if a point is on or in a circle
//takes in 3 parameters, circle object, point object, and int as cbr
//return no value as it updates the counter directly

int main() {
	
	Circle circleA, circleB, circleC;
	Point userPoint;
	int x, y, radius, sum, ctrA = 0, ctrB = 0, ctrC = 0;
	char ch;

	cout << "enter the center point and radius of 3 circles:\n";
	//taking in values for circleA and initializing
	cin >> ch >> x >> ch >> y >> ch >> radius;
	circleA.setCenter(x, y);
	circleA.setRadius(radius);

	//taking in values for circleB and initializing
	cin >> ch >> x >> ch >> y >> ch >> radius;
	circleB.setCenter(x, y);
	circleB.setRadius(radius);

	//taking in values for circleC and initializing
	cin >> ch >> x >> ch >> y >> ch >> radius;
	circleC.setCenter(x, y);
	circleC.setRadius(radius);

	//will print circumference for each cirlce, calling the method circumference on each circle
	cout << "perimeter:	A: " << circleA.circumference() << "	B: " << circleB.circumference()
		<< "	C: " << circleC.circumference() << endl;

	//will print area for each cirlce, calling the method area on each circle
	cout << "area:	A: " << circleA.area() << "    B: " << circleB.area()
		<< "	C: " << circleC.area() << endl;

	cout << "enter points until (0,0):\n";
	cin >> ch >> x >> ch >> y >> ch;
	do {

		userPoint.setX(x);  //reading in values and setting them using setter methods
		userPoint.setY(y);

		//going to check where point lies in respect to each of 3 circles
		checkPoint(circleA, userPoint, ctrA);
		checkPoint(circleB, userPoint, ctrB);
		checkPoint(circleC, userPoint, ctrC);

		cin >> ch >> x >> ch >> y >> ch;
		
		sum = x + y;
	} while (sum != 0); //keep going until hit point (0,0)

	cout << "num of points in circle:	A:" << ctrA << " B:" << ctrB << " C:" << ctrC << endl;

	return 0;
}

void checkPoint(Circle circle, Point point, int& counter) {
	int check;

	check = circle.findPoint(point); //calling method to find where point lies in respect to circle
	if (check <= 0) { //if returned -1 or 0, it's in or on circle
		counter++;
	}
}

/*enter the center point and radius of 3 circles:
(0,0) 3
(1,1) 2
(5,5) 2
perimeter:      A: 18.84        B: 12.56        C: 12.56
area:   A: 28.26    B: 12.56    C: 12.56
enter points until (0,0):
(0,1)
(1,0)
(0,4)
(0,0)
num of points in circle:        A:2 B:2 C:0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework1.3\Debug\Homework1.3.exe (process 16896) exited with code 0.
Press any key to close this window . . .
*/
