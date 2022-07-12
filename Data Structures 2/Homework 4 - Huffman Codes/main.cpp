#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "HuffmanTree.h"
#include "TreeEncodings.h"
using namespace std;


int main()
{
	char choice;


	HuffmanTree* t;
	TreeEncodings te;
	string word;
	cout << "enter E to encode a text\n";
	cout << "enter D to decode a text\n";
	cout << "enter X to exit\n";

	do
	{
		cin >> choice;
		switch (choice)
		{
		case 'E':

			cout << "enter the original text" << endl;
			cin >> word;
			t = new HuffmanTree(word);
			cout << "The encoded string is\n";
			t->encode(word);
			te.allEncodings.push_back(t);
			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.


			break;
		case 'D':
			int n;
			string letters, structure, text;
			cout << "enter n\n";
			cin >> n;
			cout << "enter the letters\n";
			cin >> letters;
			cout << "enter the encoded structure\n";
			cin >> structure;
			cout << "enter the encoded text\n";
			cin >> text;
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 

			cout << "The decoded string is: ";
			t->decode(n, letters, structure, text, te);
		}

	} while (choice != 'X');
	return 0;
}