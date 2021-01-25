/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 7 Question 2
This program will take in 3 arrays from the user and will print out a
merged array with all the values in descending order
*/

#include <iostream>
using namespace std;

void fillArray(int arr[], const int size);
//function to fill an array based on user inputs
//takes in 2 parameters, the array and its size
//does not return a value since it changes the array directly

bool isSorted(const int arr2[], int size);
//function to check if an array is in strictly descending order
//takes in 2 parameters, an array and its size
//does not return a value because it changes the array directly

void mergeArrays(int arr1[], int arr2[], int arr3[], int arrMerge[], int size1, int sizeMerge);
//function that takes in 3 arrays and merges them into 1 long array in descending order
//takes in 4 array parameters, with sizes for each
//does not return a value because it changes the array (arrMerge) directly

void printArray(int arr[], int size);
//function to print the elements of an array
// takes in 2 parameters, an array and its size
//does not return a value

int main() {
	int vec1[10] = { 0 }, vec2[10] = { 0 }, vec3[10] = { 0 }, vecMerge[30] = { 0 };

	cout << "enter values for the first vector:\n";
	fillArray(vec1, 10);

	cout << "enter values for the second vector:\n";
	fillArray(vec2, 10);

	cout << "enter values for the third vector:\n";
	fillArray(vec3, 10);

	mergeArrays(vec1, vec2, vec3, vecMerge, 10, 30); //calling function to merge 3 arrays into 1

	cout << "merged vector is:\n";
	printArray(vecMerge, 30);

	return 0;
}

void fillArray(int arr[], const int size) {
	bool isDescending, isPositive;
	int num;
	
	do {
		isDescending = true; //need these here so it will reset in each iteration of the loop
		isPositive = true;
		for (int i = 0; i < size; i++) { //first fill the array with whatever was inputted
			cin >> num;
	
			if (num != 0) { //as long as the input isn't 0, add the element to the array
				arr[i] = num;
				if (num < 0) { //still adding negatives to the array but will still need to input new values
					isPositive = false;
				}
			}
			else { //once reach a 0, means user input is finished
				break;
			}
		}
		if (isPositive == false) {
			cout << "ERROR\n";
			continue;
		}
		isDescending = isSorted(arr, 10); //calling on the function to check if the user gave descending numbers only, no doubles included
	
		if (isDescending == false) //if false then print error, so the user can input more values
			cout << "ERROR\n";
	} while (isDescending == false || isPositive == false); //as long as 1 of these was false need to go through the loop again

}

bool isSorted(const int arr2[], int size) {
	for (int i = 0; i < size - 1; i++) { //each iteration checks if the current element is less than the next element
		if (arr2[i + 1] == 0) { //once the next element is zero we know the user inputs have stopped and don't need to compare anymore
			return true;
		}
		if (arr2[i] <= arr2[i + 1])
			return false;	//if there is one case where condition is true, return false and leave the function
	}
}

void mergeArrays(int arr1[], int arr2[], int arr3[], int arrMerge[], int size1, int sizeMerge) {
	int i = 0, j = 0, k = 0, x = 0; //i is for arr1, j arr2, k arr3, and x arrMerge

	while (i < 10 && j < 10 && k < 10) { //first while loop for when all 3 array still have elements left
		if (arr1[i] >= arr2[j] && arr1[i] >= arr3[k]) { //cases when current element in arr1 is bigger than current elements in arr2 and arr3
			arrMerge[x] = arr1[i++]; //put element from arr1 into arrMerge and increment arr1 to next element
		}
		else if (arr2[j] >= arr1[i] && arr2[j] >= arr3[k]) { //cases when current element in arr2 is bigger than current elements in arr1 and arr3
			arrMerge[x] = arr2[j++]; //put element from arr2 into arrMerge and increment arr2 to next element
		}
		else if (arr3[k] >= arr1[i] && arr3[k] >= arr2[j]) { //cases when current element in arr3 is bigger than current elements in arr2 and arr1
			arrMerge[x] = arr3[k++]; //put element from arr3 into arrMerge and increment arr3 to next element
		}
		
		else { //have this case for all the empty zeros in the arrays
			break;
		}
		x++; //increment x each time so it moves to the next element in the merge array
	}
	if (i < 10 && j < 10) { //for when all of arr3 was used up and left with arr1 and arr2
		while (i < 10 && j < 10) { //as long as both arrays aren't done go here
			if (arr1[i] > arr2[j]) { //if current element in arr1 is bigger than current element in arr2
				arrMerge[x] = arr1[i++]; //put element from arr1 into arrMerge and increment arr1 to next element
			}
			else { //otherwise arr2 is bigger than arr1 and put element from arr2 into arrMerge
				arrMerge[x] = arr2[j++];
			}
			x++; //increment x each time so it moves to the next element in the merge array
		}
		while (i < 10) { //only arr1 has elements left and fill up arrMerge with leftover elements
			arrMerge[x++] = arr1[i++];
		}
		while (j < 10) { //only arr2 has elements left and fill up arrMerge with leftover elements
			arrMerge[x++] = arr2[j++];
		}
	}

	if (j < 10 && k < 10) { //for when all of arr1 was used up and left with arr3 and arr2
		while (j < 10 && k < 10) { //as long as both arrays aren't done go here
			if (arr2[j] > arr3[k]) { //if current element in arr2 is bigger than current element in arr3
				arrMerge[x] = arr2[j++]; //put element from arr2 into arrMerge and increment arr2 to next element
			}
			else {
				arrMerge[x] = arr3[k++]; //otherwise arr3 is bigger than arr2 and put element from arr3 into arrMerge
			}
			x++; //increment x each time so it moves to the next element in the merge array
		}
		while (j < 10) { //only arr2 has elements left and fill up arrMerge with leftover elements
			arrMerge[x++] = arr2[j++];
		}
		while (k < 10) { //only arr3 has elements left and fill up arrMerge with leftover elements
			arrMerge[x++] = arr3[k++];
		}
	}

	if (i < 10 && k < 10) { //for when all of arr2 was used up and left with arr1 and arr3
		while (i < 10 && k < 10) { //as long as both arrays aren't done go here
			if (arr1[i] > arr3[k]) { //if current element in arr1 is bigger than current element in arr3
				arrMerge[x] = arr1[i++]; //put element from arr1 into arrMerge and increment arr1 to next element
			}
			else { //otherwise arr3 is bigger than arr1 and put element from arr3 into arrMerge
				arrMerge[x] = arr3[k++];
			}
			x++; //increment x each time so it moves to the next element in the merge array
		}
		while (i < 10) { //only arr1 has elements left and fill up arrMerge with leftover elements
			arrMerge[x++] = arr1[i++];
		}
		while (k < 10) { //only arr3 has elements left and fill up arrMerge with leftover elements
			arrMerge[x++] = arr3[k++];
		}
	}
}
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] != 0) { //print all non-zero values
			cout << arr[i] << " ";
		}
	}
}
/*enter values for the first vector:
5 4 0
enter values for the second vector:
5 2 1 0
enter values for the third vector:
4 2 1 0
merged vector is:
5 5 4 4 2 2 1 1
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework7.2\Debug\Homework7.2.exe (process 19448) exited with code 0.
Press any key to close this window . . .
*/
