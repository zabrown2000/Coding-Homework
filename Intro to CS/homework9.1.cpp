/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 9 Question 1
This program will create a user-friendly menu to navigate a database of classrooms 
where the user can add, delete, search, or print the contents. This will be done 
by using  dynamically allocated memory*/

#include <iostream>
using namespace std;

int* newClass(int* roomList, int& size, int newRoom);
//function to add an element to an array in a sorted order using dynamic allocation
//takes in 3 parameters, a pointer to an array (dynamically allocated), the current size as a CBR, and the element to be added
//returns the address of the newly created dynamic array or NULL if none was created

void insertSort(int* classes, int size, int newClass);
//function to add an element to a sorted array 
//takes in 3 parameters, a pointer to an array (dynamically allocated), the size, and the element to be added
//returns no value as it affects the array directly 

void printAll(int* classrooms, int size);
//function to print the contents of an array
//takes in 2 parameters, a pointer for an array (dynamically allocated) and the array size
//returns no value as it is printing directly

int* delClass(int* roomList, int& size, int delRoom);
//function to delete an element from an array using dynamic allocation
//takes in 3 parameters, a pointer to an array (dynamically allocated), the current size as a CBR, and the element to be deleted
//returns the address of the newly created dynamic array or NULL if none was created

int* searchClass(int* classList, int size, int roomSearch);
//function to search for an element in an array and return the address if it was found
//takes in 3 parameters, pointer to the array (dynamically allocated), the size, and the element searching for
//returns a pointer with the location of the element if found or NULL if not found

void printCode(int* classList, int size, int classCode);
//function to print all elements that start with a specific 2-digit code 
//takes in 3 parameters, a pointer to an array (dynamically allocated), array size, and the 2-digit code
//returns no value as it is printing directly

int main() {

	int* database = NULL; //this will be the pointer used to point to the dynamic array with the classrooms
	int classCounter = 0, userChoice, classInput, codeInput, *classAddress, *databaseReturn;

	enum ACTION { ADD, DELETE, SEARCH, CODE_PRINT, ALL_PRINT };

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

			if (((classInput / 1000) % 11) || (classInput < 10000) || (classInput > 99999)) { //if user entered class that has an invalid class code or that's not 5 digits
				cout << "ERROR\n";
				cin >> classInput;
				break; //allow user to enter new input and then break from this switch iteration
			}
			else {
				databaseReturn = newClass(database, classCounter, classInput); //sending the pointer, current array size, and class to be added to the function
				if (databaseReturn != NULL) { //if function returned null it means the element existed so the array wasn't changed
					database = databaseReturn; //set pointer database to point to the new dynamic array created in function
				}
				printAll(database, classCounter); //sending the pointer to the dynamic array and the current size to be printed
				break;
			}
		
		case DELETE: //case when user enters 1--to delete an element from the database
			cout << "Enter the code of the classroom to delete:\n";
			cin >> classInput;

			if (((classInput / 1000) % 11) || (classInput < 10000) || (classInput > 99999)) { //if user entered class that has an invalid class code or that's not 5 digits
				cout << "ERROR\n";
				cin >> classInput;
				break; //allow user to enter new input and then break from this switch iteration
			}
			else {
				databaseReturn = delClass(database, classCounter, classInput); //sending the pointer, current array size, and class to be deleted to the function
				if (databaseReturn != NULL) { //if function returned null it means the element existed so the array wasn't changed
					database = databaseReturn; //set pointer database to point to the new dynamic array created in function
				}
				printAll(database, classCounter); //sending the pointer to the dynamic array and the current size to be printed
				break; //allow user to enter new input and then break from this switch iteration
			}
		
		case SEARCH: //case when user enters 2--to search from an element in the database
			cout << "Enter the code of the classroom to search for:\n";
			cin >> classInput;

			if ((classInput < 10000) || (classInput > 99999)) { //if user entered a non-5-digit number
				cout << "ERROR\n";
				cin >> userChoice;
				break; //allow user to enter new input and then break from this switch iteration
			}
			else {
				classAddress = searchClass(database, classCounter, classInput); //sending the class number to see if it's in the database and storing the address if found
				
				if (classAddress == NULL) { //if it wasn't found will return a null value
					cout << "Not found\n";
				}
				else { //otherwise print found
					cout << "Found\n";
				}
				break;
			}
		
		case CODE_PRINT: //case when user enters 3--to print all the elements with a specific 2-digit code in the beginning
			cout << "Enter the code of the Machon:\n";
			cin >> codeInput;

			if ((codeInput > 99) || ((codeInput % 11) != 0)) { //if user entered an invalid machon code
				cout << "ERROR\n";
				cin >> codeInput;
				printCode(database, classCounter, codeInput);
				cout << endl;
				break; 
			}
			else {
				printCode(database, classCounter, codeInput); //sending the pointer, current size, and code to the function
				cout << endl;
				break;
			}
		
		case ALL_PRINT: //case when user enters 4--to print all the elements in the database
			printAll(database, classCounter); //sending the pointer and size to be printed
			break;
		}
		cout << "Enter your next choice:\n";
		cin >> userChoice;
	}

	return 0;
}

int* newClass(int* roomList, int& size, int newRoom) {

	if (size == 0) { //if there are no elements in the database yet
		roomList = new int[1]; //create a dynamic array of size 1 that roomList will point to
		roomList[0] = newRoom; //now will add the new room to the database
		size++; //increase size because just added an element
		return roomList; //returning address of new dynamic array
	}
	else if (size == 1) { //if there is already an element in the database
		int* tempList = new int[2]; //create a new dynamic array of size 2 that tempList will point to

		if (newRoom > roomList[0]) { //if the new room to be added is greater than the current element in the database
			tempList[0] = roomList[0]; //set the first spot in the new dynamic array to the current element in roomList
			tempList[1] = newRoom; //the new element gets placed in the last spot of the new dynamic array

			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; //set roomList to point to the new dynamic array that tempList points to

			size++; //increase size because just added an element
			return roomList; //returning address of new dynamic array
		}
		else if (newRoom < roomList[0]) { //if the new room to be added is less than the current element in the database
			tempList[0] = newRoom; //set the first spot in the new dynamic array to the new element
			tempList[1] = roomList[0]; //now the current element gets placed in the last spot in the new dynamic array

			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; //set roomList to point to the new dynamic array that tempList points to

			size++; //increase size because just added an element
			return roomList; //returning address of new dynamic array
		}
	}
	else { //there are already multiple elements in the array
		bool exists = false; //flag to check if the new element exists in the dynamic array

		for (int i = 0; i < size; i++) {
			if (roomList[i] == newRoom) { //if the element exists, flag set to true and leave loop
				exists = true; 
				break;
			} 
		}
		if (exists == false) { //if new element not in the array
			int* tempList = new int[size + 1]; //need to make a new dynamic array with one extra space for the new element we'll be adding

			for (int j = 0; j < size; j++) { //copying over all the elements from old dynamic array to new dynamic array
				tempList[j] = roomList[j]; //last index in tempList will be empty
			}
			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; //set roomList to point to the new dynamic array that tempList points to
			insertSort(roomList, size + 1, newRoom); //sending the pointer to the dynamic array, it's new size, and the new element to be added to the function
			size++; //increase size because just added an element
			return roomList; //returning address of new dynamic array
		}
	}
	return NULL; //this means the element already exists so no new address to return
}
void insertSort(int* classes, int size, int newClass) {
	int sizeBound = size - 2;

	while ((classes[sizeBound] > newClass) && (sizeBound >= 0)) {
		classes[sizeBound + 1] = classes[sizeBound]; //moving elements to the right
		sizeBound--; //reducing how far checking in the array
	}
	classes[sizeBound + 1] = newClass; //adding the element to the correct spot, made room for it in the loop, or it will go at the end because it is greater than the last element
}

void printAll(int* classrooms, int size) {

	for (int i = 0; i < size; i++) {
		cout << classrooms[i] << " "; //printing each element of the array with a space after
	}
	cout << endl;
}

int* delClass(int* roomList, int& size, int delRoom) {
	for (int i = 0; i < size; i++) { //looping to find the element in the array so can delete it
		
		if (roomList[i] == delRoom) { //if found it then will copy over all the elements except for that one into a new shortened dynamic array
			int* tempList = new int[size - 1]; //need to make new dynamic array with 1 less spot because we are removing an element
			
			int j; //need to declare variable here so it can be used in 2 consecutive loops
			for (j = 0; j < i; j++) { //will loop through all the elements until arrive at the element we want to delete
				tempList[j] = roomList[j]; //copying element from old dynamic array to the new one
			}
			for (; j < (size - 1); j++) { //no need to initialize j here because picking up where left off in previous loop
				tempList[j] = roomList[j + 1]; //need j+1 because skipping the element at index i (that's why needed size-1 in the loop)
			}
			//delete[] roomList; //delete the array that roomList was currently pointing to
			roomList = tempList; //set roomList to point to the new dynamic array that tempList points to
			size--; //decreasing size by 1 because just removed an element
			return roomList; //no need to continue, we found the element and deleted it, so can return address of new dynmaic array
		}
	}
	return NULL; //this means the element already exists so no new address to return
}

int* searchClass(int* classList, int size, int roomSearch) { //will be using binary search method
	int* address = NULL, left = 0, right = (size - 1);

	while (left <= right) {
		int middle = (left + right) / 2;

		if (classList[middle] == roomSearch) { //if element is found set the location of the element to variable address and return it, leaving function
			address = &classList[middle];
			return address;
		}
		if (classList[middle] < roomSearch) { //element not in left half of array
			left = (middle + 1);
		}
		if (classList[middle] > roomSearch) { //element not in right half of array
			right = (middle - 1);
		}
	}
	return address; //will return null because left loop without having found item
}

void printCode(int* classList, int size, int classCode) {

	for (int i = 0; i < size; i++) {
		if ((classList[i] / 1000) == classCode) { //printing all the elements that begin with the 2-digit code sent to the function
			cout << classList[i] << " ";
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
33555
ERROR
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
0
Enter the code of the classroom to add:
22222
11111 22222 33333 44444
Enter your next choice:
3
Enter the code of the Machon:
5555
ERROR
55

Enter your next choice:
1
Enter the code of the classroom to delete:
33333
11111 22222 44444
Enter your next choice:
1
Enter the code of the classroom to delete:
33333
11111 22222 44444
Enter your next choice:
4
11111 22222 44444
Enter your next choice:
5

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework9.1\Debug\Homework9.1.exe (process 544) exited with code 0.
Press any key to close this window . . .
*/