#include "HashVolunteer.h"
#include <ctime>;

HashVolunteer::HashVolunteer(int size) 
{
	this->size = this->findPrime(size);
}

/**
 * initial hash function for a string key.
 * 
 * \param key key to hash
 * \return hash value
 */
int HashVolunteer::h1(string key)
{
    //looked up string hash function algorithm online
	unsigned int result = 0x7FFFFFFF;
	const static unsigned int p = 2147483659;  // smallest prime number past largest int
	srand((unsigned)time(nullptr));
	unsigned int a = rand() % (p) + 1;
	unsigned int b = rand() % p;
	for (auto i = key.begin(); i != key.end(); ++i) {
		result += (((a * (*i) + b) % p) % this->size);
	}
	return result % this->size;
}

/**
 * hash step function for a string key.
 *
 * \param key key to hash
 * \return hash value
 */
int HashVolunteer::h2(string key)
{
	int value = stoi(key);
    return 1 + (value % (this->size - 1));
}
