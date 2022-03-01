/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 6 Question 2

this program will take in inputs from the user that will determine the size and 
contents of 2 arrays and then through checking the arrays in a function the 
program will output the amount times the entire vector 2 is found in vector 1*/
#include <iostream>
using namespace std;

void checkAmount(int& sizeInput, int limit);
//function will check that the size the user inputted is within the set limit
//takes in 2 parameters, 1 call-by-reference and 1 int
//does not return a value because it is just checking that the input was correct and will fix it within the function

void fillArray(int arr[], const int size);
//function to fill an array based on user input
//takes in 2 parameters, array and array size
//doesn't return a value--changes the array directly

int checkElements(int arr1[], const int size1, int arr2[], const int size2);
//function to find out how many times the elements in arr2 are in arr1 if at all
//takes in 4 parameters, 2 arrays and 2 array sizes
//returns int value with the amount of times arr2 is in arr1

int main (){
	int size1, size2, twoInOne;
	
	cout << "enter size of first array:\n";
	cin >> size1;
	checkAmount(size1, 500); //checking that the size entered by the user is within 500

	int vector1[500]; //set it to 500 but will only fill it size1 times
	cout << "enter first array values:\n";
	fillArray(vector1, size1); //filling array 1 with size1 elements

	cout << "enter size of second array:\n";
	cin >> size2;
	checkAmount(size2, 100); //checking that the size entered by the user is within 100

	int vector2[100]; //set it to 100 but will only fill it size2 times
	cout << "enter second array values:\n";
	fillArray(vector2, size2); //filling array 2 with size2 elements

	twoInOne = checkElements(vector1, size1, vector2, size2);

	cout << "result: " << twoInOne << " times\n";
	
	return 0;
}


void checkAmount(int& sizeInput, int limit) {
	while (sizeInput >= limit) {
		cout << "ERROR\n";
		cin >> sizeInput;
	}
}

void fillArray(int arr[], const int size) {
	for (int i = 0; i < size; i++)
		cin >> arr[i]; //filling the array to the amount of spaces declared by the user
}

int checkElements(int arr1[], const int size1, int arr2[], const int size2) {
	
	int counter = 0, indexCheck = 0; 
	bool inArr1 = false; 

	for (int i = 0; i < (size1 - size2) + 1; i++) { //will check through arr1 the amount of times arr2 can be in it (if size1 = 200, size2 = 50, will check through index 150+1-because starting from 0)

		for (int j = 0; j < size2; j++) { //now we'll check if each element in arr2 is in arr1, in the correct order
			if (arr1[i + j] != arr2[j]) { //checking i+j because we want the elements from arr2 in arr1 to be one after the other
				inArr1 = false; //if at this index of arr1 the elements of arr2 aren't found, leave j-loop, will go back to i-loop
				break;
			}
			else {
				inArr1 = true;
			}
		}
		if (inArr1 == true) { //if we have a case of arr2 being in arr1 in order, then add to counter so we know how many times it repeats
			counter++;
		}
	}
	return counter;
}
/*enter size of first array:
18
enter first array values:
6 5 4 3 2 1 6 5 4 3 2 1 6 5 4 3 2 1
enter size of second array:
4
enter second array values:
5 4 3 2
result: 3 times

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.2\Debug\Homework6.2.exe (process 13416) exited with code 0.
Press any key to close this window . . .
*/
