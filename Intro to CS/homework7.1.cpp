/*Zahava Brown
* TZ: 346287956
* Intro to Computer Science-Joyce Vogel
* Lab 7 Question 1
* This program will take in an array and a seperate number from the
* user and will print if the number was found in the array or not, if
* yes then it will also print where in the array the number is located
*/

#include <iostream>
using namespace std;

bool isSorted(const int arr2[], int size);
//function to check if an array is in ascending order
//takes in 2 parameters, an array and its size
//does not return a value because it changes the array directly

bool noDuplicates(const int arr3[], int size);
//checks if there are any duplicates in an array
//takes in 2 parameters, an array and its size
//does not return a value because it changes the array directly

void fillArray(int arr[], const int size);
//function to fill an array and check that the inputs are valid
//takes in 2 parameters, an array and its size
//does not return a value because it changes the array directly

int binarySearch(const int arr[], int size, int userNum);
//function to search for an element in an array using the binary search method
//takes in 3 parameters, the array, array size, and the number from the user
//returns int value of the index of the number if it's found, otherwise returns -1


int main() {
	int array[10] = { 0 }, num, numIndex;

	cout << "enter 10 numbers:\n";
	fillArray(array, 10); //sending array to function to fill it up with valid inputs

	cout << "enter 1 number:\n";
	cin >> num;
	numIndex = binarySearch(array, 10, num); //search the array for the number and return the index if found

	if (numIndex < 0) { //if it wasn't found, it will return -1, so the following statement will be executed
		cout << "not found\n";
	}
	else { //this means the number was found and will print where it is located
		cout << "the number " << num << " was found at index " << numIndex << endl;
	}
	
	return 0;
}


bool isSorted(const int arr2[], int size) {
	
	for (int i = 0; i < size - 1; i++) { //each iteration checks if the current element is greater than the next element
		if (arr2[i] > arr2[i + 1]) //if do >= don't need duplicates function
			return false;	//if there is one case where condition is true, return false and leave the function
	}
	return true; //if got here, it means every element is ascending so return true
}

bool noDuplicates(const int arr3[], int size) {
	
	for (int i = 0; i < size; i++) { //need 2 loops so can check each element against every other element
		for (int j = 0; j < size; j++) {
			if (j != i) { //don't want this because then function will return a false false
				if (arr3[i] == arr3[j])
					return false; //once there is 1 case of a duplicate return false and end the funciton
			}
		}
	}
	return true; //this means there were no duplicates so return true
}

void fillArray(int arr[], int size) {
	bool isAscending, noDoubles;

	do {
		isAscending = true; //need these here so it will reset in each iteration of the loop
		noDoubles = true;
		for (int i = 0; i < size; i++) { //first fill the array with whatever was inputted
			cin >> arr[i];
		}
		isAscending = isSorted(arr, size); //calling on the function to check if the user gave ascending numbers
		noDoubles = noDuplicates(arr, size); //calling on the function to make sure the user didn't input any duplicates

		if (isAscending == false || noDoubles == false) //if 1 of these is false then print error, so the user can input more values
			cout << "ERROR\n";
	} while (isAscending == false || noDoubles == false); //as long as 1 of these was false need to go through the loop again
}

int binarySearch(const int arr[], int size, int userNum) {

	int left = 0, right = size - 1, middle = 0;

	while (left <= right) { //left boundry should never be to the right of the right boundry
		middle = (left + right) / 2; //with binary search start from middle of boundries

		if (arr[middle] < userNum) { //then will look in 2nd half of the array
			left = middle + 1;
		}
		else if (arr[middle] > userNum) { //then will look in 1st half of the array
			right = middle - 1;
		}
		else { //if here then arr[middle] == userNum
			left = right + 1; //so changing condition to end the while loop
		}
	}
	if (arr[middle] == userNum) { //if left loop either means the number was found or the boundries changed naturally because the number wasn't found
		return middle; //return the index of the found number
	}
	else {
		return -1; //ends the function
	}
}
/*enter 10 numbers:
1 3 5 5 9 11 13 15 17 19
ERROR
1 3 5 2 9 11 13 15 17 19
ERROR
1 3 5 7 9 11 13 15 17 19
enter 1 number:
5
the number 5 was found at index 2

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework7.1\Debug\Homework7.1.exe (process 15032) exited with code 0.
Press any key to close this window . . .
*/