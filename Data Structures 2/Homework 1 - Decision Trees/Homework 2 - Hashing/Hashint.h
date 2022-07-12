#ifndef HASHINT_H 
#define HASHINT_H 

#include "HashOpenAdd.h"

class Hashint : public HashOpenAdd<int, int>
{
public:
    Hashint(int userSize);
    int h1(int key);
    int h2(int key);
};

#endif // !HASHINT_H 





