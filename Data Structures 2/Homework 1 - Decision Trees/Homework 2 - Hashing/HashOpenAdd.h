#ifndef HASHOPENADD_H
#define HASHOPENADD_H                  

#include <iostream>
using namespace std;

template <class T, class K>
class HashOpenAdd
{
public:
    enum state { empty, full, deleted };
protected:
    class Item
    {
    public:
        T data;
        K key;
        state flag;
        Item() {}
        Item(T d, K k, state f) { data = d; key = k; flag = f; }
    }; //end of item class

    int findPrime(int currentSize);
    bool isPrime(int num);

public:
    HashOpenAdd<T, K>::Item* table; //made these 2 fields public to allow iterating over the table
    int size;

    HashOpenAdd() { size = 0; }
    HashOpenAdd(int currentSize);
    ~HashOpenAdd();
    virtual int h1(K key) = 0; //hash function h1 that receives a key k of type K and returns its position in the table
    virtual int h2(K key) = 0; //probe function h2 which returns the step size
    int hash(K key, int step); //function hash(k, i) that returns the position in the table of key k in step i
    int searchKey(K key); //function which searches for a key in the table : if the key is found the function returns its position in the table; otherwise it returns - 1
    int insertEntry(T entry, K key); //make it int-return position?, need key too?
    void deleteEntry(K key); //just need delete? 
    void printTable(); // function print to display the contents of the entire table
    //T getItem(int pos); //function to access specific item in hash table
};


#endif // !HASHOPENADD_H

/**
 * function to find the next lowest prime number.
 * 
 * \param currentSize number to start looking for prime numbers from
 * \return new lowest prime
 */
template <class T, class K>
int HashOpenAdd<T,K>::findPrime(int currentSize) 
{
    int lowestPrime;
    bool prime;

    do 
    { 
        prime = isPrime(currentSize);
        if (prime == true) 
        { 
            lowestPrime = currentSize;
        }
        else 
        { 
            prime = false;
            ++currentSize;
        }
    } while (prime == false); 

    return lowestPrime; 
}

/**
 * Function to check if a number is prime.
 * 
 * \param num number to check
 * \return true or false
 */
template<class T, class K>
bool HashOpenAdd<T, K>::isPrime(int num)
{
    bool prime = false;
	
	if (num == 1 || num == 2) 
    { 
		prime = true;
	}
	else 
    { 
		for (int i = 2; i < num; i++) 
        { 
			if (num % i == 0) 
            { 
				prime = false; 
				break; 
			}
			else 
            {
				prime = true; 
			}
		}
	}
	return prime; 
}

template <class T, class K>
HashOpenAdd<T, K>::HashOpenAdd(int currentSize)
{
    this->size = findPrime(currentSize);
    this->table = new Item[this->size];

    for (int i = 0; i < this->size; i++)
    {
        this->table[i].flag = empty;
    }
}

template <class T, class K>
HashOpenAdd<T, K>::~HashOpenAdd()
{
    if (!this->table)
    {
        delete this->table;
    }
}

/**
 * double hashing has function.
 * 
 * \param key key of item to put in table
 * \param step step size of hash function
 * \return position in table for key
 */
template<class T, class K>
int HashOpenAdd<T, K>::hash(K key, int step) 
{
    //(h1(k) + i*h2(k))mod size
    int hashReturn = h1(key) + (step * h2(key));
    return hashReturn % this->size;
}

/**
 * Function to search for a given key in a hash table.
 * 
 * \param key key to search for
 * \return index of key in hash table
 */
template<class T, class K>
int HashOpenAdd<T, K>::searchKey(K key)
{
    int j, i = 0;
    do
    {
        j = hash(key, i);
        if ((this->table[j].state == full) && (this->table[j].key == key)) //checking state as well to accomodate delete function
        {
            return j;
        }
        ++i;
    } while ((this->table[j].state != empty) || (i == this->size));
    return -1; //key not found
}

/**
 * Function to insert an element into a hash table.
 * 
 * \param entry data for item to insert
 * \param key key of item to insert
 */
template<class T, class K>
int HashOpenAdd<T, K>::insertEntry(T entry, K key)
{
    int j, i = 0;

    do
    {
        j = hash(key, i);
        if ((this->table[j].state == empty) || (this->table[j].state == deleted))
        {
            this->table[j].data = entry;
            this->table[j].key = key;
            this->table[j].state = full;
            return j;
        }
        else
        {
            ++i;
        }
    } while (i < this->size);
    return -1; //table is full
}

/**
 * Function to delete an entry from a hash table.
 * 
 * \param key key for item to delete
 */
template<class T, class K>
void HashOpenAdd<T, K>::deleteEntry(K key)
{
    int pos = this->searchKey(key);
    if (pos != -1)
    {
        this->table[pos].state = deleted;
    }
}

/**
 * Function to print contents of a hash table.
 * 
 */
template<class T, class K>
void HashOpenAdd<T, K>::printTable()
{
    cout << "Index\t Key\t Data\t" << endl;

    for (int i = 0; i < this->size; i++)
    {
        if (this->table[i].state == full) //only printing positions of table that hold items
        {
            cout << i << "\t" << this->table[i].key << "\t" << this->table[i].data << endl;
        }
    }
}

///**
// * Function to return item from a hash table.
// * 
// * \param pos position of item to retrieve
// * \return data of the item
// */
//template<class T, class K>
//T HashOpenAdd<T, K>::getItem(int pos)
//{
//    return this->table[pos];
//}


