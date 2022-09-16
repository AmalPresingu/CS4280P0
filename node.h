#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

//taking logic from first few lines of geeksforgeeks source
struct Node
{
	char data;
	Node* left;
	Node* right;
	Node* middle;
};

#endif
