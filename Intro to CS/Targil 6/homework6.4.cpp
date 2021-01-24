/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 6 Question 4

this program will take in 6 numbers from the user between 0 and 1 
and will output the indices of the inputed numbers in ascending order*/

#include <iostream>
using namespace std;

void fillArray(float arr[], const int size);
//funciton to fill an array with 6 numbers that are between 0 and 1 only
//takes in 2 parameters, the array and its size
//doesn't return a value because it fills the array directly

void swapOrder(int& index1, int& index2);
//function to swap 2 integer values (will use this to sort indices array)
//takes in 2 int parameters
//returns no value because the variables are being changed directly (call by reference)

void sortIndices(float arr1[], int arr2[], const int size);
//function to sort 1 array according to the values of another array of equal size (in ascending order)
//takes in 3 parameters, the 2 arrays and their size
//returns no value since it changes the array directly

void printArray(int arr3[], const int size);
//function to print out all the elements of an array 
//takes in 2 parameters, array and array size
//doesn't return a value because it is printing directly

int main() {

	float numbers[6], size = 6;

	cout << "enter  6 numbers between 0 and 1:\n";

	fillArray(numbers, size); //filling the array, only with legal values

	int indices[6] = {0,1,2,3,4,5}; //default values, will rearrange according to numbers array

	sortIndices(numbers, indices, size); //calling the function to sort the indices array according to the values of numbers, in ascending order

	cout << "sorted indices:" << endl;

	printArray(indices, size); //printing out the newly arranged indices array
	cout << endl;

	return 0;
}


void fillArray(float arr[], const int size) {

	bool isError = true; //will be used to control the loop below
	float input = 0; //so we can compare the input before putting it in the array
	
	while (isError == true) {
		isError = false; //starting off the loop with no problems, it will change if there is later on
		for (int i = 0; i < size; i++) {
			cin >> input;
			if (input <= 0 || input >= 1) { //if the input is less than 0 or greater than 1 than change the value to true--there is an input with an error
				isError = true;
			}
			else { //otherwise if the inputs are between 0 and 1 then fill the array element
				arr[i] = input;
			}
		}
		if (isError == false) {
			break; //if there isn't an error then end the loop here instead of printing out the error
		}
		cout << "ERROR\n";
	} 
}

void swapOrder(int& index1, int& index2) {
	int temp = index1; //setting temporary variable to index1
	index1 = index2; //index1 is now index2
	index2 = temp; //index2 is now temp (original index1)
}

void sortIndices(float arr1[], int arr2[], const int size) {

	for (int i = 0; i < size; i++) { //will be going through each value of arr1 at the indexes of arr2 (so it can be ordered)

		for (int j = i; j < size; j++) { //this loop will do the actual comparing and sorting
			
			//arr1=numbers, arr2=indices, will check if any number after itself is smaller than itself, 
			//and then swap the indices pointing to those numbers
			if (arr1[arr2[j]] < arr1[arr2[i]]) { //checking if arr1 at the index of index i (outer loop) is greater than the elements after it
				swapOrder(arr2[j], arr2[i]); //if the numbers after the current index are smaller, then swap the values of arr2 to reflect that
			}
		}
	}
}

void printArray(int arr3[], const int size) {
	for (int i = 0; i < size; i++) { //printing each element with a space after
		cout << arr3[i] << " ";
	}
}
/*
enter  6 numbers between 0 and 1:
0.9 0.05 0.1 0.4 0.2 0.3
sorted indices:
1 2 4 5 3 0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.4\Debug\Homework6.4.exe (process 16716) exited with code 0.
Press any key to close this window . . .
*/