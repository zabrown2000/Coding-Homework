/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 6 Question 5

this program will take in values for 2 arrays and will print
out the values of the 1st array that are not in the 2nd 
array, if all are in 2nd array it will print empty*/

#include <iostream>
using namespace std;

void fillArray(int arr[], const int size);
//function to fill array based on user input and checks for valid input
//takes in 2 parameters, the array and its size
//doesn't return a value because it fills the array directly

bool checkDiff(int element1, int arr2[], int size);
//function to check if a single integer is found in an array-will be used in fillDiff function
//takes in 3 parameters-the element, the array being checked, and the array size
//returns a boolean value if the element is in the array or not

void fillDiff(int arr1[], int arr2[], int arrDiff[], int size);
//function to fill in the difference array by comparing the values of set1 to set2
//takes in all 3 arrays delcared in main and the size (same for all 3)
//returns no value since it changes the array directly

void printDiff(int arrDiff[], int size);
//function to print out the elements of the difference array, or empty if is all 0s
//takes in 2 parameters, the difference array and the size
//returns no value since it changes the array directly and prints directly from the array

int main() {
	
	int set1[6], set2[6], difference[6] = { 0 };

	cout << "enter first 6 numbers:\n";
	fillArray(set1, 6); //filling set1 array with only positive values

	cout << "enter next 6 numbers:\n";
	fillArray(set2, 6); //filling set2 array with only positive values

	fillDiff(set1, set2, difference, 6); //filling the difference array by comparing set1 to set2

	cout << "set difference is:\n";
	printDiff(difference, 6); //calling the function to print the elements of the set difference (or empty)

	return 0;
}


void fillArray(int arr[], const int size) {
	bool isError = false; //will be used to control the loop below
	int input; //so we can compare the input before putting it in the array

	do { //using do-while so the statements will run at least once
		for (int i = 0; i < size; i++) {
			cin >> input;
			if (input > 0) { //if the inputs are positive then fill the array element
				arr[i] = input;
			}
			else { //otherwise make an error an break out of the for loop
				isError = true;
				cout << "ERROR\n";
				break;
			}
		}
	} while (isError == true); //will only go again when isError is true, which only happens when the input isn't in range
}

bool checkDiff(int element1, int arr2[], int size) {
	
	bool inSet = false; 

	for (int i = 0; i < size; i++) { //checking element sent to function against the array elements
		if (element1 == arr2[i]) { //once there is a case where it's in the set, then we can leave the loop, no need to check more
			inSet = true; //so the function can return the value
			break;
		}
	}
	return inSet; //either true from loop, or the loop ran through without stopping and value stayed false
}

void fillDiff(int arr1[], int arr2[], int arrDiff[], int size) {

	bool inSet2;

	for (int i = 0; i < size; i++) {
		inSet2 = checkDiff(arr1[i], arr2, size); //for each element in arr1, sending it to checkDiff to check if it's in arr2

		if (inSet2 == true) { //if it is in set2 then set the corresponding element in arrDiff to 0 (won't print this element)
			arrDiff[i] = 0;
		}
		else { //if it's not then set the corresponding element to the element in arr1
			arrDiff[i] = arr1[i];
		}
	}
}

void printDiff(int arrDiff[], int size) {

	bool isEmpty = true; //need to initialize here because will cause problems in if statement

	for (int i = 0; i < size; i++) { //checking all the elements in arrDiff to see if all the elements are 0 
		if (arrDiff[i] == 0) { //the default is true, so each time an element is =0 then it stays true
			isEmpty = true;
		}
		else { //once there is a case of a non-0 element then it will leave the loop and move on to the if statement
			isEmpty = false;
			break;
		}
	}
	if (isEmpty == true) { //if it's true that all the elements are 0 (all elements in set1 were in set2)
		cout << "empty\n"; //print empty
	}
	else { //otherwise print all the non-0 elements
		for (int j = 0; j < size; j++) {
			if (arrDiff[j] != 0) { //only the non-0 elements will be printed (if an element from set1 was in set2 a 0 was added to difference)
				cout << arrDiff[j] << " "; //printing with a space after it

			}

		}
	}
}

/*enter first 6 numbers:
10 9 7 5 3 1
enter next 6 numbers:
6 5 4 3 2 1
set difference is:
10 9 7
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.5\Debug\Homework6.5.exe (process 29904) exited with code 0.
Press any key to close this window . . .
*/