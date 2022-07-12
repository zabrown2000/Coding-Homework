#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include <string>
#include <iostream>
using namespace std;

class Volunteer
{
private:
    string homeAddress;
    int phoneNumber; //ignore leading 0 for number-9 digits
    string cityName;

public:
    string name;

    Volunteer();
    Volunteer(string n, string h, int p, string c);
    ~Volunteer();
    Volunteer& operator=(const Volunteer& v);
    bool operator==(const Volunteer& v);

    friend istream& operator>>(istream& is, Volunteer& v);
    friend ostream& operator<<(ostream& os, Volunteer& v);
};

#endif // !VOLUNTEER_H




