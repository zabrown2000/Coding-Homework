#ifndef HASHTBLS_H
#define HASHTBLS_H

#include "HashClient.h"
#include "HashVolunteer.h"

class HashTbls
{
private:
    HashClient clientTable;
    HashVolunteer volunteerTable;

public:
    HashTbls(); 
    void addVolunteer(Volunteer newV);
    void addClient(Client newC);
    void addVolunteerToClient(Volunteer v, Client c);
    void delVolunteer(Volunteer v);
    void delClient(Client c);
    void listOfVolunteers(Client c);
    void listOfClients(Volunteer v);
    void printTables();
};

#endif // !HASHTBLS_H

/*Define a class to represent the entire repository.
The members of this class should be:
• A hash table for the volunteers, by volunteer name
• A hash table for the clients, by caller phone number

The methods of the class should enable:
• Initializing both hash tables to size 100, each
• Adding/deleting a volunteer     
• Adding/deleting a new caller    
• Adding a volunteer as a responder to a call (must first verify that the volunteer exists in the repository)
• Given a caller, print the names of the volunteers who responded to him (including
volunteers who are no longer in the repository, without duplicates)
• Given a volunteer (lots of iteraring, go over whole tree), print the names of the callers to which he responded (this is an
expensive operation, which requires going over all the callers. A bonus will be given if     --maybe sort?
the implementation is changed to allow for greater efficiency of this operation).  --if a client has this vol in list, add to result
• Printing the callers' table and the volunteers' table. Make sure all volunteer details
and all caller details are printed (the print function will be checked only by the manual
checker, and not by the automatic checker).*/

