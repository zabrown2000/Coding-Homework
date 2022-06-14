/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 4 Question 1
This program will implement a class Account and its methods*/

#include "Account.h"
//using namespace std;

//initializing static variables
int Account::sumDeposit = 0;
int Account::sumWithdraw = 0;

/// <summary>
/// default ctor
/// </summary>
Account::Account() {
	m_accountNumber = 0;                        
	m_code = 0;
	m_balance = 0;
	m_email = "";
}

/// <summary>
/// ctor that accepts parameters
/// </summary>
/// <param name="accNum">int</param>
/// <param name="code">int</param>
/// <param name="bal">float</param>
/// <param name="mail">string</param>
Account::Account(int accNum, int code, float bal, string mail) {
	
	m_accountNumber = accNum;
	m_code = code;
	m_balance = bal;
	m_email = mail;
}

/// <summary>
/// setter method for balance field
/// </summary>
/// <param name="bal">float</param>
void Account::setBal(float bal) {
	m_balance = bal;
}

/// <summary>
/// setter method for email field
/// </summary>
/// <param name="mail">string</param>
void Account::setMail(string mail) {
	try {
		int index;
		index = mail.find('@'); //checking if the email contains an @ symbol
		if (index == -1) throw string("wrong email!"); //exit code from find function if char not found
		
		if ((mail.find(".com", index) == -1) || (mail.find(".co.il", index) == -1)) { //checking if the email ends in either .com or .co.il
			throw string("wrong email!");
		}
		m_email = mail; //got to this point, no problems so set m_email
	} 
	catch (string s) { //catching the string exception and printing it
		cout << s << endl;
		return;
	}
}

/// <summary>
/// getter method for account number field
/// </summary>
/// <returns>int</returns>
int Account::getAccNum() const {
	return m_accountNumber;
}

/// <summary>
/// getter method for code field
/// </summary>
/// <returns>int</returns>
int Account::getCode() const {
	return m_code;
}

/// <summary>
/// getter method for balance field
/// </summary>
/// <returns>float</returns>
float Account::getBal() const {
	return m_balance;
}

/// <summary>
/// getter method for email field
/// </summary>
/// <returns>string</returns>
string Account::getMail() const {
	return m_email;
}

/// <summary>
/// method to withdraw a given amount of money from an account
/// </summary>
/// <param name="nis">int</param>
void Account::withdraw(int nis, Clock c) {
	
	if ((m_balance - nis) < -6000) throw 6000; //when user oversteps overdraft limits

	if (nis > 2500) throw 2500; //when user tries to withdraw more than 2500 nis
	
	m_balance -= nis; //no problems so withdrawing amount
	sumWithdraw += nis; //adding to sum of total money withdrawn
}

/// <summary>
/// method to deposit a given amount of money to an account
/// </summary>
/// <param name="nis">int</param>
void Account::deposit(int nis, Clock c) {

		if (nis > 10000) throw string("ERROR: cannot deposit more than 10000 NIS!"); //when user tries to deposit to large of an amount
	
	m_balance += nis; //no problems so depositing the amount
	sumDeposit += nis; //adding to sum of total money deposited
}

/// <summary>
/// static method to return sum of all withdraws across all accounts
/// </summary>
/// <returns>int</returns>
int Account::getSumWithdraw() {
	return sumWithdraw; 
}

/// <summary>
/// static method to return sum of all deposits across all accounts
/// </summary>
/// <returns>int</returns>
int Account::getSumDeposit() {
	return sumDeposit;
}

/// <summary>
/// friend operation overload method for cin
/// </summary>
/// <param name="is">istream&</param>
/// <param name="bank">Account</param>
/// <returns>istream&</returns>
istream& operator>>(istream& is, Account& bank) {
	
	int code;
	string mail;
	is >> bank.m_accountNumber >> code >> mail;
	//is >> bank.m_accountNumber >> bank.m_code >> bank.m_email;
	
	//int test = bank.m_code / 1000; //doing this to check if code is 4 digits
	int test = code / 1000;
	if ((test <= 0) || (test >= 10)) { //if <=0, less than 4 digits, if >=10 then more than 4 digits
		throw string("ERROR: code must be of 4 digits!");
	}
	else {
		bank.m_code = code;
	}

	//if find returns -1, substring/char not found (size_t will contain the npos which is a constant -1)
	int at = mail.find('@'); //checking if the email contains an @ symbol            
	if (at == -1) throw string("ERROR: email must contain @"); //exit code from find function if char not found
		
	int com = mail.find(".com"); //checking if email ends .com
	int il = mail.find(".co.il"); //checking if email ends .co.il
	if ((com == -1) && (il == -1)) { //checking if find() returned a position
		throw string("ERROR: email must end at .com or .co.il!");
	}
	//int index;
	//index = bank.m_email.find('@'); //checking if the email contains an @ symbol            
	//if (!(index != -1)) throw string("ERROR: email must contain @"); //exit code from find function if char not found

	////if the find function does not return -1 (npos) then substring found, so added ! to negate it
	//if (!((bank.m_email.find(".com")) != -1) && !(bank.m_email.find(".co.il")) != -1) { //checking if the email ends in either .com or .co.il
	//	throw string("ERROR: email must end at .com or .co.il!");
	//}
	else {
		bank.m_email = mail;
	}

	bank.m_balance = 0;
	return is;
}


