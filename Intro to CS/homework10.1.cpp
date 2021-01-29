/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 10 Question 1
Thiis program will take in a word from the user and through the 
azby encryption method, it will encrypt the word and print it*/

#include <cstring>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;

void crypto (char* word);
//function to replace the lowercase letters of a word with its azby counterpart
//takes in 1 parameter, the word to be encrypted
//does not return a value as it changes the char array directly

int main() {

	char string[80];
	cout << "Enter a string:\n";
	cin.getline(string, 80); //reading in a string of up to 80 characters, NULL will be placed at end automatically

	crypto(string); //sending word to get encrypted

	cout << "After crypto:\n" << string << endl;

	return 0;
}

void crypto(char* word) {

	char atoz[] = "abcdefghijklmnopqrstuvwxyz"; //made char array with all the lowercase letters, size will be 27 for null at the end
	int letterIndex;
	char* address, * alphaIndex = atoz, * p = word;

	while (*p) { //loop will encrypt the word until it gets to the null at the end
		
		address = strchr(atoz, *p); //checking to see what letter we are up to in word to see if it needs to be encrypted (a lowercase letter)

		if (address) { //if the function returned an address for the letter from word in atoz
			
			letterIndex = address - alphaIndex; //getting the index of the letter found in atoz from word
			*p = *(alphaIndex + 25 - letterIndex); //setting the letter that p points to in word to its azby counterpart
		
			p++; //move to next letter
		}
		else {
			p++; //current character is not a lowercase letter so move to the next one
		}
	}
}
/*
Enter a string:
bamba
After crypto:
yznyz

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework10.1\Debug\Homework10.1.exe (process 26976) exited with code 0.
Press any key to close this window . . .
*/