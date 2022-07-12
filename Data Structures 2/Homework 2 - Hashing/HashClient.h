#ifndef HASHCLIENT_H
#define HASHCLIENT_H

#include "HashOpenAdd.h"
#include "Client.h"

class HashClient : public HashOpenAdd<Client, int>
{
public:
    HashClient(int size);
    int h1(int key);
    int h2(int Key);
};

#endif // !HASHCLIENT_H



