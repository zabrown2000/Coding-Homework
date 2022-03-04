/*Zahava Brown, TZ: 346287956
Course: Workshop in C++
Exercise 1 Question 2
This program will define a class and its methods*/

#pragma once
class Employees {
	//private by default
	int m_ssid;
	char m_name[21];
	float m_wage;
	int m_hours;
	float m_collMoney;

public:
	//setter methods
	void setSsid();
	void setName();        
	void setWage();        
	void setHours();       
	void setCollMoney();
	void setCollMoneyParm(float collMoney);

	//getter methods
	int getSsid();
	char* getName();
	float getWage();
	int getHours();
	float getCollMoney();

	float calcSalary(); //function to calculate the total salary of an employee, including the bonus

private:
	//function can only be accesed by above functions, not in main
	float calcBonus(float wages);
};

