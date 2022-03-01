/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 11 Question 4
This program will take in an array of size defined by the user, and will print out 
the array after having the values reversed, using recursion*/

#include <iostream>
using namespace std;


void swap(int* arr2, int a, int b);
//function to swap 2 values in an array
//takes in 3 parameters, a pointer to an array, and the indices for the elements to be swapped
//returns n value as it changes the array directly

void reverse(int* arr1, int size, int left = 0);
//function to reverse the elements in an array using recursion
//take in 3 parameters, a pointer to the array, its size, and the left boundry
//does not return a value as it changes the array directly

int main() {
	
	int* arr;
	int num;
	cout << "enter a number: ";
	cin >> num;
	
	arr = new int[num]; //creating array of size num given by the user
	
	cout << "enter array values: ";
	for (int i = 0; i < num; i++) { //filling array with values from the user
		cin >> arr[i];
	}
	cout << "before: \n";
	for (int j = 0; j < num; j++) { //printing array as is, before reversal
		cout << arr[j] << " ";
	}
	cout << endl;
	reverse(arr, num); //calling function to change all the values in the array so they are in reverse order
	
	cout << "after: \n";
	for (int k = 0; k < num; k++) { //printing array after values are reversed
		cout << arr[k] << " ";
	}
	cout << endl;
	return 0;
}

void swap(int* arr2, int a, int b) {
	int temp = arr2[a]; //setting element a to temp variable
	arr2[a] = arr2[b]; //spot that had element a now has element b
	arr2[b] = temp; //element b is now a previously held by temp
}

void reverse(int* arr1, int size, int left) {

	if (size <= 1) { //if function is sent a size of 1 or lowers, nothing to do so just end this function iteration
		return;
	}

	if (left < size) { //because as we call the function again we are changing the boundries, once left becomes greater than or equal to the size, we are done swapping
		swap(arr1, left, size-1); //swapping the current first and last elements
		reverse(arr1, size - 1, left + 1); //calling reverse again moving inwards in the array
	}
}
/*enter a number: 6
enter array values: 7 8 9 6 5 4
before:
7 8 9 6 5 4
after:
4 5 6 9 8 7

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework11.4\Debug\Homework11.4.exe (process 34064) exited with code 0.
Press any key to close this window . . .
*/
