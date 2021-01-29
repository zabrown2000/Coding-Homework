/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 8 Question 1
This program will take in 2 arrays and determine if the second is is the first, 
and what its gap size is (space between each number). This will be done using pointers*/

#include <iostream>
using namespace std;

void fillArray(int* arrPtr, const int size);
//function to fill an array using pointers
//takes in 2 parameters, pointer to an array and the array size
//does not return a value since it affects the array directly

int gapCheck(int* bigArray, int* smallArray, const int sizeB, const int sizeS);
//function to check the gap size of 1 array in another using pointers
//takes in 4 parameters, 2 pointers to the arrays and their sizes
//returns an int value of the gap size

bool checkContained(int* bigArray, int* smallArray, const int sizeB, const int sizeS);
//function to check if one array is contained in the other using pointers
//takes in 4 parameters, 2 pointers to the arrays and their sizes
//returns a boolean value to correspond if the small array is in the big


int main() {
	int big[80], small[80], bigSize, smallSize, gapSize;
	int* pBig = big, * pSmall = small;

	cout << "Enter the size of big:\n";
	cin >> bigSize;

	while (bigSize <= 0 || bigSize > 80) { //checking to make sure the inputted size is valid
		cout << "ERROR\n";
		cin >> bigSize;
	}
	cout << "Enter " << bigSize << " numbers:" << endl;
	fillArray(pBig, bigSize); //sending pointer to array to function with the array size

	cout << "Enter the size of small:\n";
	cin >> smallSize;

	while (smallSize <= 0 || smallSize > 80) { //checking to make sure the inputted size is valid
		cout << "ERROR\n";
		cin >> smallSize;
	}
	cout << "Enter " << smallSize << " numbers:" << endl;
	fillArray(pSmall, smallSize); //sending pointer to array to function with the array size

	gapSize = gapCheck(pBig, pSmall, bigSize, smallSize);

	cout << "Size of jump:\n";

	if (gapCheck >= 0) {
		cout << gapSize << endl;
	}
	else { //this means either small was not contained in big or elements of small were not evenly spaced in big
		cout << "-1" << endl;
	}
	
	return 0;
}

void fillArray(int* arrPtr, const int size) {
	for (int* p = arrPtr; p < (arrPtr + size); p++) {
		cin >> *p; //filling the array by pointer
	}
}

int gapCheck(int* bigArray, int* smallArray, const int sizeB, const int sizeS) {
	bool isContained;
	int currentDist;

	isContained = checkContained(bigArray, smallArray, sizeB, sizeS); //before going further, sending the arrays to the function to check if small is even contained in big 

	if (isContained == false) {
		return -1; //will leave function and not continue if small is not contained in big
	}
	for (int* p = smallArray; p < (smallArray + sizeS); p++) { //this loop is to go through the elements of small to compare to big and get gap size
		if (sizeS == 1) {
			return 0; //no need to check in bigArray because already know it's contained from before and no other elements to check
		}
		for (int* q = bigArray; q < (bigArray + sizeB); q++) { //this loop will get size between current element in small and the next one
			
			if (*q == *p) {
				for (int* r = (q + 1); r < (bigArray + sizeB); r++) { //this loop will now pick up where j-loop left off and search for next small element
					
					if (*r == *(p + 1)) { //looking for the next element in small inside big
						currentDist = (r - 1) - q; //jump size is the amount of numbers in between q and r so need to do r-1
						if (sizeS == 2) {
							return currentDist; //if there are only 2 numbers then checking p + 2 will go out of scope, so this is the distance
						}
						if (*(r + (currentDist + 1)) == *(p + 2)) { //checking if the element after r + gap is = 3rd small element
							return currentDist; //not done yet, need to check minimum that it's minimum
						}
					}
				}
			}
		}
	}
	return -1; //default setting, if the numbers are contained but aren't evenly spaced, will have gotten to this point and will return -1
}

bool checkContained(int* bigArray, int* smallArray, const int sizeB, const int sizeS) {
	int* checkIndex, * p, * q;

	for (p = smallArray; p < (smallArray + sizeS); p++) { //outer loop to go through each element in smallArray
		checkIndex = NULL; //will reset before each iteration of the inner loop, used as a flag

		for (q = bigArray; q < (bigArray + sizeB); q++) { //now checking each element of small against every element in big
			if (*p == *q) { 
				checkIndex = q; //once find the element in big, set the index to the address and break from the loop
				break;
			}
		}
		if (checkIndex != NULL) { //if current element from small was found in big 
			bigArray = checkIndex; //set bigArray to the address where found so it will search for remaining elements from that point
		}
		else { //otherwise, if a case where 1 element isn't found, return false and leave the function
			return false;
		}
	}
	return true; //this means got through whole outer loop with no false cases, so all elements in small are in big
}

/*Enter the size of big:
8
Enter 8 numbers:
1 2 3 4 5 6 7 8
Enter the size of small:
3
Enter 3 numbers:
2 5 8
Size of jump:
2

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework8.1\Debug\Homework8.1.exe (process 6228) exited with code 0.
Press any key to close this window . . .
*/