/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 11 Question 2
This program will take in an array and its size from the 
the user and will print out the smallest element*/

#include <iostream>
using namespace std;


int smallest(int* arr1, int size, int minIndex = 0, int currentIndex = 0);
//function to search through an array for the smallest element in an array and return its index, using recursive functions
//takes in 4 parameters, a pointer to the array, its size, and 2 indices that will be updated each function call
//returns int value of an index in the array

int main() {
	int* array;
	int num;
	do {
		cout << "enter a number:" << endl;
		cin >> num;
		if (num <= 0) { //making sure user entered valid array size
			cout << "ERROR" << endl;
		}
	} while (num <= 0);
	
	array = new int[num]; //dynamically allocating array with size from user
	cout << "enter array values: ";
	
	for (int i = 0; i < num; i++) { //filling the array
		cin >> array[i];
	}
	cout << "the smallest is: " << array[smallest(array, num)] << endl; //calling the function to return the index of the smallest element so we can print the element from the array at that index
	
	delete[] array;

	return 0;
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

/*enter a number:
5
enter array values: 62 54 14 98 78
the smallest is: 14

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework11.2\Debug\Homework11.2.exe (process 2736) exited with code 0.
Press any key to close this window . . .

*/
