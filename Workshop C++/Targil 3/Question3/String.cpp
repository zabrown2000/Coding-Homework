/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 3 Question 3
This program will implement a class String and its mehtods*/

#include "String.h"
#include<cstring>
#include<iostream>
using namespace std;
#pragma warning (disable:4996)

/// <summary>
/// getter method for array field
/// </summary>
/// <returns>char*</returns>
char* String::getArray() const {
	return m_array;
}

/// <summary>
/// getter method for length field
/// </summary>
/// <returns>int</returns>
int String::getLength() const {
	return m_length;
}

/// <summary>
/// default constructor
/// </summary>
String::String() {//: String("") {} //sending empty array to initialize string to NULL, it calls regular ctor which calls setString
	this->setString("");    //moodle won't compile with colon-initialization
}

/// <summary>
/// constructor
/// </summary>
/// <param name="str">const char*</param>
String::String(const char* str) {
	setString(str); //str will be copied to array field and length field will be given a value
}

/// <summary>
/// destructor
/// </summary>
String::~String() {
	if (m_array != NULL) { //don't want to delete if there's nothing there
		delete[] m_array;
		m_array = NULL; //to avoid floating pointer
	}
}

/// <summary>
/// copy constructor
/// </summary>
/// <param name="s">const cbr String</param>
String::String(const String& s) {//: String(s.m_array) {} //calling regular ctor which calls setString to do a deep copy
	this->setString(s.m_array);
}
///// <summary>
///// move constructor
///// </summary>
///// <param name="s">String&&</param>
//String::String(String&& s) { 
//	m_array = s.m_array; //"stealing" what s's array points to instead of copying
//	m_length = s.m_length; //needs new value for new array that object contains
//	s.m_array = NULL; //now as if moved over the string array to current object from sent object
//}
//
///// <summary>
///// move assignment operator overload method
///// </summary>
///// <param name="s">String&&</param>
///// <returns>String&</returns>
//String& String::operator=(String&& s) {
//	
//	if (m_array) { //only want to delete if points to something
//		delete[] m_array;
//	}
//	m_array = s.m_array; //moving over array from sent object
//	s.m_array = NULL;
//
//	return *this;
//}

/// <summary>
/// assignment operator overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>String&</returns>
String& String::operator=(const String& s) {
	
	if (&s != this) { //no need to copy over information if the sent object is same as called object
		setString(s.m_array); //sending array over to create a new string with same info
	}
	return *this; //utilizing x=y=z
}

/// <summary>
/// less than operation overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>bool</returns>
bool String::operator<(const String& s) const {
	
	//char* temp1 = toLower(m_array); //making strings lowercase so can compare them without worrying about case
	//char* temp2 = toLower(s.m_array);
	return (strcmp(m_array, s.m_array) < 0); //calling strcmp and if it returns <0 then first string comes before first and will return true
}

/// <summary>
/// less than or equal operation overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>bool</returns>
bool String::operator<=(const String& s) const {
	
	//char* temp1 = toLower(m_array); //making strings lowercase so can compare them without worrying about case
	//char* temp2 = toLower(s.m_array);
	//calling strcmp and if it returns <0 or 0 then first string comes before second or they are equal and will return true
	return ((strcmp(m_array, s.m_array) < 0) || (strcmp(m_array, s.m_array) == 0));
}

/// <summary>
/// greater than operation overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>bool</returns>
bool String::operator>(const String& s) const {
	
	//char* temp1 = toLower(m_array); //making strings lowercase so can compare them without worrying about case
	//char* temp2 = toLower(s.m_array);
	return (strcmp(m_array, s.m_array) > 0); //calling strcmp and if it returns >0 then first string comes after first and will return true
}

/// <summary>
/// greater than or equal operation overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>bool</returns>
bool String::operator>=(const String& s) const {
	
	//char* temp1 = toLower(m_array); //making strings lowercase so can compare them without worrying about case
	//char* temp2 = toLower(s.m_array);
	//calling strcmp and if it returns >0 or 0 then first string comes after second or they are equal and will return true
	return ((strcmp(m_array, s.m_array) > 0) || (strcmp(m_array, s.m_array) == 0));
}

/// <summary>
/// not equal operation overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>bool</returns>
bool String::operator!=(const String& s) const {
	
	//char* temp1 = toLower(m_array); //making strings lowercase so can compare them without worrying about case
	//char* temp2 = toLower(s.m_array);
	return (strcmp(m_array, s.m_array) != 0); //calling strcmp, and if returns any value other than 0, strings not same and will return true
}

/// <summary>
/// is equal operation overload method
/// </summary>
/// <param name="s">const cbr String</param>
/// <returns>bool</returns>
bool String::operator==(const String& s) const {
	
	//char* temp1 = toLower(m_array); //making strings lowercase so can compare them without worrying about case
	//char* temp2 = toLower(s.m_array);
	return (strcmp(m_array, s.m_array) == 0); //calling strcmp, and if returns 0 strings are same and will return true
}

/// <summary>
/// bracket operation overload method
/// </summary>
/// <param name="index">int</param>
/// <returns>char&</returns>
char& String::operator[](int index) {
	
	if ((index < 0) || (index > m_length)) //if user sent index out of range
		; //throws exception
	return m_array[index]; //will return address of this spot
}

/// <summary>
/// method to insert 1 string into another at a given index
/// </summary>
/// <param name="index">int</param>
/// <param name="str">const char*</param>
/// <returns>String</returns>
String String::insert(int index, const char* str) {
	
	if ((index < 0) || (index > m_length)) { //if user sent index out of range will return empty string
		cout << "ERROR\n";
		return String();
	}
	int strLen = strlen(str); //getting length of string passed to function
	String newStr;
	newStr.m_length = (m_length + strLen); //making new length sum of 2 strings
	newStr.m_array = new char[newStr.m_length + 1];

	strncpy(newStr.m_array, m_array, index); //copying over elements from first string until index where will insert
	newStr.m_array[index] = '\0'; //putting null at end so can concatenate second string
	strcat(newStr.m_array, str); //inserting second string at desired place
	char* s = m_array + index; //getting location of where left off in string 1 
	strcat(newStr.m_array, s); //tacking the rest of string 1 to end of new string

	return newStr;
}

/// <summary>
/// method to print array in string class
/// </summary>
void String::print() {
	cout << m_array << endl;
}


/// <summary>
/// helper method to do a deep copy
/// </summary>
/// <param name="str">const char*</param>
void String::setString(const char* str) {
	
	if (str == NULL) //needed since strlen no longer checks for null
		str = "";

	m_length = strlen(str); //getting length of current array
	m_array = new char[m_length + 1]; //creating new array of same size as sent string
	//strcpy_s(m_array, m_length + 1, str); //copyng elements over to new array
	strcpy(m_array, str);
}

///// <summary>
///// method to make all letters in a string lowercase
///// </summary>
///// <param name="word">char*</param>
///// <returns>char*</returns>
//char* String::toLower(char* word) {
//	
//	for (int i = 0; i < strlen(word); i++) {
//		if ((word[i] >= 65) && (word[i] <= 92)) { //checking each letter to see if ascii value in range of uppercase letters
//			word[i] = word[i] + 32; //97 - 65 = 32
//		}
//	}
//	return word;
//}
