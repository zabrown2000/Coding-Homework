/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 7 Question 4
This program will take in a matrix of 10 5-letter words and
will use the bubble sort method to sort them in lexicographical (dictionary) order.*/

#include <iostream>
using namespace std;

const int words = 10;
const int letters = 5;

void fillMatrix(char matrix[][letters], int rows);
//function to fill a matrix based on values inputed by user
//takes in 2 parameters, a matrix and its row size
//does not return a value since it changes the matrix directly

void bubbleSort(char words[][letters], int rows);
//function to sort a matrix containing char values (words) in alphabetical order
//takes in 2 parameters, a matrix and its row size
//does not return a value since it changes the matrix directly

bool compareWords(char word1[], char word2[], int wordLength);
//function that will take in 2 words (char arrays) at a time and determine which one comes first alphabetically
//takes in 3 parameters, 2 char arrays and their length
//returns a boolean value if word1 is less than or greater than word2, or if they are the same

void swapWords(char word1[], char word2[], int wordLength);
//function to swap the values of whole arrays
//takes in 3 parameters, 2 arrays and their length
//does not return a value since it changes the arrays directly

void printMatrix(const char mat[][letters], int rows);
//function to print the contents of a char matrix
//takes in 2 parameters, the matrix and its row size
//does not return a value since it prints out the matrix

int main() {
	
	char wordList[words][letters];

	cout << "enter 10 words:\n";
	fillMatrix(wordList, words); //send matrix to be filled from user input

	bubbleSort(wordList, words); //send matrix to be sorted

	cout << "after sorting:\n";
	printMatrix(wordList, words); //sending the newly sorted matrix to be printed

	return 0;
}

void fillMatrix(char matrix[][letters], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < letters; j++) {
			cin >> matrix[i][j];
		}
	}
}

void bubbleSort(char words[][letters], int rows) {
	int sortIndex, i;
	bool isFirst;

	for (sortIndex = (rows - 1); sortIndex > 0; sortIndex--) { //starting with all rows, but after each iteration the last word will be in place so we can decrease the length that we are checking
		for (i = 0; i < sortIndex; i++) { //here we will check each word
			isFirst = compareWords(words[i], words[i + 1], letters); //sending each word (rows from the matrix) and the word after it to check if they are in the right order
			if (isFirst == false) {
				swapWords(words[i + 1], words[i], letters); //when the words are not in the right order we need to sway them
			}
		}
	}
}

bool compareWords(char word1[], char word2[], int wordLength) {
	
	for (int i = 0; i < wordLength; i++) { //will compare each letter of the words to see which comes first
		if (word1[i] < word2[i]) { //word1 comes before word2
			return true;
		}
		else if (word1[i] > word2[i]) { //doing else-if instead of else because we don't want to include cases where the letters are the same return false
			return false;
		}
	}
	return true; //this would mean every letter compared was the same so the whole word was the same, and in this case we return true
}

void swapWords(char word1[], char word2[], int wordLength) {

	for (int i = 0; i < wordLength; i++) {
		char temp = word1[i];
		word1[i] = word2[i];
		word2[i] = temp;
	}
}

void printMatrix(const char mat[][letters], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < letters; j++) {
			cout << mat[i][j]; //printing each row with no spaces because they are words
		}
		cout << '\t'; //spaces in between rows
	}
}
/*
enter 10 words:
house apple teach array books point float apply begin teach
after sorting:
apple   apply   array   begin   books   float   house   point   teach   teach
C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework7.4\Debug\Homework7.4.exe (process 11212) exited with code 0.
Press any key to close this window . . .
*/
