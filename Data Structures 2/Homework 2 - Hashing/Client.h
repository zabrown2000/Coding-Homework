#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <list>
#include "Volunteer.h"
#include <iostream>
using namespace std;

class Client
{
private:
    string name;
    string homeAddress;

public:
    int phoneNumber;
    list<Volunteer> responders; //automatically initialized to empty list

    Client();
    Client(string n, string h, int p);
    ~Client();
    Client& operator=(const Client& c);
    bool operator==(const Client& c);

    friend istream& operator>>(istream& is, Client& c);
    friend ostream& operator<<(ostream& os, Client& c);
};


#endif // !CLIENT_H



/*Define a class Client in which information regarding a caller will be stored: name, phone
number, home address, and a list of volunteers who have so far responded to him
(without duplicates). The phone number of the caller will be the key (can be defined as
int, while ignoring the leading 0).
Add functions and operators to this class, as needed (<<, >>, ==, = etc.).*/
