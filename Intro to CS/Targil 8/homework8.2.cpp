/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 8 Question 2
This program will create a user-friendly menu to navigate a 
database of classrooms where the user can add, delete, 
search, or print the contents*/ 

#include <iostream>
using namespace std;

void printAll(int* classrooms, int size);
//function to print the contents of an array using pointers
//takes in 2 parameters, a pointer for an array and the array size
//returns no value as it is printing directly

void newClass(int* roomList, int& size, int newRoom);
//function to add an element to an array in a sorted order using pointers
//takes in 3 parameters, a pointer to an array, the size as a CBR, and the element to be added
//returns no value as it affects the array directly

void insertSort(int* classes, int size, int newClass);
//function to add an element to a sorted array using pointers
//takes in 3 parameters, a pointer to an array, the size, and the element to be added
//returns no value as it affects the array directly 

void delClass(int* roomList, int& size, int delRoom);
//function to delete an element from an array using pointers
//takes in 3 parameters, a pointer to an array, the size as a CBR, and the element to be deleted
//returns no value as it affects the array directly

int* searchClass(int* classList, int size, int roomSearch);
//function to search for an element in an array and return the address if it was found, all using pointers
//takes in 3 parameters, pointer to the array, the size, and the element searching for
//returns a pointer of the location of the element or NULL if not found

void printCode(int* classList, int size, int classCode);
//function to print all elements that start with a specific 2-digit code 
//takes in 3 parameters, a pointer to an array, array size, and the 2-digit code
//returns no value as it is printing directly

int main() {

	int database[50], classCounter = 0, userChoice, classInput, codeInput;
	int *pDatabase = database, *classAddress;

	enum ACTION {ADD, DELETE, SEARCH, CODE_PRINT, ALL_PRINT}; //using enum so switch below is easier to read

	cout << "Enter 0 to add a new classroom.\n";
	cout << "Enter 1 to delete a hybrid classroom.\n";
	cout << "Enter 2 to search for a specific classroom.\n";
	cout << "Enter 3 to print all the classsrooms for a specific Machon.\n";
	cout << "Enter 4 to print all the hybrid classrooms.\n";
	cout << "Enter 5 to exit.\n";
	
	cout << "Enter your choice:\n";
	cin >> userChoice;

	while (userChoice != 5) { //as soon as user enters a 5 loop will end, ending the program
		if ((userChoice > 4) || (userChoice < 0)) { //now checking if user entered a valid menu option
			cout << "ERROR\n";
			cin >> userChoice;
			continue; //after storing new input will check that it's not a 5 and then again to see if it's valid
		}
		switch (userChoice) {
		
		case ADD: //case when user enters 0--to add an element to the database
			cout << "Enter the code of the classroom to add:\n";
			cin >> classInput;
			if ((classInput / 1000) % 11) { //if user entered an invalid classroom option (doesn't have a valid campus code)
				cout << "ERROR\n";
				cin >> classInput;
				break; //leave the switch statement and will go to next iteration
			}
			else {
				newClass(pDatabase, classCounter, classInput); //sending array and new element to be added to the array
				printAll(pDatabase, classCounter); //printing all the current elements in the database
				break;
			}
		
		case DELETE: //case when user enters 1--to delete element from database
			cout << "Enter the code of the classroom to delete:\n";
			cin >> classInput;
			if ((classInput / 1000) % 11) { //if user entered an invalid classroom option (doesn't have a valid campus code)
				cout << "ERROR\n";
				cin >> classInput;
				break; //leave the switch statement and will go to next iteration
			}
			else {
				delClass(pDatabase, classCounter, classInput);
				printAll(pDatabase, classCounter); //printing all the current elements in the database
				break;
			}
		
		case SEARCH: //case when user enters 2 and wants to see if a classroom is in the database
			cout << "Enter the code of the classroom to search for:\n";
			cin >> classInput;

			classAddress = searchClass(pDatabase, classCounter, classInput); //sending the class number to see if it's in the database and storing the address if found
			if (classAddress == NULL) { //if it wasn't found will return a null value
				cout << "Not found\n";
			}
			else { //otherwise print found
				//cout << "Found at location " << classAddress << " in memory" << endl; //prints the memory
				cout << "Found\n";
			}
			break;
		
		case CODE_PRINT: //case when user enters and wants to print the classrooms of a specific campus
			cout << "Enter the code of the Machon:\n";
			cin >> codeInput;
			
			if ((codeInput % 11) || (codeInput >= 100)) { //if user entered invalid machon code then it will take in a new value and thensend to the function
				cout << "ERROR\n";
				cin >> codeInput;
				printCode(pDatabase, classCounter, codeInput);
				cout << endl;
				break;
			}
			else { //otherwise send the code to a function to only print out classrooms in that campus
				printCode(pDatabase, classCounter, codeInput);
				cout << endl;
				break;
			}

		case ALL_PRINT: //case when user enters 4 and wants to print all curernt elements in the database
			printAll(pDatabase, classCounter);
			break;
		}
		cout << "Enter your next choice:\n";
		cin >> userChoice;
	}

	return 0;
}

void printAll(int* classrooms, int size) {

	for (int* p = classrooms; p < (classrooms + size); p++) { //printing each element of the array that is filled
		cout << *p << " ";
	}
	cout << endl;
}

void newClass(int* roomList, int& size, int newRoom) {

	if (size == 0) { //no elements were added to the array yet, so just set the new element to the first spot of the array
		*roomList = newRoom;
		size++; //increase size by 1, it's adding to the counter that was sent as a parameter to gage the current size of the array
	}
	else if (size == 1) { //there is only 1 element in the array so will compare the values to see which one goes first
		if (newRoom > *roomList) { //new element is greater so just add it to the next open spot
			*(roomList + 1) = newRoom;
			size++;
		}
		else if (newRoom < *roomList) { //new element is less than current element so need to swap them
			int temp = *roomList;
			*roomList = newRoom;
			*(roomList + 1) = temp;
			size++;
		} //if the new element is equal to the current element it won't do anything
	}
	else { //there are a number of elements in the array already 
		bool exists = false; //flag to check if the new elements exists in the array
		for (int* p = roomList; p < (roomList + size); p++) { //if the elements exists, flag set to true and leave loop
			if (*p == newRoom) {
				exists = true;
				break;
			}
		}
		if (exists == false) { //if the element is not in the array
			insertSort(roomList, size, newRoom); //we need to add the new element using the insert sort method
			size++;
		}
	}
}
void insertSort(int* classes, int size, int newClass) {
	int sizeBound = size - 1;
	while ((*(classes + sizeBound) > newClass) && (sizeBound >= 0)) {
		*(classes + (sizeBound + 1)) = *(classes + sizeBound); //moving elements to the right
		sizeBound--; //reducing how far checking in the array
	}
	*(classes + (sizeBound + 1)) = newClass; //adding the element to the correct spot, made room for it in the loop, or it will go at the end because it is greater than the last element 
}

void delClass(int* roomList, int& size, int delRoom) {

	for (int* p = roomList; p < (roomList + size); p++) { //will now go through all the elements in the array to find the element to delete
		if (*p == delRoom) { //if it's never equal, nothing will happen
			for (int* q = p; q < (p + (size - 1)); q++) { //moving all elements to the left because got rid of one of the elements
				*q = *(q + 1);
			}
			size--; //the size of the array decreased since the element was deleted
			break; //no need to continue, found the element
		}
	}
}

int* searchClass(int* classList, int size, int roomSearch) {
	int *address = NULL, left = 0, right = (size - 1); //will use binary search method since the array is sorted

	while (left <= right) {
		int middle = (left + right) / 2;

		if (*(classList + middle) == roomSearch) { //if element is found set the location to variable address and return it, leaving function
			address = (classList + middle);
			return address;
		}
		if (*(classList + middle) < roomSearch) { //element not in left half of array
			left = (middle + 1);
		}
		if (*(classList + middle) > roomSearch) { //element not in right half of array
			right = (middle - 1);
		}
	}
	return address; //it will return null because there were no cases when the element was found which would have resulted in the program ending
}

void printCode(int* classList, int size, int classCode) {

	for (int* p = classList; p < (classList + size); p++) {
		if (((*p) / 1000) == classCode) { //if the first 2 digits of the class number are equal to the class code, then print the class
			cout << *p << " ";
		}
	}
}
/*Enter 0 to add a new classroom.
Enter 1 to delete a hybrid classroom.
Enter 2 to search for a specific classroom.
Enter 3 to print all the classsrooms for a specific Machon.
Enter 4 to print all the hybrid classrooms.
Enter 5 to exit.
Enter your choice:
0
Enter the code of the classroom to add:
11111
11111
Enter your next choice:
0
Enter the code of the classroom to add:
44444
11111 44444
Enter your next choice:
0
Enter the code of the classroom to add:
33333
11111 33333 44444
Enter your next choice:
0
Enter the code of the classroom to add:
33555
11111 33333 33555 44444
Enter your next choice:
3
Enter the code of the Machon:
33
33333 33555
Enter your next choice:
4
11111 33333 33555 44444
Enter your next choice:
2
Enter the code of the classroom to search for:
65656
Not found
Enter your next choice:
2
Enter the code of the classroom to search for:
11111
Found
Enter your next choice:
1
Enter the code of the classroom to delete:
33555
11111 33333 44444
Enter your next choice:
5

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework8.2\Debug\Homework8.2.exe (process 11652) exited with code 0.
Press any key to close this window . . .
*/