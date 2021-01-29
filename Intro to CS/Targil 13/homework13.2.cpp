/*Zahava Brown
* TZ: 346287956
* Intro to Computer Science-Joyce Vogel
* Lab 13 Question 2
* This program will read in information from a text file 
* and record the frequency of the digits in seperate file as
* well as printing it to the console.
*/

#include<iostream>
#include<fstream>
using namespace std;

void frequency(ifstream& inFile, ofstream& outFile, int freq[], int size);
//function to record frequency of digits in a given file
//takes in 4 parameters, the reading and writing files, the array to be used as a counter, and the array size
//does not return a value as it changes the file directly

int main() {
	char fileName[25];
	int counter[10] = { 0 };

	cout << "Enter a name for reading file\n";
	cin >> fileName;

	ifstream readFile(fileName); //declaring ifstream variable to point to file of name given by user
	if (!readFile) { //checking if file opened correctly
		cout << "Error opening file " << fileName << endl;
		return -1;
	}

	ofstream writeFile("frequencyDigits.txt"); //declaring ofstream variable to point to frequency file
	if (!writeFile) { //checking if file opened correctly
		cout << "Error opening output file\n";
		readFile.close(); //closing file already opened before ending the program
		return -1;
	}
	writeFile << "digit\t" <<"frequency\n"; //writing to file
	cout << "digit\t" << "frequency\n"; //printing to console

	frequency(readFile, writeFile, counter, 10); //calling function to record the frequency

	readFile.close(); //closing the files before ending the program
	writeFile.close();
	return 0;
}

void frequency(ifstream& inFile, ofstream& outFile, int freq[], int size) {

	char input;
	int index;

	while (inFile >> input) { //keep reading until end of file, didn't use .eof() because it was reading the last character twice
		if (input >= '0' && input <= '9') { //as long as input is a digit between 0 and 9
			index = input - '0'; //casting the char value to be an integer
			freq[index]++; //updating frequency of the digit found in the array
		}
	}
	for (int i = 0; i < size; i++) { //now going through array and will print to file and console the values

		outFile << i << '\t' << freq[i] << endl; //writing info to file
		cout << i << '\t' << freq[i] << endl; //printing info to console
	}
}
/*
information.txt
digit   frequency
0       4
1       3
2       1
3       0
4       1
5       2
6       1
7       0
8       0
9       2

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework13.2\Debug\Homework13.2.exe (process 29160) exited with code 0.
Press any key to close this window . . .



read from file below:

mavo 150005
semester 1 2019
694 students
*/