/*****************************************************************//**
 * \file   main.cpp
 * \brief Program to implement a hotline using hash tables
 * 
 * \author Zahava Brown - 346287956
 * \date   March 2022
 *********************************************************************/

#include <iostream>
#include <string>
#include "Volunteer.h"
#include "Client.h"
#include "HashTbls.h"
#include "Hashint.h"
using namespace std;

///////


void main()
{
	//Hashint h(10);
	////22, 1, 13, 11, 24, 33, 18, 42, 31
	//int returnVal;
	//returnVal = h.insertEntry(22, 22);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(1,1);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(13,13);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(11,11);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(24,24);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(33,33);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(18,18);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(42,42);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();
	//returnVal = h.insertEntry(31,31);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();

	//int index = h.searchKey(11);
	//if (index != 4) cout << "error with search\n"; 

	//h.deleteEntry(33);
	//h.printTable();

	//h.insertEntry(19, 19);
	//if (returnVal == -1) cout << "table is full\n";
	//h.printTable();

	char ch;
	Volunteer v;
	Client c;
	list<Volunteer*> lst;
	HashTbls ht;

		cout << "Hash Tables\n";
	do
	{
		cout << "\nChoose one of the following" << endl;
		cout << "n: New volunteer" << endl;
		cout << "d: Del a volunteer " << endl;
		cout << "c: New client" << endl;
		cout << "l: Add a connection volunteer-client " << endl;
		cout << "*: Print volunteers that helped a client " << endl;
		cout << "i: Print clients that were helped by a voluneer " << endl;
		cin >> ch;
		switch (ch)
		{
		case 'n':cin >> v; ht.addVolunteer(v);  break;
		case 'd':cin >> v.name; ht.delVolunteer(v);  break;
		case 'c': cin >> c; ht.addClient(c); break;
		case 'l': cout << "enter volunteer name and client phone ";  cin >> v.name >> c.phoneNumber; ht.addVolunteerToClient(v, c); break;
		case '*': cout << "enter client phone ";  cin >> c.phoneNumber; ht.listOfVolunteers(c); break;
		case 'i': cout << "enter volunteer name ";  cin >> v.name; ht.listOfClients(v); break;
		case 'e':cout << "bye "; break;
		default: cout << "Error ";  break;
		}
	} while (ch != 'e');
}
