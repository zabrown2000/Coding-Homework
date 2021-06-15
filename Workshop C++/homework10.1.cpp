/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 10 Question 1
This program will perform like a database for soldiers and perform 
actions on it. STL containers and lambdas will be used.*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>                                 
#include "Private.h"
#include "Officer.h"
#include "Commander.h"

enum option {
	stop,	//	End program
	addNewSoldier,	//	Add new soldier
	medalList,	//	Print all soldiers that are entitled to a medal
	mostSociometric,	//	Most sociometric score 
	countMedalPrivate,	//	Number of private soldiers getting a medal
	noCombatCommander,	//	Names of officers not combat
	overSoldier,	//	A message for soldier participating in more than 15 operations
	removeOfficer,	//	Removing officers that did'nt participate in any operation
};

void add(vector<Soldier*>& army);    //vector or list  
//function to add a soldier to the list of soldiers
//takes in 1 parameter, vector of Soldier* by reference
//does not return a value as it changes the vector directly

void medal(vector<Soldier*> army);   //vector or list 
//function to print all the soldiers who are eligible for a medal
//takes in 1 parameter, vector of soldier*
//does not return a value

Soldier* mostSociometricScore(vector<Soldier*> army);   //vector or list
//function to find soldier with highest score
//takes in 1 parameter, vector of soldier*
//returns pointer to soldier that found

int main() {
	vector<Soldier*> army;   // define vector or list of soldiers
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	try {
		while (op != stop) {
			switch (op) {

			case addNewSoldier:
				add(army);  //add new soldier	
				break;

			case medalList:
				medal(army);  //print entitled for a medal
				break;

			case mostSociometric:
			{ Soldier* s = mostSociometricScore(army); // vector or list 
			if (!s) {
				break; //no officers in army
			}
			cout << "Officer soldier with most sociometric score: ";
			cout << s->getFirst() << ' ' << s->getLast() << endl;
			break; }

			case countMedalPrivate:
			{cout << "# private soldier for medal: "; //number of privates entitled for medal
				//count all soldiers who are of type private and are eligible for a medal
			cout << count_if(army.begin(), army.end(), [](Soldier* s) {return ((s->soldierType() == "Private") && (s->medal())); });

			cout << endl;
			break; }

			case noCombatCommander:
			{cout << "list of no combat commander soldier :";
			//for each soldier, if they are commander and not in combat, print their info
			for_each(army.begin(), army.end(), [](Soldier* s) {if (((s->soldierType() == "Commander") && !(s->getCombat()))) { cout << s->getFirst() << " " << s->getLast() << " "; } });
			cout << endl;
			break; }

			case overSoldier:
			{//searching for any soldier whose number of operations is more than 15
				if (any_of(army.begin(), army.end(), [](Soldier* s) {return (s->getOps() > 15) ? true : false; }))
					cout << "there is a soldier that takes more than 15 operations\n";
				else cout << "no soldier takes more than 15 operations\n";
				break; }

			case removeOfficer:
			{//removing a soldier if they are an officer and the amount of operations is zero
				vector<Soldier*>::iterator newEnd = remove_if(army.begin(), army.end(), [](Soldier* s) {return ((s->soldierType() == "Officer") && (s->getOps() == 0)); });
				//for each soldier, print info (new list without officers with 0 operations)    
				for_each(army.begin(), newEnd, [](Soldier* s) {s->print(); });   //still unsure on this, officer, private, all?
				break; }
			};
			cout << "enter 0-7\n";
			cin >> op;
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	
	return 0;
} 

void add(vector<Soldier*>& army) {
	int choice, id, ops;
	string first, last;

	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";
	cin >> choice;

	cout << "enter id, first name, last name and number Of operations\n";
	cin >> id >> first >> last >> ops;

	if (choice == 3) {
		cout << "enter number of sociometric score\n";
		int score;
		cin >> score;
		
		Soldier* officer = new Officer(id, first, last, ops, score); //creating new officer
		army.push_back(officer); //adding it to end of vector of soldiers
	}
	else if (choice == 2) {
		Soldier* commander = new Commander(id, first, last, ops); //creating new commander (will default for combat field)
		
		if (ops != 0) { //won't bother to ask if no operations
			cout << "enter " << ops << " grades\n"; //setting the grades
			commander->setGrades();
		}
		
		cout << "enter 1 if the soldier is combat and 0 if not\n"; //getting combat value and setting it
		int is;
		cin >> is;
		bool combat = (is == 1) ? true : false;
		commander->setCombat(combat);

		army.push_back(commander); //adding it to end of vector of soldiers
	}
	else if (choice == 1) {
		Soldier* privat = new Private(id, first, last, ops); //creating new private

		if (ops != 0) {
			cout << "enter " << ops << " grades\n"; //setting the grades
			privat->setGrades();
		}

		army.push_back(privat); //adding it to end of vector of soldiers
	}
}

void medal(vector<Soldier*> army) {

	for (vector<Soldier*>::iterator it = army.begin(); it != army.end(); ++it) { //creating iterator to go through vector
		
		if ((*it)->medal()) { //if the medal method on this particular soldier returns true, print the info
			(*it)->print();
		}
	}
}

Soldier* mostSociometricScore(vector<Soldier*> army) {

	Soldier* maxSoldier = nullptr;
	int max = 0;

	for (vector<Soldier*>::iterator it = army.begin(); it != army.end(); ++it) { //creating iterator to go through vector

		if ((*it)->soldierType() == "Officer") { //only want to check if soldier is an officer
			
			if ((*it)->getSociometric() > max) { //comparing score of current soldier in vector to max score
				max = (*it)->getSociometric(); //resetting pointer to max soldier and max score
				maxSoldier = (*it);
			}
		}
	}
	return maxSoldier; //will return null if no officers in vector
}

/*enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 3
enter 3 grades
23 56 98
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
222 bbb bbb 2
enter 2 grades
100 85
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
333 ccc ccc 16
enter number of sociometric score
98
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
444 ddd ddd 0
enter number of sociometric score
89
enter 0-7
2
officer
ID: 333
first name: ccc
last name: ccc
num operations: 16
sociometric score: 98
enter 0-7
3
Officer soldier with most sociometric score: ccc ccc
enter 0-7
4
# private soldier for medal: 0
enter 0-7
5
list of no combat commander soldier :
enter 0-7
6
there is a soldier that takes more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 23 56 98
commander
ID: 222
first name: bbb
last name: bbb
num operations: 2
grades: 100 85
combat: yes
officer
ID: 333
first name: ccc
last name: ccc
num operations: 16
sociometric score: 98
enter 0-7
0

C:\Users\zbrow\Documents\Visual Studio 2019\Projects\Homework\Homework10.1\Debug\Homework10.1.exe (process 30340) exited with code 0.
Press any key to close this window . . .
*/