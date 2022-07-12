#include "HuffmanNode.h"

using namespace std;

/**
 * Helper function for using a priority queue.
 * 
 * \param n1 node #1
 * \param n2 node #2
 * \return if n1 has a higher frequency than n2
 */
bool CompareNode::operator()(HuffmanNode* const& n1, HuffmanNode* const& n2)
{
    return (n1->frequency) > (n2->frequency);
}

/**
 * Default ctor for huffman node.
 * 
 */
HuffmanNode::HuffmanNode() : str(""), leftChild(nullptr), rightChild(nullptr), frequency(0) {}

/**
 * ctor with parameters.
 * 
 */
HuffmanNode::HuffmanNode(std::string text, int f, HuffmanNode* left, HuffmanNode* right)
{
	this->str = text;
	this->frequency = f;
	this->leftChild = (left != nullptr) ? left : nullptr;
	this->rightChild = (right != nullptr) ? right : nullptr;
}

/**
 * copy ctor.
 * 
 */
HuffmanNode::HuffmanNode(const HuffmanNode& hNode)
{
	this->str = hNode.str;
	this->frequency = hNode.frequency;
	this->leftChild = (hNode.leftChild != nullptr) ? new HuffmanNode(*hNode.leftChild) : nullptr;
	this->rightChild = (hNode.rightChild != nullptr) ? new HuffmanNode(*hNode.rightChild) : nullptr;
}

/**
 * Dtor.
 * 
 */
HuffmanNode::~HuffmanNode()
{
	if (this->leftChild != nullptr) delete this->leftChild;
	if (this->rightChild != nullptr) delete this->rightChild;
	this->leftChild = this->rightChild = nullptr;
}

//getter functions
int HuffmanNode::getFrequency()
{
    return this->frequency;
}

string HuffmanNode::getStr()
{
    return this->str;
}

HuffmanNode* HuffmanNode::getLeft()
{
    return this->leftChild;
}

HuffmanNode* HuffmanNode::getRight()
{
    return this->rightChild;
}

/**
 * Assignment operator overload.
 */
HuffmanNode HuffmanNode::operator=(const HuffmanNode& hNode)
{
	this->str = hNode.str;
	this->frequency = hNode.frequency;
	this->leftChild = (hNode.leftChild != nullptr) ? new HuffmanNode(*hNode.leftChild) : nullptr;
	this->rightChild = (hNode.rightChild != nullptr) ? new HuffmanNode(*hNode.rightChild) : nullptr;

	return *this;
}
