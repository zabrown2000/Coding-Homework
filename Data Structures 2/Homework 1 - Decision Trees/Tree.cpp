#include "Tree.h"

/**
 * Function to answer from a node's list.
 * 
 * \param v answer deleting from node
 */
void DecisionTreeNode::removeSonValue(string v)
{
	for (auto i = this->answersList.begin(); i != this->answersList.end(); i++)
	{
		if ((*i)->ans == v) 
		{
			i = this->answersList.erase(i); //removing 
		}
	}
}

/**
 * Function to seach for node containing a certain question.
 * 
 * \param p current node checking
 * \param val string looking for
 * \param parent 
 * \return node containing string, or null if not found
 */
DecisionTreeNode* Tree::search(DecisionTreeNode* p, string val, DecisionTreeNode*& parent)
{
	if (!p)
		return nullptr;

	if (p->value == val)
	{
		return p;
	}

	for (auto i = p->answersList.begin(); i != p->answersList.end(); i++)
	{
		search((*i)->son, val, parent);
	}
}

/**
 * Function to print the path to a question or decision.
 * 
 * \param p pointer to current node
 * \param val string searching for
 * \return if found at end 
 */
bool Tree::searchAndPrint(DecisionTreeNode* p, string val)
{
	if (val == p->value)
	{
		cout << val << endl;
		return true;
	}
	else if ((val != p->value) && (p->isLeaf))
	{
		return false;
	}
	else 
	{
		for (auto i = p->answersList.begin(); i != p->answersList.end(); i++)
		{
			if (val == (*i)->ans)
			{
				cout << val << "=>";
				return true;
			}
			else
			{
				return searchAndPrint((*i)->son, val);
			}
		}
	}


    
}

/**
 * Function to print out tree.
 * 
 * \param p root of tree
 * \param level current level in tree
 */
void Tree::print(DecisionTreeNode* p, int level)
{
	for (int i = 0; i < level; i++) //printing appropiate amount of spaces for a level
		cout << " ";

	cout << p->value << endl;

	for (auto i = p->answersList.begin(); i != p->answersList.end(); i++) 
	{
		cout << ": " << (*i)->ans << endl;
		print((*i)->son, level + 1); //going to next level of tree
	}
}

/**
 * Function to execute the decision process recursively.
 * 
 * \param p current node in decision process
 */
void Tree::process(DecisionTreeNode* p)
{
	cout << p->value;

	if (p->isLeaf) //printed final decision
		return;

	string userInput;
	bool validAnswer;
	do
	{
		cin >> userInput;
		validAnswer = false;
		for (auto i = p->answersList.begin(); i != p->answersList.end(); i++)
		{
			if (userInput == (*i)->ans)
			{
				validAnswer = true;
				process((*i)->son); //moving down tree
				break; //no need to finish loop when trace back recursion
			}
		}
		if (!validAnswer)
			cout << "Invalid answer, please try again\n";
	} while (!validAnswer);
}

/**
 * ctor that accepts string with initial question.
 * 
 * \param initial
 */
Tree::Tree(string initial)
{
    this->root = new DecisionTreeNode(initial);
}

/**
 * recursive function to delete the contents of a tree.
 * 
 * \param t root of tree to delete
 */
void Tree::deleteAllSubTree(DecisionTreeNode* t)
{
	if (t)
	{
		if (t->isLeaf) //base case
		{
			delete t;
			t = nullptr; 
			return;
		}

		for (auto i = t->answersList.begin(); i != t->answersList.end(); i++)
		{
			deleteAllSubTree((*i)->son); //tracing all sons of current answer and deleting 
		}
		delete t; //deleting node after deleted all sons
		t = nullptr;
	}
}

/**
 * function to start a new decision tree.
 * 
 * \param newval initial question to be in root of tree
 */
void Tree::addRoot(string newval)
{
	this->root = new DecisionTreeNode(newval);
}

/**
 * Function to add new son to tree.
 * 
 * \param fatherquestion strin used to find parent node
 * \param newanswer answer to be added to parent's answers list
 * \param newval value to be added new son 
 * \return 
 */
bool Tree::addSon(string fatherquestion, string newanswer, string newval)
{
	DecisionTreeNode *d = search(this->root, fatherquestion, this->root);

	if (!d)
		return false;

	DecisionTreeNode* newNode = new DecisionTreeNode(newval);
	d->answersList.push_back(new Answer(newanswer, newNode)); //sending new answer to list with new node as son

	if (d->isLeaf)
		d->isLeaf = false;

	return true;
}

/**
 * Function to delete a subtree starting with a given string.
 * 
 * \param val value of node whose subtree will be deleting
 */
void Tree::deleteSubTree(string val)
{
	//use seach to find node with val, and then call other delete function and send node
	DecisionTreeNode *toDelete = search(this->root, val, this->root);
	if (toDelete)
	{
		deleteAllSubTree(toDelete);
	}
}
