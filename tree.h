#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <iterator>
#include <stdio.h>
#include <ctype.h>

//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
class Traversals
{
private:
	Node* root;
	string buffer;

public:
	Traversals();
	~Traversals();

	Node* createNode(char data);
	Node* buildTree(string fileName);
	Node* buildTree();
	string getString(char data);
	string cleanBuffer();
	void insertNode(Node*& node, string data);
	void deleteTree(Node* leaf);
	void printPostorder(Node* node, int depth, ofstream& file);
	void printInorder(struct Node* node, int depth, ofstream &file);
	void printPreorder(struct Node* node, int depth, ofstream& file);

};

#endif
