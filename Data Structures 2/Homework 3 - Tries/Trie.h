#ifndef TRIE_H 
#define TRIE_H 

#include <string>

class Trie
{
private:
    class TrieNode
    {
    public:
        TrieNode* children[27] = { nullptr };
        bool endOfWord;
        TrieNode* parent;

        TrieNode();
    };

    TrieNode* root;

    int getIndex(char c);
    bool isOnlyChild(Trie::TrieNode* parent, int index);
    bool isLeaf(Trie::TrieNode* node);
    Trie::TrieNode* delRec(Trie::TrieNode* currentNode, std::string word, int depth = 0);
    int autoSuggRec(Trie::TrieNode* currentNode, std::string currentPrefix);

public:
    Trie();
    void insert(std::string newWord);
    bool del(std::string word);
    bool search(std::string word);
    int printAutoSuggestions(std::string prefix);
};

#endif // !TRIE_H 



