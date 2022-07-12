#include "HuffmanTree.h"
#include <iostream>
using namespace std;

HuffmanTree::HuffmanTree(std::string text)
{
	this->originalText = text;
	priority_queue<HuffmanNode> frequencies = calculateFrequencies(text);
	HuffmanNode left, right; //helper nodes to build the tree

	//now implementing huffman algo
	while (frequencies.size() > 1)
	{
		left = frequencies.top();
		frequencies.pop();
		right = frequencies.top();
		frequencies.pop();
		frequencies.push(HuffmanNode(left.getStr() + right.getStr(), left.getFrequency() + right.getFrequency(), &left, &right));
	}
	this->root = new HuffmanNode(frequencies.top());
	frequencies.pop();
	constructListOfCodes();
}

/**
 * Function to get the frequencies of each letter in the text.
 * 
 * \param text
 * \return priority queue of the frequencies
 */
priority_queue<HuffmanNode> HuffmanTree::calculateFrequencies(string text)
{
	int arrOfFreq[26] = { 0 };
	//calculating amt of times each letter shows up in text, assuming only lowercase letters
	for (int i = 0; i < text.length(); ++i)
	{
		arrOfFreq[text[i] - 'a']++;
	}

	priority_queue<HuffmanNode> freqQueue;
	//making nodes for all letters that appear in text
	for (int i = 0; i < 26; i++)
	{
		if (arrOfFreq[i] != 0)
		{
			string letter = (char*)('a' + i);
			freqQueue.push(HuffmanNode(letter, arrOfFreq[i]));
		}
	}
	return freqQueue;
}

/**
 * Function to locate a letter in a huffman tree and create the code for it.
 * 
 * \param current node up to
 * \param letter letter looking for
 * \param codePath stack with the code in it (passed by ref to use in funciton that called it)
 * \return true if code could be created, false if not
 */
bool HuffmanTree::calcCodeOfLetter(HuffmanNode* current, string letter, stack<char>& codePath)
{
	if (!current)
	{
		return false; //tree empty, so no code
	}
	if (current->getStr() == letter) //code for letter exists in tree, and code now compiled in stack
	{
		return true;
	}
	if (calcCodeOfLetter(current->getLeft(), letter, codePath)) //letter in left subtree
	{
		codePath.push('0'); //updating code path for letter
		return true;
	}
	if (calcCodeOfLetter(current->getRight(), letter, codePath)) //letter in right subtree
	{
		codePath.push('1'); //updating code path for letter
		return true;
	}
	return false; //if got to this point, letter not in tree, no code
}

/**
 * Function to build up a list of codes for all the letters found in a huffman tree.
 * 
 */
void HuffmanTree::constructListOfCodes()
{
	string newCode, letter;
	stack<char> codeReversed;

	for (int i = 0; i < 26; i++) //searching for code of each letter in the tree (if it exists)
	{
		string letter = (char*)(i + 'a');
		if (calcCodeOfLetter(this->root, letter, codeReversed)) //checking to see if code for letter in tree, will put it in stack
		{
			while (!codeReversed.empty())
			{
				newCode += codeReversed.top(); //gathering code into string
				codeReversed.pop();
			}
			this->codesTable.push_back(CodeForChar((i + 'a'), newCode)); //adding current letter with its code to the table
		}
	}
	this->codesTable.sort(); //making sure sorted in alphabetical order
}

/**
 * Function to search for the code of a letter in the codes table.
 * 
 * \param c letter searching for
 * \return  the code if letter found
 */
string HuffmanTree::searchForCode(char c)
{
	for (auto it = this->codesTable.begin(); it != this->codesTable.end(); ++it)
	{
		if ((*it).letterToCode == c)
		{
			return (*it).code;
		}
	}
	return nullptr; //no code for that letter
}

/**
 * Function to encode a given text.
 * 
 * \param text
 */
void HuffmanTree::encode(string text)
{
	//1. The first line in the encoding file will contain the number
	cout << this->codesTable.size() << endl;

	//2. The second line contains the characters, as they appear in an in-order traversal   
	for (auto it = this->codesTable.begin(); it != this->codesTable.end(); ++it)
	{
		traversal += (*it).letterToCode;
	}
	cout << traversal << endl;                                                  //save these things for when decode?

	//3. The third line contains the representation of the tree structure
	for (auto it = this->codesTable.begin(); it != this->codesTable.end(); ++it)
	{
		structure += (*it).code;
	}
	cout << structure << endl;

	//4. The fourth line contains the encoded text 
	for (int i = 0; i < text.length(); ++i)
	{
		code += searchForCode(text[i]);
	}
	cout << code << endl;
}

/**
 * Function to decode a string to its original text.
 * 
 * \param numberLeaves
 * \param lettersTraversal
 * \param encodeStruct
 * \param encodedStr
 * \param te
 */
void HuffmanTree::decode(int numberLeaves, string lettersTraversal, string encodeStruct, string encodedStr, TreeEncodings te)
{
	if (!te.allEncodings.empty()) //have some codes in here
	{
		//searching to see if already created code wiith given info
		for (auto it = te.allEncodings.begin(); it != te.allEncodings.end(); ++it)
		{
			if ((*it)->code == encodedStr)
			{
				cout << (*it)->originalText << endl;
				return;
			}
		}
	}
	cout << "ERROR\n"; //no codes exists for this encryption
}
