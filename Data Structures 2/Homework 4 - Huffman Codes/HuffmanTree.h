#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include "TreeEncodings.h"
#include "CodeForChar.h"
#include <stack>
#include <queue>
#include <list>

class HuffmanTree
{
private:
    HuffmanNode* root;
    std::string originalText;

    std::priority_queue<HuffmanNode> calculateFrequencies(std::string text = "");
    bool calcCodeOfLetter(HuffmanNode* current, std::string letter, std::stack<char>& codePath);
    void constructListOfCodes();
    std::string searchForCode(char c);

public:
    std::list<CodeForChar> codesTable;
    std::string traversal = "";
    std::string structure = "";
    std::string code = "";

    HuffmanTree(std::string text);
 
    void encode(std::string text);
    void decode(int numberLeaves, std::string lettersTraversal, std::string encodeStruct, std::string encodedStr, TreeEncodings te);
};

#endif // !HUFFMANTREE_H







