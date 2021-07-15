/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 11 Question 1
This program will define a class Family and its methods*/

#ifndef FAMILY_H
#define FAMILY_H

#include <string>

class Family {

	int m_id;
	char m_lastName[20];
	int m_members;
	int m_phone;
	bool m_activities[6];

public:
	Family(int id = 0, char* last = nullptr, int mems = 0, int phone = 0, bool* acts = nullptr);

	//setters and getters
	void setID(int id);
	void setName(char* name);
	void setMems(int members);
	void setPhone(int phone);
	void setAct(int act, bool choice);
	void setActs(bool* acts);
	int getID() const;
	std::string getName() const;
	int getMems() const;
	int getPhone() const;
	bool getAct(int i) const;

	void print(); //method to print info of a family

};


#endif // !FAMILY_H

/*a.	family id (int) – in the range 1-100 (this is the key of the record)
b.	last name (up to 20 chars)
c.	number of family members
d.	phone number (int)
e.	a Boolean array for each of the 6 activities offered in the neighborhood. A value true in the array 
	indicates if at least one child in the family is registered for the activity, otherwise it is false.

	ctor - checks id btw 1-100, sets all values of array to false
*/
