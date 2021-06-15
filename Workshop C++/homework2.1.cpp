/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 2 Question 1
This program will read in values for 2 polygons and calculate 
their perimeters and compare them*/

#include<iostream>
#include<cmath>
#include "Point.h"
#include "Polygon.h"
using namespace std;

void fillPoints(Polygon& shape, int size);
//function to fill in values of array of Points
//takes in 2 parameters, Polygon object and size of array to be filled
//returns no value as it changes the object directly

int main() {
	
	int sides;
	bool isEqual;
	float perimeter1, perimeter2;
	
	//creating first object of type polygon
	cout << "enter number of sides:\n";
	cin >> sides;
	Polygon polygon1(sides); //creating a polygon using constructor
	fillPoints(polygon1, sides); //calling function to fill the vertices from the user

	//creating second object of type polygon
	cout << "enter number of sides:\n";
	cin >> sides;
	Polygon polygon2(sides); //creating a polygon using constructor
	fillPoints(polygon2, sides); //calling function to fill the vertices from the user

	//calling the perimeter methods for each polygon and rounding the result to nearest int value
	perimeter1 = round(polygon1.perimeter());
	perimeter2 = round(polygon2.perimeter());

	if (perimeter1 != perimeter2) {
		cout << "perimeter:" << perimeter1 << endl << "perimeter:" << perimeter2 << endl;
	}
	else { //perimeters are equal
		cout << "equal perimeter:" << perimeter1 << endl;
	}
	
	return 0; 
}

void fillPoints(Polygon& shape, int size) {
	
	int x, y;
	char ch;

	cout << "enter the point values:\n";
	
	for (int i = 0; i < size; i++) {
		cin >> ch >> x >> ch >> y >> ch;

		shape.getVertices()[i].setX(x); //setting x-value for point in array in object at index i to be what user entered
		shape.getVertices()[i].setY(y); //setting y-value for point in array in object at index i to be what user entered
	}
}
/*enter number of sides:
4
in constructor
enter the point values:
(0,0) (0,2) (2,2) (2,0)
enter number of sides:
3
in constructor
enter the point values:
(1,1) (2,0) (3,1)
perimeter:8
perimeter:5
in destructor
in destructor

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework2.1\Debug\Homework2.1.exe (process 31608) exited with code 0.
Press any key to close this window . . .
*/