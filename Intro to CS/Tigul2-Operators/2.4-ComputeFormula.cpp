#include <iostream>
using namespace std;

/* Zahava Brown
  TZ: 346287956
  This function will take 2 inputs from the user and compute them in the formula (5*a + 3) / (6*b + 2) and then print it out
*/

int main() {
	int a, b;
	float c; //made c a float so output would be a decimal
	cout << "enter two numbers:" << endl;
	cin >> a >> b; //store input values in a and b
	c = (5.0 * a + 3) / (6.0 * b + 2); //made the 5 and 6 floats so the entire answer would be converted implicitly from int->float
	cout << "c=" << c;
	return 0;
}

/*
enter two numbers:
2
0
c=6.5
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework1.4\Debug\Homework1.4.exe (process 19388) exited with code 0.
Press any key to close this window . . .
*/
