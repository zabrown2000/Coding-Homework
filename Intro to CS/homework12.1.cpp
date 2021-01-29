/*Zahava Brown
TZ: 346287956
Intro to Computer Science-Joyce Vogel
Lab 12 Question 1
This program will act as a database for products in a particular store.
The user can add items, make "purchases", order more items, find pricing
info on an item, and print all the inventory information*/

#include<iostream>
#include <cstring>
using namespace std;

struct Item {

	int itemCode;       //product code
	char itemName[20];  //name of product
	int curStock;       //current amount of item in stock
	int minStock;       //minimum amount of stock needed for an item 
	float itemPrice;    //price of the product
};

void addItem (Item* productList, int maxProducts, int& amtProducts); //add & if not being changed
//function to add a struct element to a list/array of products in a store
//takes in 3 parameters, a pointer to the array of products, the limit on amount of elements to be added, and the current amount of items as CBR
//returns no value as it changes the database/array directly

int codeIndex(Item* productList, int amtProducts, int userCode);
//function to search for a specific field value in an array of structs 
//takes in 3 parameters, a pointer to the struct list, amount of products in list, and the value to search for
//returns int value of the index of struct item if the value is found or -1 if not

void findPrice(Item* productList, int amtProducts);
//function to find the price of an item in the store
//takes in 2 parameters, a pointer to the array of products and the amount of products inside it
//returns no value as it prints directly from the function

void sold(Item* productList, int amtProducts);
//function to record a sale and adjust the stock accordingly
//takes in 2 parameters, a pointer to the array of products and the amount of products inside it
//returns no value as it changes the database/array directly

void order(Item* productList, int amtProducts);
//function to go through all products in the store and check if new stock needs to be ordered for any item
//takes in 2 parameters, a pointer to the array of products and the amount of products inside it
//returns no value as it changes the database/array directly and prints directly from the function

void print(Item* productList, int amtProducts);
//function to print all the products in the list
//takes in 2 parameters, a pointer to the array of products and the amount of products inside it
//returns no value as it prints directly from the function

int main() {
	enum cases { EXIT, ADD, FIND, SOLD, ORDER, PRINT }; //setting this up so easier to read in switch statement

	Item* store; //declaring variable of struct type Item

	int maxItems;
	int numItems = 0; //current amount of items in the store
	int userChoice;
	cout << "enter max number of items: " << endl;
	cin >> maxItems;
	store = new Item[maxItems]; //setting up array of type Item with maxItems spots

	do {
		cout << "enter 0-5:\n";

		cin >> userChoice;

		switch (userChoice) {
		case EXIT:	//case where user entered a 0, terminating the program
			break;

		case ADD:	//case where user enters a 1, to add a product to the store
			addItem(store, maxItems, numItems); //calling function to add a new item to the store
			break;

		case FIND: 	//case where user enters a 2, to find specific information about a product
			findPrice(store, numItems); //calling function to find the price of an item
			break;

		case SOLD:	//case where user enters a 3, recording a product(s) sold and adjusting accordingly
			sold(store, numItems); //calling a function to update stock after a sell
			break;

		case ORDER:	//case where user enters a 4, making an order to update the stock of items with low inventory
			order(store, numItems); //calling function to place an order to update stock
			break;

		case PRINT: //case when user enters a 5, printing all the products in the store with their info
			print(store, numItems); //calling function to print all the products in the store
			break;

		default: //case where user entered invalid input
			cout << "ERROR" << endl;
			break;
		}
	} while (userChoice != 0); //loop will end once user enters 0 (the EXIT case)

	delete[] store;

	return 0;
}

void addItem(Item* productList, int maxProducts, int& amtProducts) {
	int tempCode, tempCurAmt, tempMinAmt;
	char tempName[20];
	float tempPrice;

		cout << "enter code:\n"; //asking user for values for a new product which will be added if following requirements are met
		cin >> tempCode;
		cout << "enter name:\n";
		cin >> tempName;     
		cout << "enter amount:\n";
		cin >> tempCurAmt;
		cout << "enter minimum amount:\n";
		cin >> tempMinAmt;
		cout << "enter price:\n";
		cin >> tempPrice;

		if (amtProducts == 0) { //currently no elements in list so nothing to check
			productList[amtProducts].itemCode = tempCode;
			strcpy_s(productList[amtProducts].itemName, tempName); //for VS
			//strcpy(productList[amtProducts].itemName, tempName); //for moodle
			productList[amtProducts].curStock = tempCurAmt;
			productList[amtProducts].minStock = tempMinAmt;
			productList[amtProducts].itemPrice = tempPrice;

			amtProducts++; //added item so updating size
			return; //did what we needed to, now can leave function
		}

		int existingCode = codeIndex(productList, amtProducts, tempCode); //calling function to try and find index of code in the list, if it exists

		if (existingCode >= 0) { //function didn't return a -1, so item code exists at index existingCode

			if (strcmp(tempName, productList[existingCode].itemName) == 0) { //now check if the name given by user is the same as the name associated with given code
				productList[existingCode].curStock += tempCurAmt; //updated stock to amount user gave
				return; //nothing left to do, item exists so just updated stock
			}
			else { //product with this code exists but the names are different
				cout << "ERROR\n";
				return; //nothing left to do, user entered invalid code and name combo
			}
		}
		else { //returned 0, so code doesn't exist--item doesn't exist, so now checking if enough room to add another item 
			if ((amtProducts + 1) <= maxProducts) { //enough room so can add in info to new element (at index amtProducts) and update size
			
				productList[amtProducts].itemCode = tempCode;
				strcpy_s(productList[amtProducts].itemName, tempName); //for VS
				//strcpy(productList[amtProducts].itemName, tempName); //for moodle
				productList[amtProducts].curStock = tempCurAmt;
				productList[amtProducts].minStock = tempMinAmt;
				productList[amtProducts].itemPrice = tempPrice;

				amtProducts++; //added item so updating size
				return; //did what we needed to, now can leave function
			}
			else { //not enough room left in array to add another item
				cout << "ERROR\n";
			}
		}
}

int codeIndex(Item* productList, int amtProducts, int userCode) {

	for (int i = 0; i < amtProducts; i++) { //loop through all items to find the code
		if (productList[i].itemCode == userCode) { //we found the code, so return the index of the item in the array
			return i;
		}
	}
	return -1; //never found the code so return -1
}

void findPrice(Item* productList, int amtProducts) {
	int inputCode;

	cout << "enter code:\n"; //getting info from user to look for the item price
	cin >> inputCode;

	for (int i = 0; i < amtProducts; i++) { //now will loop through list to find a product with an item code that matches user input

		if (inputCode == productList[i].itemCode) { //found the item user is looking for
			cout << "price: " << productList[i].itemPrice << endl;
			return; //can leave function because found item and printed price
		}
	}
	cout << "ERROR\n"; //this means looped through entire list and did not find product code matching user input
}

void sold(Item* productList, int amtProducts) {
	int inputCode, inputAmt;

	cout << "enter code:\n"; //getting info from user to use to update stock
	cin >> inputCode;
	cout << "enter amount:\n";
	cin >> inputAmt;

	for (int i = 0; i < amtProducts; i++) { //looping through list to find product to update

		if (inputCode == productList[i].itemCode) { //found item by a matching code
			productList[i].curStock -= inputAmt; //deducting amount sold from the inventory of a particular item
			return; //did what we need, can leave function
		}
	}
	cout << "ERROR\n"; //this means looped through entire list and did not find product code matching user input
}

void order(Item* productList, int amtProducts) {
	int toOrder;

	for (int i = 0; i < amtProducts; i++) {

		if (productList[i].curStock < productList[i].minStock) { //checking each item if the current stock is less than minimum amount needed to be in stock
			cout << "item name: " << productList[i].itemName << endl;
			cout << "code: " << productList[i].itemCode << endl;

			toOrder = productList[i].minStock - productList[i].curStock + 5; //want that number in stock for product is 5 more than its minimum
			productList[i].curStock += toOrder; //updating stock to include the "order" made
			cout << "amount to order: " << toOrder << endl;
		}
	}
}

void print(Item* productList, int amtProducts) {

	for (int i = 0; i < amtProducts; i++) { //looping through all elements to print

		cout << "name: " << productList[i].itemName << endl;
		cout << "code: " << productList[i].itemCode << endl;
		cout << "amount: " << productList[i].curStock << endl;
		cout << "minimum amount: " << productList[i].minStock << endl;
		cout << "price: " << productList[i].itemPrice << endl;
		cout << endl;
	}
}
/*enter max number of items:
3
enter 0-5:
1
enter code:
20
enter name:
apple
enter amount:
13
enter minimum amount:
5
enter price:
0.25
enter 0-5:
1
enter code:
21
enter name:
orange
enter amount:
5
enter minimum amount:
5
enter price:
.20
enter 0-5:
1
enter code:
21
enter name:
car
enter amount:
5
enter minimum amount:
1
enter price:
500
ERROR
enter 0-5:
1
enter code:
22
enter name:
banana
enter amount:
56
enter minimum amount:
30
enter price:
1.25
enter 0-5:
1
enter code:
20
enter name:
apple
enter amount:
2
enter minimum amount:
3
enter price:
0.25
enter 0-5:
5
name: apple
code: 20
amount: 15
minimum amount: 5
price: 0.25

name: orange
code: 21
amount: 5
minimum amount: 5
price: 0.2

name: banana
code: 22
amount: 56
minimum amount: 30
price: 1.25

enter 0-5:
2
enter code:
21
price: 0.2
enter 0-5:
3
enter code:
21
enter amount:
4
enter 0-5:
4
item name: orange
code: 21
amount to order: 9
enter 0-5:
5
name: apple
code: 20
amount: 15
minimum amount: 5
price: 0.25

name: orange
code: 21
amount: 10
minimum amount: 5
price: 0.2

name: banana
code: 22
amount: 56
minimum amount: 30
price: 1.25

enter 0-5:
0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework12.1\Debug\Homework12.1.exe (process 18484) exited with code 0.
Press any key to close this window . . .
*/