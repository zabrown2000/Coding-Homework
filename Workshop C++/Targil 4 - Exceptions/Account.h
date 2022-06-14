/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 4 Question 1
This program will define a class Account and its methods*/

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Clock.h"
#include <string>
#include <iostream>
using namespace std;

class Account {
	int m_accountNumber;
	int m_code;
	float m_balance;
	string m_email;

	//static fields
	static int sumWithdraw; //to keep track of all withdraw transactions
	static int sumDeposit; //to keep track of all deposit transactions

public:
	//constructors
	Account(); //default ctor
	Account(int accNum, int code, float bal, string mail); //ctor

	//setters and getters
	void setBal(float bal);
	void setMail(string mail);
	int getAccNum() const;
	int getCode() const;
	float getBal() const;
	string getMail() const;
	
	void withdraw(int nis, Clock c); //method to withdraw a given amount of money from an account
	void deposit(int nis, Clock c); //method to deposit a given amount of money to an account

	//static methods
	static int getSumWithdraw(); //static method to return sum of all withdraws across all accounts
	static int getSumDeposit(); //static method to return sum of all deposits across all accounts

	//friend methods
	friend istream& operator>>(istream& is, Account &bank); //friend operation overload method for cin
};

#endif //!ACCOUNT_H
