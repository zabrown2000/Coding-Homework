/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 7 Question 1
This program will implement different shapes using 
inheritance and polymorhpism*/

#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"


int main() {

	int numShapes;

	cout << "How many shapes you would like to define?\n";
	cin >> numShapes;

	Shape** shapes = new Shape * [numShapes]; //making array of pointers to shapes of different types

	for (int i = 0; i < numShapes; i++) {
		cout << "Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4\n";
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: //make circle
			cout << "Enter radius:\n";
			float radius;
			cin >> radius;
			shapes[i] = new Circle(radius);
			break;

		case 3: //make triangle
			shapes[i] = new Triangle(); 
			break;

		case 4: //make rectangle
			shapes[i] = new Rectangle();
			break;

		default: //user entered incorrect choice
			cout << "invalid input\n";
			--i;
			break;
		}
	}

	//printing all relevant info for each shape
	for (int i = 0; i < numShapes; i++) {
		cout << "points: "; 
		//printing the points
		if (shapes[i]->getNum() == 1) { //printing points of a circle
			cout << shapes[i]->getPoints()[0];
		}
		else if (shapes[i]->getNum() == 3) { //printing points of triangle
			for (int j = 0; j < 3; j++) {
				cout << shapes[i]->getPoints()[j];
			}
		}
		else if (shapes[i]->getNum() == 4) { //printing points of rectangle
			for (int j = 0; j < 4; j++) {
				cout << shapes[i]->getPoints()[j];
			}
		}

		cout << "area is: " << shapes[i]->area() << endl;

		bool isSpecial = shapes[i]->isSpecial(); //finding out if this shape is special
		if (isSpecial) { //if returned true prints the relevant info
			shapes[i]->printSpecial();
		}
		cout << endl;
	}

	//deleting allocated memory
	for (int i = 0; i < numShapes; i++) {
		delete[] shapes[i];
	}
	delete[] shapes;
	return 0;
}

/*How many shapes you would like to define?
3
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
3
Enter values of 3 points:
(0,0) (1,0) (1,1)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
1
Enter radius:
4
Enter values of 1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
2
invalid input
Which shape will you choose? Circle - 1, Triangular - 3, Rectangle - 4
4
Enter values of 4 points:
(0,0) (1,0) (1,1) (0,1)
points: (0,0) (1,0) (1,1) area is: 0.5

points: (0,0) area is: 50.24
A canonical circle with a radius 4

points: (0,0) (1,0) (1,1) (0,1) area is: 1
Square with side length 1

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework7.1\Debug\Homework7.1.exe (process 11804) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/