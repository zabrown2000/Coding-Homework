#include "Volunteer.h"

Volunteer::Volunteer() : homeAddress(""), phoneNumber(0), cityName(""), name("") {}

Volunteer::Volunteer(string n, string h, int p, string c)
{
    this->name = n;
    this->homeAddress = h;
    this->phoneNumber = p;
    this->cityName = c;
}

Volunteer::~Volunteer()
{}

/**
 * Assignment operator overload function.
 * 
 * \param v Volunteer to take info from
 * \return current volunteer with new values.
 */
Volunteer& Volunteer::operator=(const Volunteer& v)
{
    if (&v != this)
    {
        this->name = v.name;
        this->homeAddress = v.homeAddress;
        this->phoneNumber = v.phoneNumber;
        this->cityName = v.cityName;
    }
    return *this;
}

/**
 * Function to compare 2 volunteers based on name.
 * 
 * \param v volunteer to compare with current object
 * \return true or false
 */
bool Volunteer::operator==(const Volunteer& v)
{
    return (this->name == v.name) ? true : false;
}

/**
 * Input operator overload function.
 * 
 * \param is input stream variable
 * \param v volunteer to put input data
 * \return the input stream
 */
istream& operator>>(istream& is, Volunteer& v)
{
    is >> v.name >> v.phoneNumber >> v.homeAddress >> v.cityName; //need to fix, can read whole line as one string
    return is;
}

/**
 * Output operator overload function.
 * 
 * \param os output stream variable
 * \param v volunteer to output data from
 * \return the output stream
 */
ostream& operator<<(ostream& os, Volunteer& v)
{
    os << "Volunteer Name: " << v.name << "\nAddress: " << v.homeAddress << " " << v.cityName << "\nPhone Number: " << v.phoneNumber << endl;
    return os;
}
