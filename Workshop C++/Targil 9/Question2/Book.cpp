/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 2
This program will implement a class Book and its methods*/

#include "Book.h"


/// <summary>
/// ctor for Book class
/// </summary>
/// <param name="bookNum">int</param>
/// <param name="authName">string</param>
/// <param name="bookName">string</param>
Book::Book(int bookNum, string authName, string bookName) : m_bookNum(bookNum), m_authorName(authName), m_bookName(bookName){}

/// <summary>
/// copy ctor for Book class
/// </summary>
/// <param name="book">const Book&</param>
Book::Book(const Book& book) : m_bookNum(book.m_bookNum), m_authorName(book.m_authorName), m_bookName(book.m_bookName) {}

/// <summary>
/// operator overload method for less than
/// </summary>
/// <param name="book">const Book&</param>
/// <returns>bool</returns>
bool Book::operator<(const Book& book) const { 
	
	if (this->m_authorName != book.m_authorName) {
		return (this->m_authorName < book.m_authorName);
	}
	else if (this->m_bookName != book.m_bookName) { //author names equal so check book names
		return (this->m_bookName < book.m_bookName);
	}
	else { //book names equal so check book numbers
		return (this->m_bookNum < book.m_bookNum);
	}
}

/// <summary>
/// operator overload method for less than or equal to
/// </summary>
/// <param name="book">const Book&</param>
/// <returns>bool</returns>
bool Book::operator<=(const Book& book) const {
	return (this->m_authorName <= book.m_authorName); //don't need to go down list because names can be =
}

/// <summary>
/// operator overload method for greater than
/// </summary>
/// <param name="book">const Book&</param>
/// <returns>bool</returns>
bool Book::operator>(const Book& book) const {
	
	if (this->m_authorName != book.m_authorName) {
		return (this->m_authorName > book.m_authorName);
	}
	else if (this->m_bookName != book.m_bookName) { //author names equal so check book names
		return (this->m_bookName > book.m_bookName);
	}
	else { //book names equal so check book numbers
		return (this->m_bookNum > book.m_bookNum);
	}
}

/// <summary>
/// operator overload method for greater than or equal to
/// </summary>
/// <param name="book">const Book&</param>
/// <returns>bool</returns>
bool Book::operator>=(const Book& book) const {
	return (this->m_authorName >= book.m_authorName); //don't need to go down list because names can be =
}

/// <summary>
/// operator overload method for equal to
/// </summary>
/// <param name="book">const Book&</param>
/// <returns>bool</returns>
bool Book::operator==(const Book& book) const {
	
	//will go through each field, if just 1 set isn't equal will return false
	if (this->m_authorName != book.m_authorName) {
		return false;
	}
	if (this->m_bookName != book.m_bookName) {
		return false;
	}
	if (this->m_bookNum != book.m_bookNum) {
		return false;
	}
	return true; //if got to this point that means all fields are equal
}

bool Book::operator!=(const Book& book) const {
	
	//will go through each field, if just 1 set is equal will return false
	if (this->m_authorName == book.m_authorName) {
		return false;
	}
	if (this->m_bookName == book.m_bookName) {
		return false;
	}
	if (this->m_bookNum == book.m_bookNum) {
		return false;
	}
	return true; //if got to this point that means all fields are not equal
}

/// <summary>
/// operator overload method for >>
/// </summary>
/// <param name="is"><istream&/param>
/// <param name="book">Book&</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, Book& book) {
	
	is >> book.m_bookNum >> book.m_authorName >> book.m_bookName;
	return is;
}

/// <summary>
/// operator overload method for <<
/// </summary>
/// <param name="os">ostream&</param>
/// <param name="book">const Book&</param>
/// <returns>ostream&</returns>
ostream& operator<<(ostream& os, const Book& book) {
	
	os << book.m_bookNum << " " << book.m_authorName << " " << book.m_bookName << endl;
	return os;
}

