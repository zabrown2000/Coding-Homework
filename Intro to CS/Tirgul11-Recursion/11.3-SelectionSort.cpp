/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 11 Question 3
This program will take in an array and its size from the
the user and will sort it in non-descending order using the
selection sort method in a recursive array*/

#include <iostream>
using namespace std;

void swap(int* arr2, int currentIndex, int minIndex);
//function to swap 2 values in an array
//takes in 3 parameters, a pointer to an array, and the indices for the elements to be swapped
//returns n value as it changes the array directly

int smallest(int* arr1, int size, int minIndex = 0, int currentIndex = 0);
//function to search through an array for the smallest element in an array and return its index, using recursive functions
//takes in 4 parameters, a pointer to the array, its size, and 2 indices that will be updated each function call
//returns int value of an index in the array

void sort(int* arr3, int size, int index = 0);
//function to sort an array in non-descending order using selection sort with a recursive function
//takes in 3 parameters, a pointer to the array, its size, and the index to keep track of where we are in the array
//does not return a value as it affects the array directly


int main() {
	int* arr;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0) {
			cout << "ERROR" << endl; //checking that user entered valid size
		}
	} while (num <= 0);

	arr = new int[num]; //dynamically allocating array with size from user
	cout << "enter array values: ";

	for (int i = 0; i < num; i++) { //inputting values into the array
		cin >> arr[i];
	}
	cout << "before: \n";

	for (int j = 0; j < num; j++) { //printing array before sorted
		cout << arr[j] << " ";
	}
	cout << endl;

	sort(arr, num); //calling function to sort the array

	cout << "after: \n";

	for (int k = 0; k < num; k++) { //printing array after sorted
		cout << arr[k] << " ";
	}
	cout << endl;

	delete[] arr;

	return 0;
}


void swap(int* arr2, int currentIndex, int minIndex) {
	int temp = arr2[currentIndex]; //setting current element to temp variable
	arr2[currentIndex] = arr2[minIndex]; //spot that had current element now has min element
	arr2[minIndex] = temp; //current element is now in spot previously held by min element
}

int smallest(int* arr1, int size, int minIndex, int currentIndex) {

	if (currentIndex >= size) {
		return minIndex; //this means we exceeded the boundries of the array, so the current minIndex value will be returned
	}
	else { //calling function again, this time sending for the indices: currentIndex if the element at that index is less
		   //than element at minIndex, and minIndex if otherwise (greater or equal), and we'll move on to the next element 
		   //in the array by moving currentIndex up by 1
		return smallest(arr1, size, (arr1[currentIndex] < arr1[minIndex] ? currentIndex : minIndex), currentIndex + 1);
	}
}
void sort(int* arr3, int size, int index) {

	if (index == size - 1) { //this means we got to the end of the array so the recursion stops here
		return;
	}
	int minIndex = smallest(arr3, size, index, index); //each call of sort we need to find the smallest element, and each time we'll be starting further into the array, because index is +1 each time call sort

	if (minIndex != index) { //if the index of the min element that we found is not the same as our current index, 
		swap(arr3, index, minIndex); //then swap the values of the 2
	}
	sort(arr3, size, index + 1); //calling function again to sort rest of elements, all elements until and including index are assumed to be sorted
}
/*enter a number:
4
enter array values: 6 5 5 8
before:
6 5 5 8
after:
5 5 6 8

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework11.3\Debug\Homework11.3.exe (process 27736) exited with code 0.
Press any key to close this window . . .

*/
