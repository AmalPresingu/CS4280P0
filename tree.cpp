#include "tree.h"
using namespace std;

//Constructor & Desctructor https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
Traversals::Traversals()
{
	root = NULL;
	buffer = "";
	return;
}

Traversals::~Traversals()
{}

//P0 somefile invocation
Node* Traversals::buildTree(string fileName)
{
	ifstream file;
	string input;
	string temp;

	Node* ptr = NULL;
	//parse through opened file and insert into binary tree
	file.open((fileName).c_str(), fstream::in);
	//cout << fileName;
	if (file)
	{
		//going through each value in file
		while (file >> input)
		{
		    for (int i = 0; i < input.size(); i++)
		    {
		        if (!isalnum(input.at((unsigned int) i)))
		        {
		            cout << "Invalid input. Please only enter alphanumeric characters." << endl;
		            return NULL;
		        }
		    }
			//look for alphanumeric chars and add it to the buffer + insert
			temp = input;
			buffer += input + ' ';
			insertNode(root, input);
		}
	}
	ptr = root;
	file.close();
	return ptr;
}

//P0 invocation (read from keyboard)
Node* Traversals::buildTree()
{
	string input;
	Node* ptr = NULL;
	while (cin >> input)
	{
	    for (int i = 0; i < input.size(); i++)
		    {
		        if (!isalnum(input.at((unsigned int) i)))
		        {
		            cout << "Invalid input. Please only enter alphanumeric characters." << endl;
		            return NULL;
		        }
		    }
    	//until simulated EOF, store user input into buffer
    	buffer += input + ' ';
    	insertNode(ptr, input);
	}
	return ptr;
}

//create node
Node* Traversals::createNode(char data)
{
	Node* val = new Node();
	val -> data = data;
	val -> right = val -> left = NULL;
	return val;
}

//inserts to first alphanum char
void Traversals::insertNode(Node*& root, string data)
{
	if (root == NULL)
	{
		//first position
		root = createNode(data[0]);
	}
	else if (root -> data == data[0])
	{
		//do nothing if the letter/branch has already been created
	}
	else if (root -> data > data[0])
	{
		//left branch
		insertNode(root -> left, data);
	}
	else
	{
		//right branch
		insertNode(root -> right, data);
	}
}

//remove duplicate strings and insert into hashset
string Traversals::cleanBuffer()
{
	string duplicateBuffer;
	istringstream ss(buffer);
	ostringstream stream;
	set<string> hash;

    //insert new words into hash
	do
	{
		string alpha;
		ss >> alpha;
		while (hash.find(alpha) == hash.end())
		{
			hash.insert(alpha);
		}
	} while(ss);

	copy(hash.begin(), hash.end(), ostream_iterator<string>(stream, " "));
	duplicateBuffer = stream.str();
	return duplicateBuffer;
}

//return string that start with the same char
string Traversals::getString(char data)
{
	//will check if first letters match and store them in count
	string check = "";
	string count = "";

	string clean = cleanBuffer();
	istringstream iss(clean);

	//check strings
	while (iss >> check)
	{
		if (data == check[0])
		{
			count += check + ' ';
		}
	}
	return count;
}

//called in main
void Traversals::deleteTree(Node* leaf)
{
	if (leaf != NULL)
	{
		deleteTree(leaf -> left);
		deleteTree(leaf -> right);
		delete leaf;
		leaf = NULL;
	}
}

//not sure if these need to be printed in a separate file, but doing here for simplicity
//print inorder traversal
void Traversals::printInorder(struct Node* node, int depth, ofstream &file)
{
	string alpha = "";
	if (node == NULL)
	{
		return;
	}
	
	//starting with left child and printing node
	//multiplying depth by 2 when printing
	printInorder(node -> left, depth * 2, file);
	alpha = getString(node -> data);

	for (int i = 0; i < depth; i++)
	{
		file << "\t";
	}

    //formatting tree from example in description
	file << node -> data << ": " << alpha << " " << endl;
	printInorder(node -> right, depth * 2, file);
}

//print preorder traversal
void Traversals::printPreorder(struct Node* node, int depth, ofstream& file)
{
	string alpha = "";
	if (node == NULL)
	{
		return;
	}

	alpha = getString(node -> data);
	for (int i = 0; i < depth; i++)
	{
		file << "\t";
	}

	file << node -> data << ": " << alpha << " " << endl;


	printPreorder(node -> left, depth * 2, file);
	printPreorder(node -> right, depth * 2, file);
}

//print postorder traversal
void Traversals::printPostorder(struct Node* node, int depth, ofstream& file)
{
    string alpha = "";
	if (node == NULL)
	{
		return;
	}

	printPostorder(node -> left, depth * 2, file);
	printPostorder(node -> right, depth * 2, file);

	alpha = getString(node -> data);
	for (int i = 0; i < depth; i++)
	{
	    file << "\t";
	}

	file << node -> data << ": " << alpha << " " << endl;
}
