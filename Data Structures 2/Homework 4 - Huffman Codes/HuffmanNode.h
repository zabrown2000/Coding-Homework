#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>

class CompareNode;
class HuffmanNode
{
private:
    std::string str;
    HuffmanNode* leftChild;
    HuffmanNode* rightChild;
    int frequency;

public:
    HuffmanNode();
    HuffmanNode(std::string text, int f, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr);
    HuffmanNode(const HuffmanNode& hNode);
    ~HuffmanNode();

    int getFrequency();
    std::string getStr();
    HuffmanNode* getLeft();
    HuffmanNode* getRight();
    HuffmanNode operator=(const HuffmanNode& hNode);

    friend class CompareNode;
};

class CompareNode
{
public:
    bool operator()(HuffmanNode* const& n1, HuffmanNode* const& n2);
};

#endif // !HUFFMANNODE_H



/*1. class HuffmanNode containing the following fields:
a. str: A string of one character or more
b. frequency: the sum of frequencies of the characters composing str
c. left: a pointer to the left child of the node
d. right: a pointer to the right child of the node
2. class CompareNode comparing 2 pointers to HuffmanNode by their
corresponding frequencies.
class compareNode{
public:
bool operator()(HuffmanNode* const & n1, HuffmanNode* const &
n2)
 {
return n1->frequency > n2->frequency;
 }
};
The definition of the priority queue will be done using:
priority_queue<HuffmanNode*, vector<HuffmanNode*>,
compareNode> pQueue;
so that the nodes will be ordered by their frequencies.
Reminder: since CompareNode uses private fields from HuffmanNode, it
should be defined inside HuffmanNode as a friend class. You may declare
these two classes in the same .h file. You must declare CompareNode before
defining HuffmanNode. For example:
class CompareNode; //Declaration
class HuffmanNode{
…..
};
class CompareNode{
….
};*/