/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 7 Question 3
This program will take in a 10x10 matrix from the user and will divide 
it into 2 triangles and sort each triangle in non-descending order*/

#include <iostream>
using namespace std;

void fillMatrix(int mat[][10], int size);
//function to fill a matrix based on user inputs
//takes in 2 parameters, a matrix and it's row size
//does not return a value because it changes the matrix directly

void printMatrix(const int mat[][10], int size);
//function to take in a matrix and then print it
//takes in 2 parameters, a matrix and it's row size
//does not return a value because it is just printing out the matrix and not making any changes

void insertionSort(int arr[], int size);
//funciton to sort an array, using the insertion sort method/algorithm
//takes in 2 parameters, an array and its size
//does not return a value because it changes the array directly

int main() {
	const int matSize = 10;
	const int triSize = 45; 
	int matrix[matSize][matSize], leftTri[triSize], rightTri[triSize], triIndex;

	cout << "enter the values:\n";
	fillMatrix(matrix, matSize); //sending matrix to be filled

	cout << "before sorted:\n";
	printMatrix(matrix, matSize); //sending matrix to be printed

	triIndex = 0; //this will be for moving the bottom left side of the matrix to a regular array to be sorted
	for (int i = 1; i < matSize; i++) { //since we are ignoring the diagnal line we are starting at row index 1 instead of 0
		for (int j = 0; j < i; j++) { //how far into each column we go corresponds to the row number
			leftTri[triIndex] = matrix[i][j];
			triIndex++; 
		}
	}

	triIndex = 0; //this will be for moving the top right side of the matrix to a regular array to be sorted
	for (int i = 0; i < (matSize) - 1; i++) { //since we are ignoring the diagnal, we go up until the last row
		for (int j = (i + 1); j < matSize; j++) { //where we start in each column corresponds 1 + the row number
			rightTri[triIndex] = matrix[i][j];
			triIndex++;
		}
	}

	insertionSort(leftTri, triSize); //sending the left array to be sorted
	insertionSort(rightTri, triSize); //sending the right array to be sorted

	triIndex = 0; //now copying the left sorted array back to the bottom left side of the matrix
	for (int i = 1; i < matSize; i++) {
		for (int j = 0; j < i; j++) {
			matrix[i][j] = leftTri[triIndex]; //now putting the array elements back in their proper places
			triIndex++;
		}
	}

	triIndex = 0; //now copying the right sorted array back to the top right side of the matrix
	for (int i = 0; i < (matSize - 1); i++) {
		for (int j = (i + 1); j < matSize; j++) {
			matrix[i][j] = rightTri[triIndex]; //now putting the array elements back in their proper places
			triIndex++;
		}
	}
	cout << "sorted matrix:\n";
	printMatrix(matrix, matSize); //sending newly sorted matrix to be printed
	
	return 0;
}

void fillMatrix(int mat[][10], int size) {
	int input; //so can compare input from ther user
	bool isError; 
	do {
		isError = false; //set to false each time so it can reset if the loop needs to run again
		for (int i = 0; i < size; i++) { //need the double loops to account for both dimensions of the matrix
			for (int j = 0; j < size; j++) {
				cin >> input;
				if (input > 0) { //if the inputs are positive then fill the array
					mat[i][j] = input;
				}
				else { //otherwise, it's an invalid input and break from the inner loop
					isError = true;
					cout << "ERROR\n";
					break;
				}
			}
			if (isError == true) //if left the inner loop because of an error in the input, leave the outer loop too
				break;
		}
	} while (isError == true); //will only go again when isError is true, which only happens when the input isn't positive
}

void printMatrix(const int mat[][10], int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << mat[i][j] << '\t'; //want tab and not just a space so it stays even with the double digit numbers
		}
		cout << endl; //so each row of the matrix is printed on a new line
	}
}

void insertionSort(int arr[], int size) {
	int sortIndex, i;

	for (sortIndex = 1; sortIndex < size; sortIndex++) { //this loop controls which 2 elements are currently being compared (that's why start at 1 and not 0)
		int temp = arr[sortIndex]; //this element is what will be compared to all elements below it
		for (i = sortIndex; i > 0 && temp < arr[i - 1]; i--) {
			arr[i] = arr[i - 1]; //if the current element (sortIndex) is less than the element before it (i-1), then switch them
		}
		arr[i] = temp; //putting the element we were sorting back into the array
	}
}
/*
enter the values:
1 11 21 31 41 51 61 71 81 91
2 12 22 32 42 52 62 72 82 92
3 13 23 33 43 53 63 73 83 93
4 14 24 34 44 54 64 74 84 94
5 15 25 35 45 55 65 75 85 95
6 16 26 36 46 56 66 76 86 96
7 17 27 37 47 57 67 77 87 97
8 18 28 38 48 58 68 78 88 98
9 19 29 39 49 59 69 79 89 99
10 20 30 40 50 60 70 80 90 100
before sorted:
1       11      21      31      41      51      61      71      81      91
2       12      22      32      42      52      62      72      82      92
3       13      23      33      43      53      63      73      83      93
4       14      24      34      44      54      64      74      84      94
5       15      25      35      45      55      65      75      85      95
6       16      26      36      46      56      66      76      86      96
7       17      27      37      47      57      67      77      87      97
8       18      28      38      48      58      68      78      88      98
9       19      29      39      49      59      69      79      89      99
10      20      30      40      50      60      70      80      90      100
sorted matrix:
1       11      21      22      31      32      33      41      42      43
2       12      44      51      52      53      54      55      61      62
3       4       23      63      64      65      66      71      72      73
5       6       7       34      74      75      76      77      81      82
8       9       10      13      45      83      84      85      86      87
14      15      16      17      18      56      88      91      92      93
19      20      24      25      26      27      67      94      95      96
28      29      30      35      36      37      38      78      97      98
39      40      46      47      48      49      50      57      89      99
58      59      60      68      69      70      79      80      90      100

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework7.3\Debug\Homework7.3.exe (process 7104) exited with code 0.
Press any key to close this window . . .
*/
