#ifndef HASHVOLUNTEER_H
#define HASHVOLUNTEER_H

#include "HashOpenAdd.h"
#include "Volunteer.h"

class HashVolunteer : public HashOpenAdd<Volunteer, string>
{
public:
    HashVolunteer(int size);
    int h1(string key);
    int h2(string key);
};

#endif // !HASHVOLUNTEER_H

/*Define a class to represent a hash table (which inherits from the class
hash<volunteer,string> defined in Stage 1), which contains all the volunteers , and for
which the key is of type string (the volunteer name). Redefine only those functions for
which this is necessary.
*/

