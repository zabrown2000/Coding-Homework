//in future, make functions nested if more than 20 lines

/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 10 Question 3
This program will create a digital dictionary of words in lexicographical order that 
the user can add to, delete from, search in, and print.*/

#include <iostream>
#include <string>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

void newStr(char**& dictionary, int& size, char* newWord); 
//function to add a word to a list of existing words (2d array) in alphabetical order
//takes in 3 parameters, a pointer to the dictionary as CBR, the current size of the dictionary as CBR, and the word to be added
//returns no value as it affects the 2d array directly

void selectionSort(char** words);
//function to sort a list of items, using the selection sort method
//takes in 1 parameter, the 2d array of words
//returns no value as it affects the 2d array directly

void swapWords(char*& word1, char*& word2);
//function to swap the contents of 2 char arrays using pointers
//takes in 2 parameters, pointers to char arrays (strings) as CBR
//returns no value as it affects the arrays directly

void printAll(char** dictionary, int size);
//function to print the contents of a 2d char arry
//takes in 2 parameters, pointer to the 2d array and its size
//returns no value as it is just printing

void delStr(char**& dictionary, int& size, char* delWord);
//function to delete a word from an existing list of words (2d array) 
//takes in 3 parameters, a pointer to the dictionary as CBR, the current size of the dictionary as CBR, and the word to be deleted
//returns no value as it affects the 2d array directly

char** searchStr(char** dictionary, int size, char* wordSearch);
//function that searches for a word in an existing list of words (2d array)
//takes in 3 parameters, a pointer to the dictionary as CBR, the size, and the word to be searched
//returns the address of the word in the list if it's found, or NULL if it doesn't exist

void printChar(char** dictionary, int size, char letter);
//function to print all the words in a dictionary that start with a given letter
//takes in 3 parameters, a pointer to the existing list of words (2d array)
//does not return a value as it is just printing

int main() {

	char** lexicon = NULL;
	char* wordInput, **wordAddress, * temp, letter;
	int wordSize = 0, userChoice, length;

	cout << "Enter 0-5:\n";
	cin >> userChoice;

	while (userChoice != 5) { //code will only continue while the input is not a 5-->ending the program

		if ((userChoice > 4) || (userChoice < 0)) { //checking that user entered a valid choice option
			cout << "ERROR\n";
			cin >> userChoice;
			continue; //once get new input move on to next loop iteration
		}
		else if (userChoice == 0){ //instance when user enters a 0, will add a word to the dictionary
			temp = new char[80]; //creating new string to store new word from the user
			cout << "Enter the word:" << endl;
			cin.ignore(); //looked it up, I need this because getline reads in the hanging \n and ends with that, not allowing user to enter a word
			cin.getline(temp, 80); //storing the input

			length = strlen(temp) + 1; //calling function strlen to get the length of the word and adding 1 for the null space at the end
			wordInput = new char[length]; //now creating a string of the actual size we need to store the input from the usesr
			strncpy(wordInput, temp, length); //calling strncpy to only copy the length of the word to wordInput, which will be the correct size
			delete[] temp; //can now delete what temp points to becaues we copied the contents to wordInput

			newStr(lexicon, wordSize, wordInput); //calling newStr to add the new word to the dictionary (or it won't if it exists)
			printAll(lexicon, wordSize); //sending all contents of dictionary to be printed

			delete[] wordInput; //since this word was added (or not) to the dictionary, we don't need this placeholder anymore
		}
		else if (userChoice == 1) { //instance when user enters a 1, will delete a word from the dictionary
			temp = new char[80]; //creating new string to store word from the user
			cout << "Enter the word to delete:\n"; 
			cin.ignore(); //looked it up, I need this because getline reads in the hanging \n and ends with that, not allowing user to enter a word
			cin.getline(temp, 80); //storing the input

			length = strlen(temp) + 1; //calling function strlen to get the length of the word and adding 1 for the null space at the end
			wordInput = new char[length]; //now creating a string of the actual size we need to store the input from the usesr
			strncpy(wordInput, temp, length); //calling strncpy to only copy the length of the word to wordInput, which will be the correct size
			delete[] temp; //can now delete what temp points to becaues we copied the contents to wordInput

			delStr(lexicon, wordSize, wordInput); //calling delStr to delete a word the dictionary (or it won't if it doesn't exist)
			printAll(lexicon, wordSize); //sending all contents of dictionary to be printed

			delete[] wordInput; //since this word was deleted (or not) from the dictionary, we don't need this placeholder anymore
		}
		else if (userChoice == 2) { //instance when user enters a 2, will search for a word in the dictionary
			temp = new char[80]; //creating new string to store word from the user
			cout << "Enter the word to search for:\n";
			cin.ignore(); //looked it up, I need this because getline reads in the hanging \n and ends with that, not allowing user to enter a word
			cin.getline(temp, 80); //storing the input

			length = strlen(temp) + 1; //calling function strlen to get the length of the word and adding 1 for the null space at the end
			wordInput = new char[length]; //now creating a string of the actual size we need to store the input from the usesr
			strncpy(wordInput, temp, length); //calling strncpy to only copy the length of the word to wordInput, which will be the correct size
			delete[] temp; //can now delete what temp points to becaues we copied the contents to wordInput

			wordAddress = searchStr(lexicon, wordSize, wordInput); //sending word to function to find it in the word list

			if (wordAddress == NULL) { //didn't return an address, so wasn't found
				cout << "Not Found\n";
			}
			else { //function returned an address for the word in the list, so it was found
				cout << "Found\n";
			}
			delete[] wordInput; //since this word was just used to search in the dictionary, we don't need this placeholder anymore
		}
		else if (userChoice == 3) { //instance when user enters a 3, will search for all words in the dictionary starting with a specific letter
			cout << "Enter the char:\n";
			cin >> letter;

			printChar(lexicon, wordSize, letter); //calling function to print all the words in the list that begin with the given letter
		}
		else if (userChoice == 4) { //instance when user enters a 3, will print all the words in the list

			printAll(lexicon, wordSize); //calling function to print all the contents
		}

		cout << "Enter 0-5:\n"; //asking user for next action
		cin >> userChoice;
	}

	for (int i = 0; i < wordSize; i++) { //deleting each word in the dictionary
		delete[] lexicon[i]; 
	}
	delete[] lexicon; //deleting the dictionary itself
	return 0;
}


void newStr(char**& dictionary, int& size, char* newWord) {
	int wordCmp, wordLength;
	wordLength = strlen(newWord) + 1; //calling strlen to get the size of the word to be added

	if (size == 0) { //dictionary currently empty
		
		dictionary = new char* [2]; //need 2 rows because adding a null to the last spot
		dictionary[0] = new char[wordLength]; //creating new array in dictionary to hold the new word
		strcpy(dictionary[0], newWord); //copying over the contents of the new word to the dictionary, and the sizes are the same
		dictionary[1] = NULL;

		size += 2; //increaseing size by 2 because added a word and a null at the end
	}
	else if (size == 2) { //already 1 word in the dictionary
		char** tempList = new char* [3]; //creating temporary list so we can make sure the words are in the right order before putting them in dictionary
		wordCmp = strcmp(dictionary[0], newWord); //calling strcmp to check which word comes first alphabetically, if they are the same, nothing will happen
		
		if (wordCmp < 0) { //first word comes first alphabetically (new word is second)

			tempList[0] = new char[(strlen(dictionary[0])) + 1]; //making space in templist for the first word, of exact same length
			strcpy(tempList[0], dictionary[0]); //copying original word into templist

			tempList[1] = new char[wordLength]; //making space in templist after the original word for the new word, of exact same length
			strcpy(tempList[1], newWord); //copying new word into space just created in above line

			tempList[2] = NULL; //setting last spot in dictionary to NULL

			for (int i = 0; i < 2; i++) {
				delete[] dictionary[i]; //deleting the words in original dictionary
			}
			delete[] dictionary; //deleting what dictionary points to
			dictionary = tempList; //dictionary will now point to tempList that contains the new word
			size++; //increasing size by 1
		}
		else if (wordCmp > 0) { //first word comes second alphabetically (new word is first), will need to swap
			
			tempList[0] = new char[wordLength]; //making first spot in tempList to fit the new word, of exact same length
			strcpy(tempList[0], newWord); //copying the new word into templist

			tempList[1] = new char[((strlen(dictionary[0]) + 1))]; //now making the second spot in the list for the original word in the dictionary
			strcpy(tempList[1], dictionary[0]); //copying the original word into the spot the was created in the above line

			tempList[2] = NULL; //setting last spot in dictionary to NULL

			for (int i = 0; i < 2; i++) {
				delete[] dictionary[i]; //deleting the words in original dictionary
			}
			delete[] dictionary; //deleting what dictionary points to
			dictionary = tempList; //dictionary will now point to tempList that contains the new word
			size++; //increasing size by 1
		}
	}
	else { //there is more than 1 word in the dictionary already (size is >3)
		bool exists = false; //flag to check if word already exists in dictionary

		for (int i = 0; i < size - 1; i++) { //loop to check if the new word is same as any existing words (size-1 because last place is a null)
			if (!strcmp(newWord, dictionary[i])) { //if the words are the same, it will return 0 which is false, so saying if returns 0 make it true
				exists = true;
				break; //once found the word, no need to continue
			}
		}
		if (exists == false) { //this means the word does not exist in the dictionary
			char** tempList = new char* [size + 1]; //need a new 2d array with an extra spot for the new word

			for (int i = 0; i < size - 1; i++) { //loop to create spaces in the templist for the current dictionary and to copy over the information
				tempList[i] = new char[((strlen(dictionary[i]) + 1))]; //creating new line in the dictionary with the correct size
				strcpy(tempList[i], dictionary[i]); //copying the word over
			}
			tempList[size - 1] = new char[wordLength]; //after all the words are copied, make space for new word at end (will sort it after)
			strcpy(tempList[size - 1], newWord); //copy over the new word
			tempList[size] = NULL; //last place in the new list points to null

			for (int j = 0; j < size; j++) {
				delete[] dictionary[j]; //deleting the words in original dictionary
			}
			delete[] dictionary; //deleting what dictionary points to
			dictionary = tempList; //dictionary will now point to tempList that contains the new word
			
			selectionSort(dictionary); //sending the dictionary to be sorted, the new word was placed at the end before 
			size++;
		}
	}
}
void selectionSort(char** words) {
	for (; *words != NULL; words++) { //loops through each word until hits a null

		for (char** p = words + 1; *p != NULL; p++) { //will check each word with the word after it, until reach a NULL
			if ((strcmp(*words, *p)) > 0) { //comparing the words that *word and *p point to, will execute if *p really belongs before *word
				swapWords(*words, *p); //swapping what these pointers to point to the other words
			}
		}
	}
}
void swapWords(char*& word1, char*& word2) {

	char* temp = word1; //temp pointer to point to word1
	word1 = word2; //word1 points to word2
	word2 = temp; //word2 points to what word1 originally pointed to
}

void printAll(char** dictionary, int size) {

	for (int i = 0; i < size - 1; i++) { //printing contents of each line (each word) until hit index of the null
		cout << dictionary[i] << " ";
	}
	cout << endl;

	/*
	alt way to do:
	void printAll (const char** dictionary) {
		char** p = dictionary;
		while (*p) { //not pointing to null
			cout << *p << " "; 
		}
		cout << endl;
	}
	*/
}

void delStr(char**& dictionary, int& size, char* delWord) {

	for (int i = 0; i < size - 1; i++) { //will loop through dictionary until find  the word to delete (until hit null at end of list)
		if (!(strcmp(dictionary[i], delWord))) { //if the current word is the same as the word to delete, do the rest --> function returns 0 if the same so we need the ! to make it true

			char** tempList = new char* [size - 1]; //creating new list for the dictionary with the word deleted

			int j;
			for (j = 0; j < i; j++) { //going to copy the current contents of the dictionary up until the word to delete
				tempList[j] = new char[strlen(dictionary[j]) + 1]; //creating space for current word in the new list, of the exact length
				strcpy(tempList[j], dictionary[j]); //now copying the word from dictionary to the new list
			}
			for (; j < size - 2; j++) { //now continuing to copy over words starting from word after one to delete (essentially deleting the word)
				tempList[j] = new char[strlen(dictionary[j + 1]) + 1]; //creating space for next word in the new list (skipping one), of the exact length
				strcpy(tempList[j], dictionary[j + 1]); //now copying the word from dictionary to the new list
			}
			tempList[size - 2] = NULL; //setting last space to NULL

			for (int k = 0; k < size; k++) {
				delete[] dictionary[k]; //deleting the words in original dictionary
			}
			delete[] dictionary; //deleting what dictionary points to
			dictionary = tempList; //dictionary will now point to tempList that contains the new word

			size--; //decreasing size of list because deleted a word
		}
	}
}

char** searchStr(char** dictionary, int size, char* wordSearch) { //will search for word using binary search method
	int left = 0, right = size - 2; //right boundry starts right before the NULL at the end

	while (left <= right) {
		int middle = (left + right) / 2;

		if (!(strcmp(dictionary[middle], wordSearch))) { //if strcmp returns 0 (so need ! to make it true) then the current word is our word
			return &dictionary[middle]; //we found the word, so return the address for it			
		}
		if ((strcmp(dictionary[middle], wordSearch)) < 0) { //the word is in the second half of the list, it comes after the current word alphabetically
			left = (middle + 1);
		}
		if ((strcmp(dictionary[middle], wordSearch)) > 0) { //the word is in the first half of the list, it comes before the current word alphabetically
			right = (middle - 1);
		}
	}
	return NULL; //word wasn't found, so return NULL
}

void printChar(char** dictionary, int size, char letter) {

	for (int i = 0; i < size - 1; i++) { //will loop through all the words until the NULL at the end

		if (dictionary[i][0] == letter) { //if the first letter of every line is equal to the given letter
			cout << dictionary[i] << " ";
		}
	}
}
/*Enter 0-5:
0
Enter the word:
good
good
Enter 0-5:
0
Enter the word:
hello
good hello
Enter 0-5:
0
Enter the word:
shalom
good hello shalom
Enter 0-5:
0
Enter the word:
today
good hello shalom today
Enter 0-5:
2
Enter the word to search for:
what
Not Found
Enter 0-5:
2
Enter the word to search for:
hello
Found
Enter 0-5:
1
Enter the word to delete:
today
good hello shalom
Enter 0-5:
3
Enter the char:
s
shalom
Enter 0-5:
0
Enter the word:
toda
good hello shalom toda
Enter 0-5:
5

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework10.3\Debug\Homework10.3.exe (process 9376) exited with code 0.
Press any key to close this window . . .
*/