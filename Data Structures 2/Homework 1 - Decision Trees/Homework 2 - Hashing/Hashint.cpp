#include "Hashint.h"

Hashint::Hashint(int userSize) : HashOpenAdd(size) {}

int Hashint::h1(int key) 
{
    return (key % this->size);
}


int Hashint::h2(int key) 
{
    return 1 + (key % (this->size - 1));
}
