/*Zahava Brown
* TZ: 346287956
* Intro to Computer Science-Joyce Vogel
* Lab 10 Question 2
* This program will take in a sentence (single string of words) from the user and then 
* print out the string with the letters of each word reversed
*/

#include <cstring>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void reverse(char*& words);
//function to reverse the letters of each word in a given sentence
//takes in 1 parameter, a pointer to an array of characters
//returns no value as it affects the array directly

void reverseLetters(char*& word, int left, int right);
//function to swap the letters of a word taken from a string
//takes in 3 parameters, a pointer to an array of characters, and the 2 boundries of where to swap the letters
//returns no value as it affects the array directly

int main() {

	char sentence[80];
	char* pSentence = sentence;
	cout << "enter a string: " << endl;
	cin.getline(sentence, 80); //reading in input from user until limit reached or user pressed enter

	reverse(pSentence); //sending pointer to string sentence to have all words reversed

	cout << "After reverse: " << sentence << endl;

	return 0;
}

void reverse(char*& words) {
	int wordLength, j = 0, k = 0;

	wordLength = strlen(words) + 1; //getting the length of the letters in words and adding 1 for the null at the end
	char* tempString = new char[wordLength]; //creating a new char array so can add a space after the last letter

	for (int i = 0; i < wordLength - 1; i++) {
		tempString[i] = words[i]; //copying over the characters from given array to new array
	}
	tempString[wordLength - 1] = ' '; //adding a space at the index before the null character

	for (; j < wordLength; j++) { 
		if (tempString[j] == ' ') {
			reverseLetters(tempString, k, (j - 1));
			
			while (j + 1 == ' ') { //moving j over until the spaces are over so we can start searching for the next word
				j++;
			}
			k = j + 1; //setting the k (left) boundry to be the spot after j stopped, the space
		}
	}
	for (int m = 0; m < wordLength - 1; m++) {
		words[m] = tempString[m]; //copying the newly reverse string back to words
	}
	delete[] tempString;
}
void reverseLetters(char*& word, int left, int right) {

	while (left < right) { //once boundries cross each other will leave loop
		char temp = word[left]; //using swap method to reverse the letters
		word[left] = word[right];
		word[right] = temp;
		
		left++; //bringing boundries closer together
		right--;
	}
}
/*enter a string:
This is  a silly88 sentence
After reverse: sihT si  a 88yllis ecnetnes

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework10.2\Debug\Homework10.2.exe (process 28972) exited with code 0.
Press any key to close this window . . .
*/