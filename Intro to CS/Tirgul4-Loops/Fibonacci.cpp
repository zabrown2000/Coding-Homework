#include <iostream>
using namespace std;

/*
Zahava Brown
TZ: 346287956
This program will print out x numbers from the fibonacci sequence 
(each number is the sum of previous 2 numbers), where x is 
the input from the user
*/

int main() {

	int input, fib1 = 0, fib2 = 1, nextFib = 0;
    
	cout << "enter a number:\n";
	cin >> input;

  
    
    while (input < 0) {  //a loop to make sure that the user enter a positive number only and to keep printing error until a legal input is given
                  
            cout << "ERROR\n";
            cin >> input; 
        
	}

    for (int counter = 1; counter <= input + 1; ++counter) { //the loop will run as long as the counter is less than or equal to the input # +1
        
        if (counter == 1) { //in the first loop round it will print the first number which we declared in the beginning
            cout << fib1 << " ";
            continue; //after the print it leaves the loop so the variable fib1 won't change
        }

        if (counter == 2) { //in the second loop round it will print the second number which we declared in the beginning
            cout << fib2 << " ";
            continue; //after the print it leaves the loop so the variable fib2 won't change
        }

        nextFib = fib1 + fib2; //once in the 3rd loop round, we are determining the new number, by taking the sum of the first 2
        fib1 = fib2; //changing the 2 places-ago-number to the last-place-ago
        fib2 = nextFib; //changing the last-place-ago number to the current number being printed

        cout << nextFib << " ";
    }

	return 0;
}

/*
enter a number:
-8
ERROR
9
0 1 1 2 3 5 8 13 21 34
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework4.3\Debug\Homework4.3.exe (process 27744) exited with code 0.
Press any key to close this window . . .

*/
