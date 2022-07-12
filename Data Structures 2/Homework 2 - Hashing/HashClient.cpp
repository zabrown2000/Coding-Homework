#include "HashClient.h"

HashClient::HashClient(int size)
{
    this->size = findPrime(size);
}

int HashClient::h1(int key)
{
    return (key % this->size);
}

int HashClient::h2(int key)
{
    return 1 + (key % (this->size - 1));
}
