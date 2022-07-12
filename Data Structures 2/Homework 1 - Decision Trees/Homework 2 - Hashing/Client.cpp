#include "Client.h"

Client::Client() : homeAddress(""), phoneNumber(0), name("") {}

Client::Client(string n, string h, int p)
{
    this->name = n;
    this->homeAddress = h;
    this->phoneNumber = p;
}

Client::~Client()
{}

Client& Client::operator=(const Client& c)
{
    if (&c != this)
    {
        this->name = c.name;
        this->homeAddress = c.homeAddress;
        this->phoneNumber = c.phoneNumber;
        this->responders = c.responders;
    }
    return *this;
}

bool Client::operator==(const Client& c)
{
    return (this->name == c.name) ? true : false;
}

istream& operator>>(istream& is, Client& c)
{
    is >> c.name >> c.phoneNumber >> c.homeAddress; //need to fix, can read whole line as one string
    cout << "Please enter amount of volunteer responders\n";
    int size = 0;
    cin >> size;
    cout << "Enter the details for " << size << " volunteers:\n";
    for (int i = 0; i < size; i++)
    {
        Volunteer v;
        is >> v;
        c.responders.push_back(v);
    }
    return is;
}

ostream& operator<<(ostream& os, Client& c)
{
    os << "Client Name: " << c.name << "\nAddress: " << c.homeAddress << "\nPhone Number: " << c.phoneNumber << endl;
    for (auto i = c.responders.begin(); i != c.responders.end(); i++)
    {
        os << (*i);
    }
    return os;
}
