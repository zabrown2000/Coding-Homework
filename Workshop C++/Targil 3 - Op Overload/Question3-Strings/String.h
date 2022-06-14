/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 3
This program will define a class String and its mehtods*/

#ifndef STRING_H
#define STRING_H

class String {

	int m_length;
	char* m_array;

public:
	//getter methods
	char* getArray() const; //getter method for string itself
	int getLength() const; //getter method for length of string

	//constructors
	String(); //default constructor
	String(const char* str); //constructor
	~String(); //destructor 
	String(const String& s); //copy constructor
	//String(String&& s); //move constructor
	                                            //moodle won't compile with the move methods
	//String& operator=(String&& s); //move assignment operator overload method
	String& operator=(const String& s); //assignment operator overload method
	bool operator<(const String& s) const; //less than operation overload method
	bool operator<=(const String& s) const; //less than or equal operation overload method
	bool operator>(const String& s) const; //greater than operation overload method
	bool operator>=(const String& s) const; //greater than or equal operation overload method
	bool operator!=(const String& s) const; //not equal operation overload method
	bool operator==(const String& s) const; //is equal operation overload method
	char& operator[](int index); //bracket operation overload method

	String insert(int index, const char* str); //method to insert 1 string into another at a given index

	void print(); //method to print array in string class

private:
	//below methods can only be used by above methods
	void setString(const char* str); //helper method to do a deep copy
	//char* toLower(char* word); //method to make all letters in a string lowercase
};

#endif // !STRING_H
