#include <iostream> 
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will take in 2 inputs from the user, x and n, and
will print out the sum of a series based in x, n number of times
Series is: X + (-1/3)X^3  + (1/5)X^5 + (-1/7)X^7 + …. +((-1)^n-1/2n-1)X^2n-1 
*/

int main() {

	int x, n, coefTop, coefBottom;
	double sum = 0, nextEl, x_term, coefWhole; //these are doubless to account for any decimals that will form

	cout << "enter 2 numbers:\n";
	cin >> x >> n;

	while (n <= 0) {
		cout << "ERROR\n";
		cin >> n;
	}

	coefTop = -1; //starting at -1 because we will be mult it against itself and the first term needs to be positive
	coefBottom = 1; //we'll be adding 2 to this each time, but it starts with 1 so the result will be odd
	
	for (int i = 0; i < n; i++) {

		coefTop *= -1; //each time mult by -1 to determine the sign of the whole term
		coefWhole = (double)coefTop / coefBottom; //the whole coefficient is now put together, and need to cast at least one variable because coefWhole is a double

		x_term = 1; //setting it to 1 before loop because at end of main loop x_term is much bigger
		for (int j = 0; j < coefBottom; j++) { //now we need to set up the base and exponent

			x_term *= x; //taking the factorial of x coefBottom amount of times
		}
		coefBottom += 2; //adding 2 to 1 for each time n, so the result will keep being odd=1,3,5,7...

		nextEl = coefWhole * x_term; //setting the next element, which is all the calculations together
		sum += nextEl; //adding each new element to the sum
	}

	cout << sum;

	return 0;
}

/*
enter 2 numbers:
3
-8
ERROR
2
-6
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.4\Debug\Homework4.4.exe (process 7928) exited with code 0.
Press any key to close this window . . .

*/
