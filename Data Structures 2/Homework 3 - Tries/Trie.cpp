#include "Trie.h"
#include <iostream>
using namespace std;
                                                 
/**
 * default ctor for trie node.
 * NOTE: endOfWord is set to false
 */
Trie::TrieNode::TrieNode() : endOfWord(false), parent(nullptr) {}

/**
 * Function to get the index of a char in an alphabet array.
 * 
 * \param c the char
 * \return char's index
 */
int Trie::getIndex(char c)
{
    return (c - 'a' + 1);
}

/**
 * Function to check if a given node is a leaf.
 * 
 * \param node node to check
 * \return true if leaf, false if not
 */
bool Trie::isLeaf(Trie::TrieNode* node)
{
    for (int i = 1; i < 27; i++) //starting with 1 because index 0 always points to null
    {
        if (node->children[i] != nullptr)
        {
            return false;
        }
    }
    return true;
}

/**
 * Function to check if a parent has only 1 child.
 * 
 * \param parent node who's children checking
 * \param index index of current child
 * \return true if only child, false if not
 */
bool Trie::isOnlyChild(Trie::TrieNode* parent, int index)
{
    for (int i = 1; i < 27; i++) //starting with 1 because index 0 always points to null
    {
        if (i != index)
        {
            if (parent->children[i] != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * Recursive function to delete a word from a trie.
 * 
 * \param currentNode node up to in recursion
 * \param word word to delete
 * \param depth index of word up to in recursion
 * \return node of trie with deletion
 */
Trie::TrieNode* Trie::delRec(Trie::TrieNode* currentNode, string word, int depth)
{
    if (depth == word.length()) //base case, end of word
    {
        //Case 3: word is a prefix of another word - change eow to false
        if (currentNode->endOfWord)
        {
            currentNode->endOfWord = false;
        }

        //Case 2: word is not a prefix of another word (last letter is a leaf)
        if (isLeaf(currentNode))
        {
            delete currentNode;
            currentNode = nullptr;
        }

        return currentNode;
    }

    //Case 4: word shares prefix with another word - delete nodes until first node of longest common prefix
    int index = this->getIndex(word[depth]);
    currentNode->children[index] = delRec(currentNode->children[index], word, depth + 1);

    //if deleted last child of the node
    if ((isLeaf(currentNode)) && (currentNode->endOfWord == false))
    {
        delete currentNode;
        currentNode = nullptr;
    }

    return currentNode;
}

/**
 * Recursive function to print words starting with prefix.
 * 
 * \param currentNode node up to in trie
 * \param currentPrefix word up to prefix path
 * \return how many words
 */
int Trie::autoSuggRec(Trie::TrieNode* currentNode, string currentPrefix)
{
    int count = 0;

    if (currentNode->endOfWord)
    {
        cout << currentPrefix << endl;
        count++;
    }

    for (int i = 1; i < 27; i++)
    {
        if (currentNode->children[i] != nullptr)
        {
            char nextLetter = 'a' + i - 1; 
            count += autoSuggRec(currentNode->children[i], currentPrefix + nextLetter); //appending next letter to check if that's a word too
        }
    }

    return count;
}

/**
 * default ctor for trie.
 * 
 */
Trie::Trie()
{
    this->root = new TrieNode();
}

/**
 * Function to insert a word into a trie.
 * 
 * \param newWord word to insert
 */
void Trie::insert(string newWord)
{
    //Case 1: the string already exists in the database - no changes need to be made
    if (this->search(newWord) == true) return;

    if (this->root == nullptr)
    {
        this->root = new Trie::TrieNode();
    }

    int length = newWord.length();
    Trie::TrieNode* currentNode = this->root;
    bool case2 = true;
    
    

    int i;
    for (i = 0; i < length; i++)
    {
        int index = this->getIndex(newWord[i]);

        if (currentNode->children[index] != nullptr) //this might not be good either, we'll see when test
        {
            currentNode = currentNode->children[index];
        }
        else
        {
            case2 = false;
            break; //if current char in trie does not match current letter in word, not case 2
        }
    } //if made it to end of loop, got through entire word in trie, so it must be a prefix

    //Case 2: the string is a prefix of an existing string - change endOfWord flag
    if (case2)
    {
        currentNode->endOfWord = true;
        return;
    }
    else
    {
        //Case 3: the string has a common prefix with an existing string - insert extra letters of word
        //Case 4: the string has no common prefix with any existing - insert entire word

        //use i, that's letter that didn't match so start by inserting that into trie and work way down
        //if left loop at i=0, inserting whole word, otherwise only inserting part of the word (it has a common prefix)
        for (; i < length; i++)
        {
            int index = this->getIndex(newWord[i]);
            currentNode->children[index] = new Trie::TrieNode();
            currentNode->children[index]->parent = currentNode;
            currentNode = currentNode->children[index];
        }
        currentNode->endOfWord = true;
    }
    return;
}

/**
 * Function to delete a word from a trie.
 * 
 * \param word word to delete
 * \return true if word deleted, false if not
 */
bool Trie::del(string word)
{
    if (this->root == nullptr) return false;

    //Case 1: word does not exist in trie
    if (this->search(word) == false) return false;
    
    //cases 2-4
    this->root = delRec(this->root, word);
    return true;
}

/**
 * Function to search for a word in a trie.
 * 
 * \param word word to search for
 * \return true if exists, false if not
 */
bool Trie::search(string word)
{
    if (this->root == nullptr) return false;

    Trie::TrieNode* currentNode = this->root;
    int index;
    for (int i = 0; i < word.length(); i++)
    {
        index = this->getIndex(word[i]);
        if (currentNode->children[index] == nullptr)
        {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return (currentNode->endOfWord) ? true : false;
}

/**
 * Function to print all words in trie starting with prefix.
 * 
 * \param prefix prefix xhecking
 * \return number of words in trie
 */
int Trie::printAutoSuggestions(string prefix)
{
    if (isLeaf(this->root)) return 0;

    int count = 0;

    if (this->search(prefix)) //prefix itself is a word          
    {
        count++;
        cout << prefix << endl;
    }

    Trie::TrieNode* currentNode = this->root;
    for (int i = 0; i < prefix.length(); i++)
    {
        int index = this->getIndex(prefix[i]);
        currentNode = currentNode->children[index];
    }
    if (isLeaf(currentNode)) return count; //no words with this prefix or only prefix

    count += this->autoSuggRec(currentNode, prefix);
    return count;
}


