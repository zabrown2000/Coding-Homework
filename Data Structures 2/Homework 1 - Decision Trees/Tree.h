#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class DecisionTreeNode;

//Answer: for each answer, the string, and the pointer to the node where to continue
class Answer //parent to further node
{
public:
	string ans;
	DecisionTreeNode* son;//if null then ans is on leaf
	Answer(string s, DecisionTreeNode* p) { ans = s; son = p; }
};

//Node: each node in the decision tree
class DecisionTreeNode
{
	void removeSonValue(string v);
public:
	list<Answer*> answersList;
	string value;
	bool isLeaf; //if list is empty then node is leaf
	DecisionTreeNode(string v) { isLeaf = true;  value = v; }

	friend class Tree;
};


//Tree: the Decision Tree
class Tree
{
	DecisionTreeNode* root;
	DecisionTreeNode* search(DecisionTreeNode* p, string val, DecisionTreeNode*& parent); 
	//returns node t where the string equals val. If t has a parent, the pointer parent will contain its address. 

	bool searchAndPrint(DecisionTreeNode* p, string val); 
	void print(DecisionTreeNode* p, int level = 0); 
	void process(DecisionTreeNode* p); 
public:
	Tree() { root = NULL; } 
	Tree(string initial);
	~Tree() {    
		deleteAllSubTree(root); 
		root = 0;
	}
	void deleteAllSubTree(DecisionTreeNode* t);
	void addRoot(string newval); 
	bool addSon(string fatherquestion, string newanswer, string newval); 
	void searchAndPrint(string val)
	{
		if (!searchAndPrint(root, val))
			cout << "Value not found" << endl;
	}
	void searchAndPrintArea(string val)
	{
		DecisionTreeNode* parent;
		DecisionTreeNode* area = search(root, val, parent);
		if (area) print(root);
	}
	void printAllTree() { print(root); }
	string printToString(DecisionTreeNode* p) { return ""; }
	string printToString() { return printToString(root); }
	void deleteSubTree(string val);
	void process() { process(root); }
};

#endif // !TREE_H



