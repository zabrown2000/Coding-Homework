/*Zahava Brown
* TZ: 346287956
* Intro to Computer Science-Joyce Vogel
* Lab 13 Question 1
* This program will read in values from 2 files and will calculate the 
* average for each file and output which file has the highest average
*/

#include<iostream>
#include<fstream>
using namespace std;

float findAverage(ifstream& infile);
//function to read in and calculate the average of numbers from a file
//takes in 1 parameter, an opened file for reading as cbr
//returns a float value

int main() {
	float avg1, avg2;

	ifstream file1("grade1.txt"); //declaring variable of type ifstream to point to file grade1.txt
	if (!file1) { //checking that file1 opened successfully
		cout << "Error opening grade1\n";
		return -1;
	}

	ifstream file2("grade2.txt"); //declaring variable of type ifstream to point to file grade2.txt
	if (!file2) { //checking that file2 opened successfully
		cout << "Error opening file2\n";
		file1.close(); //before leave program want to close file1 because it was opened above
		return -1;
	}
	avg1 = findAverage(file1); //sending file1 to calculate average of its contents
	avg2 = findAverage(file2); //sending file2 to calculate average of its contents

	if (avg1 > avg2) { //if higher average came from file 1
		cout << "highest average found in file 1\n";
	}
	else { //if higher average came from file 2
		cout << "highest average found in file 2\n";
	}


	file1.close(); //need to close files before end program
	file2.close(); 
	return 0;
}

float findAverage(ifstream& infile) {
	int num, sum = 0, counter = 0;
	float average;

	while (!infile.eof()) { //will keep reading in numbers from file until it reaches the end

		infile >> num; //reads in number from file
		sum += num; //adds number to sum
		counter++; //keeping track of how many numbers added to the sum
	}
	average = (float)sum / counter; //calculating average, need to cast sum so answer itself will be a float
	return average;
}
/*highest average found in file 2

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework13.1\Debug\Homework13.1.exe (process 23692) exited with code 0.
Press any key to close this window . . .



contents of grade1:
1
2
3
4

contents of grade2:
20
12
*/