#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in inputs from the user with dimensions for a rectangle and
a circle and will output the areas using function calls
*/

int area(int length, int width);
//function to calculate the area of a rectangle
//takes in 2 int parameters
//returns int value

double area(int radius); 
//function to calculate the area of a circle
//takes in 1 int parameter
//returns double value

int main() {

	int rectLength, rectWidth, cirRadius, rectArea;
	double cirArea;

	cout << "enter length and width of the rectangle:\n";
	cin >> rectLength >> rectWidth;

	while (rectLength <= 0 || rectWidth <= 0) { //checking if either input from the user is invalid, in which case the user would need to enter 2 new values
		cout << "ERROR\n";
		cin >> rectLength >> rectWidth;
	}

	rectArea = area(rectLength, rectWidth); //calling on function area and it will go to the first function because 2 int parameters were sent
	cout << rectArea << endl; //print the area of the rectangle from the value that was returned from the function

	cout << "enter radius of the circle:\n";
	cin >> cirRadius;

	while (cirRadius <= 0) { //checking if input from user was good or not and making the user enter a new legal input
		cout << "ERROR\n";
		cin >> cirRadius;
	}

	cirArea = area(cirRadius); //calling on function area and it will go to the second function because 1 int parameter was sent
	cout << cirArea; //print the area of the circle from the value that was returned from the function

	return 0;
}

int area(int length, int width) {
	
	int rectArea;
	rectArea = length * width;
	return rectArea;
}

double area(int radius) {
	const double PI = 3.14159;
	double cirArea;
	cirArea = PI * radius * radius;
	return cirArea;
}

/*
enter length and width of the rectangle:
2
4
8
enter radius of the circle:
1
3.14159
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework5.1\Debug\Homework5.1.exe (process 17460) exited with code 0.
Press any key to close this window . . .
*/
