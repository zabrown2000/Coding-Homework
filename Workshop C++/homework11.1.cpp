/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 11 Question 1
This program will perform work with binary files for 
storing records of type Family*/

#include <iostream>
#include <fstream>
#include <queue>
#include "Family.h"
using namespace std;

enum option {EXIT, ADD, DEL, UPDATE, WAITING, RISHUM, PRINT, CLASS};

/// <summary>
/// function to initialize a binary file with blank files
/// </summary>
/// <param name="families">fstream&</param>
void setFile(fstream& families);

/// <summary>
/// function to add a family to the database
/// </summary>
/// <param name="families">fstream&</param>
void add(fstream& families);

/// <summary>
/// function to delete a family from the database
/// </summary>
/// <param name="families">fstream&</param>
/// <param name="id">int</param>
void del(fstream& families, int id);

/// <summary>
/// function to update the activities for a family
/// </summary>
/// <param name="familes">fstream&</param>
/// <param name="id">int</param>
/// <param name="q">queue<Family>&</param>
void update(fstream& families, int id, queue<Family>& q);

/// <summary>
/// function to check if there is room for anyone in the waiting list and to update accordingly
/// </summary>
/// <param name="families">fstream&</param>
/// <param name="q">queue<Family>&</param>
void waiting(fstream& families, queue<Family>& q);

/// <summary>
/// function to check if a family is registered for a given activity
/// </summary>
/// <param name="families">fstream&</param>
/// <param name="id">int</param>
/// <param name="act">int</param>
/// <returns></returns>
bool rishum(fstream& families, int id, int act);

/// <summary>
/// function to print info of given family from data base
/// </summary>
/// <param name="families">fstream&</param>
/// <param name="id">int</param>
void print(fstream& families, int id);

/// <summary>
/// function to print all of the families with members registered for a specific activity
/// </summary>
/// <param name="families"></param>
/// <param name="act"></param>
void inClass(fstream& families, int act);

/// <summary>
/// function to check if a family id exists in the database
/// </summary>
/// <param name="families">fstream&</param>
/// <param name="id">int</param>
/// <returns>bool</returns>
bool checkID(fstream& families, int id);

/// <summary>
/// function to check if there are more than 10 families registered for a particular event
/// </summary>
/// <param name="families">fstream&</param>
/// <param name="act">int</param>
/// <returns>bool</returns>
bool checkActs(fstream& families, int act);


int main()
{
	queue<Family> q;
	fstream file;
	file.open("families.dat", ios::binary | ios::out | ios::in);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}      
	setFile(file);
	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to update rishum to classes\n4 to update waiting to classes \n5 to check rishum for a classas\n6 to print a family\n7 to print all the families that participate in a specific class\n";
	cout << "enter 0-7:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case ADD://add to the file
			try { add(file); }
			catch (const char* msg) { cout << msg; }
			break;

		case DEL://delete from file
			cout << "enter number of family to delete:\n";
			cin >> snum;
			try { del(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;

		case UPDATE://update the list of classes of a family
			cout << "enter number of family to update:\n";
			cin >> snum;
			try { update(file, snum, q); }
			catch (const char* msg) { cout << msg; }
			break;

		case WAITING://update the list of classes of a waiting family
			waiting(file, q);
			break;

		case RISHUM://check rishum to a specific class
			cout << "enter number of family to check rishum:\n";
			cin >> snum;
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try
			{
				cout << "The family is" << (rishum(file, snum, cnum) ? " " : " not ") << "taking the class\n";
			}
			catch (const char* msg) { cout << msg; }
			break;

		case PRINT://print the details of a specific family
			cout << "enter number of family to print:\n";
			cin >> snum;
			try { print(file, snum); }
			catch (const char* msg) { cout << msg; }
			break;

		case CLASS://print the details of all the families that are taking a specific class
			cout << "enter number of class to check rishum:\n";
			cin >> cnum;
			try { inClass(file, cnum); }
			catch (const char* msg) { cout << msg; }
			break;

		default:
			cout << "ERROR: invalid choice\n";

		}
		cout << "\nenter 0-7:\n";
		cin >> choice;
	}
	file.close();
	return 0;
}

void setFile(fstream& families) {
	Family f;
	for (int i = 0; i < 100; i++) {
		families.write((char*)&f, sizeof(Family)); //writing 100 blank records to file
	}
}

void add(fstream& families) {
	Family f;
	int input;

	cout << "Enter the family ID\n";
	cin >> input;
	if ((input < 1) || (input > 100)) throw "ERROR: Invalid family number\n";

	bool famExists = checkID(families, input); //checking if id exists
	if (famExists) throw "ERROR: Family is already in the file\n"; //id found in database so already exists

	f.setID(input);

	cout << "Enter family name, amount of family members, and a phone number\n";
	char name[20];
	cin >> name;
	f.setName(name);
	cin >> input;
	f.setMems(input);
	cin >> input;
	f.setPhone(input);

	//now will write family into record
	families.seekp((f.getID() - 1) * sizeof(Family), ios::beg);
	families.write((char*)&f, sizeof(Family));
}

void del(fstream& families, int id) {

	if ((id < 1) || (id > 100)) throw "ERROR: Invalid family number\n";

	//will overwrite current record id with 0, as if deleting it
	families.seekp((id - 1) * sizeof(Family), ios::beg);
	int id0 = 0;
	families.write((char*)&id0, sizeof(id0));
}

void update(fstream& families, int id, queue<Family>& q) {
	if ((id < 1) || (id > 100)) throw "ERROR: Invalid family number\n";
	bool famExists = checkID(families, id); //checking if id exists
	if (!famExists) throw "ERROR: Family is not in the file\n"; //id found in database so already exists

	bool list[6];

	cout << "Please enter 1 to register for an activity, and 0 if not for each of 6 activities\n";
	for (int i = 0; i < 6; i++) {
		cin >> list[i];
	}
	families.seekg((id - 1) * sizeof(Family), ios::beg);
	Family f;
	families.read((char*)&f, sizeof(Family)); //getting family info to can update activities accordingly


	//now will go through user input and update accordingly
	for (int i = 0; i < 6; i++) {
		if (list[i] == false) {
			f.setAct(i + 1, false);
		}
		else {
			if (checkActs(families, i + 1)) { //will return true if limit registeration was reached
				f.setAct(i + 1, false); //no space
				Family f2 = f; //making new family to put in queue so bool vector reflects correct activity
				bool b[6] = { 0 };
				f2.setActs(b);
				f2.setAct(i + 1, true);
				q.push(f2); //puts family in waiting list queue
				
			}
			else { //has space, so registering
				f.setAct(i + 1, true); //there is space to register
			}
			
		}
	}
	families.seekp((id - 1) * sizeof(Family), ios::beg); //now getting file to write
	families.write((char*)&f, sizeof(Family));
}

void waiting(fstream& families, queue<Family>& q) {
	int size = q.size(); //getting amount of elements in 

	Family f;
	for (int i = 0; i < size; i++) { //going through all current elements once and getting rid of ones that have space now
		f = q.front();
		q.pop();
		int j = 0;
		for (; j < 6; j++) {
			if (f.getAct(j + 1)) {
				break; //got true value, this is what we need to check
			}
		}
		if (checkActs(families, j + 1)) { //if returns true, can't register family
			q.push(f); //put family back to end of queue to be checked next round 
		}
		else {
			cout << f.getName() << " " << f.getPhone() << " Do you still want to register for activity " << j + 1 << "? Y/N\n";
			char ans;
			cin >> ans;

			if (ans == 'Y') { //now need to update in file
				families.seekg((f.getID() + 1) * sizeof(Family), ios::beg); //reading what's in file so can update activity and then overwrite it
				Family f2;
				families.read((char*)&f2, sizeof(Family));

				f2.setAct(j + 1, true); //now registered
				families.seekp((f.getID() + 1) * sizeof(Family), ios::beg);
				families.write((char*)&f2, sizeof(Family)); //now writing family back to file with activity update
			}
		}
	}
}

bool rishum(fstream& families, int id, int act) {
	
	if ((act < 1) || (act > 6)) throw "ERROR: Invalid class number\n";
	if ((id < 1) || (id > 100)) throw "ERROR: Invalid family number\n";
	bool famExists = checkID(families, id); //checking if id exists
	if (!famExists) throw "ERROR: Family is not in the file\n"; //id found in database so already exists

	families.seekg((id - 1) * sizeof(Family), ios::beg);
	Family f;
	families.read((char*)&f, sizeof(Family));

	return f.getAct(act - 1); //returns value in activity array, true if registered false if not
}

void print(fstream& families, int id) {

	if ((id < 1) || (id > 100)) throw "ERROR: Invalid family number\n";

	bool famExists = checkID(families, id); //checking if id exists
	if (!famExists) throw "ERROR: Family is not in the file\n"; //id found in database so already exists

	families.seekg((id - 1) * sizeof(Family), ios::beg); //getting to right place in file to read record
	Family f;
	families.read((char*)&f, sizeof(Family)); //reading info at that place in database to a temp object
	f.print(); //calling print function for object
	cout << endl;
}

void inClass(fstream& families, int act) {

	if ((act < 1) || (act > 6)) throw "ERROR: Invalid class number\n";

	families.seekg(0, ios::beg); //getting to right place in file to read record
	for (int i = 0; i < 100; i++) {
		Family f;
		families.read((char*)&f, sizeof(Family)); //reading info at that place in database to a temp object

		if (f.getAct(act - 1)) { //checking value of activities array at correct activity index, want true values
			cout << f.getName() << " "; //printing name of family
		}
	}
	cout << endl;
}


bool checkID(fstream& families, int id) {
	
	families.seekg((id - 1) * sizeof(Family), ios::beg); //getting to right place in file to read record
	Family f;
	families.read((char*)&f, sizeof(Family)); //reading info at that place in database to a temp object

	return (id == f.getID()); //returns if ids are the same (if doesn't exist will be 0)
}

bool checkActs(fstream& families, int act) {
	int ctr = 0;
	Family f;
	bool check;

	families.seekg(0, ios::beg); //setting file to beg to read through each one
	for (int i = 0; i < 100; i++) {
		families.read((char*)&f, sizeof(Family));
		check = f.getAct(act - 1); //checking if family is registered for that activity
		if (check) {
			ctr += f.getMems(); //counting amount of people registered
		}
	}
	return (ctr >= 10); //returns true if 10 or more families registered for a specific activity
}

