/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 6 Question 3

this program will take in up to 100 values from the user and then print 
them out, leaving out any duplicates and the amount of elements 
now that the duplicates are gone*/
#include <iostream>
using namespace std;

void fillArray(int arr[], const int size);
//function to fill an array based on user input and to stop once user enters 0
//takes in 2 parameters, array and array size
//doesn't return a value, will change the array directly

void checkRepeats(int arr2[], const int size);
//function to check for any repeat numbers in an array and to get rid of them
//takes in 2 parameters, array and array size
//doesn't return a value, will change the array directly

int printArray(int arr3[], const int size);
//function to print out all the remaining elements of an array (after duplicates deleted) and to count the amount of numbers being printed
//takes in 2 parameters, array and array size
//returns int value of the amount of numbers printed

int main() {
    
    int hundredNums[100] = { 0 }, elementsLeft;
    cout << "enter up to 100  values, to stop enter 0:\n";

    fillArray(hundredNums, 100); //filling up the array, it will stop once the user enters a 0

    checkRepeats(hundredNums, 100); //gets rid of any duplicate numbers

    cout << "the new vector is:\n";
    elementsLeft = printArray(hundredNums, 100); //printing out the remaining elements as well as counting how many are left

    cout << "number of elements:  " << elementsLeft << endl;
    
    return 0;
}


void fillArray(int arr[], const int size) {

    int input; //so we can compare the input to 0
    
    for (int i = 0; i < size; i++) { //loop to fill the array
        cin >> input;
        if (input == 0) { //checking for each iteration if the input was 0, at which the loop will end
            break;
        }
        else { //otherwise, keep adding elements to the array
            arr[i] = input;
        }
    }
}

void checkRepeats(int arr2[], const int size) {
   
    for (int i = 0; i < size; i++) { // iterate through each element of the array
        
        if (arr2[i] == 0) //later on a duplicate will get changed to 0, but it won't affect things here
            break; //end of user inputs so leave the loop   
        
        for (int j = i; j >= 0; j--) { // Checks element i against the existing numbers in the array, counting down
            
            if (j != i) { // Makes sure don't check number against itself, then will be getting rid of a false number
                
                if (arr2[i] == arr2[j]) {
                    arr2[i] = 0; //once this new element finds a duplicate in an earlier element, change the value to 0
                }
            }
            
        } 
    }
}

int printArray(int arr3[], const int size) {
    
    int counter = 0;

    for (int i = 0; i < size; i++) {
        if (arr3[i] != 0) { //only the non-0 elements will be printed (duplicates were changed to 0)
            cout << arr3[i] << " "; //printing with a space after it
            counter++; //adding to counter each time a number is printed-to get the remaining elements
        }
    }
    cout << endl; //we want a new line for the next print statement
    return counter; //returning the counter value so it can be printed
}

/*enter up to 100  values, to stop enter 0:
1 5 8 9 5 4 1 2 3 5 1 4 8 9 6 5 0
the new vector is:
1 5 8 9 4 2 3 6
number of elements:  8

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework6.3\Debug\Homework6.3.exe (process 744) exited with code 0.
Press any key to close this window . . .
*/
