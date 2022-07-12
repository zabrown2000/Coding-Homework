#include "HashTbls.h"


HashTbls::HashTbls() : clientTable(100), volunteerTable(100) {}

/**
 * Function to add a volunteer to the volunteer database.
 * 
 * \param newV volunteer to add
 */
void HashTbls::addVolunteer(Volunteer newV)
{
    int existsIndex = this->volunteerTable.searchKey(newV.name); //first checking if volunteer already in table
    if (existsIndex != -1)
    {
        int insertIndex = this->volunteerTable.insertEntry(newV, newV.name);
        if (insertIndex == -1) cout << "ERROR\n"; //table full, couldn't add
    }
}

/**
 * Function to add a client to the client database.
 * 
 * \param newC client to add
 */
void HashTbls::addClient(Client newC) //sent client, so assuming list of vols already there
{
    int existsIndex = this->clientTable.searchKey(newC.phoneNumber); //first checking if client already in table
    if (existsIndex != -1)
    {
        int insertIndex = this->clientTable.insertEntry(newC, newC.phoneNumber);
        if (insertIndex == -1) cout << "ERROR\n"; //table full, couldn't add
    }
}

/**
 * Function to add a volunteer as a responder to a client.
 * 
 * \param v volunteer to add
 * \param c client adding to
 */
void HashTbls::addVolunteerToClient(Volunteer v, Client c)
{
    //need to check client is in table and then copy over data
    int existsIndex = this->clientTable.searchKey(c.phoneNumber);
    if (existsIndex == -1)
    {
        cout << "ERROR\n"; //no client to add volunteer to, can't add client because main only sends client with key intialized
        return;
    }
    //c = this->clientTable.getItem(existsIndex);
    c = this->clientTable.table[existsIndex].data;

    //need to check if volunteer exists in table and then copy over data
    existsIndex = this->volunteerTable.searchKey(v.name);
    if (existsIndex == -1)
    {
        cout << "ERROR\n"; //can't add to table to only sent volunteer with key initialized (see main)
        return;
    }
    //v = this->volunteerTable.getItem(existsIndex); //getting rest of info for volunteer to compare below
    v = this->volunteerTable.table[existsIndex].data;

    //need to search for volunteer in client's list of responders
    for (auto i = c.responders.begin(); i != c.responders.end(); i++)
    {
        if ((*i) == v) return; //already there, can leave function
    }
    c.responders.push_back(v);
}

/**
 * Function to delete a volunteer from the database.
 * 
 * \param v volunteer to delete
 */
void HashTbls::delVolunteer(Volunteer v)
{
    this->volunteerTable.deleteEntry(v.name);
    //not deleting from client list because will need the info still in a later function
}

/**
 * Function to delete a client from the database.
 * 
 * \param c client to delete
 */
void HashTbls::delClient(Client c)
{
    this->clientTable.deleteEntry(c.phoneNumber);
}

/**
 * Function to get all the volunteers that responded to a given client.
 * 
 * \param c client to access
 */
void HashTbls::listOfVolunteers(Client c)
{
    int existsIndex = this->clientTable.searchKey(c.phoneNumber);
    if (existsIndex == -1)
    {
        cout << "ERROR\n";
    }
    else
    {
       // c = this->clientTable.getItem(existsIndex); //function only being sent a client with key info filled in, need to get the current list of responders
        c = this->clientTable.table[existsIndex].data;
        for (auto i = c.responders.begin(); i != c.responders.end(); i++)
        {
            cout << (*i);
        }
    }
}

/**
 * Function to print all clients a volunteer responds to.
 * 
 * \param v volunteer to check clients on
 */
void HashTbls::listOfClients(Volunteer v)
{
    //need to check if volunteer exists in table and then copy over data
    int existsIndex = this->volunteerTable.searchKey(v.name);
    if (existsIndex == -1)
    {
        cout << "ERROR\n"; //can't add to table, only sent volunteer with key initialized (see main)
        return;
    }
    //v = this->volunteerTable.getItem(existsIndex); //getting rest of info for volunteer to compare below
    v = this->volunteerTable.table[existsIndex].data;

    //loop through each client
    //loop through vol list, if vol is there print that client
    for (int i = 0; i < this->clientTable.size; i++)
    {
        for (auto j = this->clientTable.table[i].data.responders.begin(); j != this->clientTable.table[i].data.responders.end(); j++)
        {
            if ((*j) == v)
            {
                cout << this->clientTable.table[i].data;
                break; //leaves to check inside next client
            }
        }
    }
}

/**
 * Function to print contents of both tables.
 * 
 */
void HashTbls::printTables()
{
   //volunteers
    cout << "List of volunteers\n";
    for (int i = 0; i < this->volunteerTable.size; i++)
    {
        if (this->volunteerTable.table[i].flag = HashOpenAdd<Volunteer, string>::state::full) //only printing items from table that contain data
        {
            cout << this->volunteerTable.table[i].data;
        }
    }

    //clients
    cout << "List of clients\n";
    for (int i = 0; i < this->clientTable.size; i++)
    {
        if (this->clientTable.table[i].flag = HashOpenAdd<Client, int>::state::full) //only printing items from table that contain data
        {
            cout << this->clientTable.table[i].data;
        }
    }
}
