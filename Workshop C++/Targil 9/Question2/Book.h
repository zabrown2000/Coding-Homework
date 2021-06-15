/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 9 Question 2
This program will define a class Book and its methods*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
	int m_bookNum;
	string m_authorName;
	string m_bookName;

public:
	//constructors
	Book(int bookNum = 0, string authName = "", string bookName = ""); //ctor
	Book(const Book& book); //copy ctor

	//oporator overload methods
	bool operator<(const Book& book) const;
	bool operator<=(const Book& book) const;
	bool operator>(const Book& book) const;
	bool operator>=(const Book& book) const;
	bool operator==(const Book& book) const;
	bool operator!=(const Book& book) const;
	friend istream& operator>>(istream& is, Book& book);
	friend ostream& operator<<(ostream& os, const Book& book);

};

#endif // !BOOK_H



