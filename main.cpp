// Name         :   CS4280 - Project 0
// Author       :   Amal Presingu
// Date         :   9/3/2022
// Description  :   Building and printing tree traversals from strings (keyboard input & files).
// Sources      :   https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
//					https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
//					https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
// 					https://math.hws.edu/eck/cs225/s03/binary_trees/
//					https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
//

#include "node.h"
#include "tree.h"
#include "empty.h"
using namespace std;

//using sample structure from project description
int main(int argc, char* argv[])
{
	string fileName = "output";
	ifstream file;
	//node_t* root = NULL;
	Node* ptr = NULL;
	Traversals tree;
	int depth = 1;

        //process command line arguments first and error if improper
	//using some of the command line logic from a 2750 project
	//P0 < somefile
	if (argc > 2)
	{
		//fileName = argv[1];
		ptr = tree.buildTree();
	}

	//P0
	else if (argc == 1)
	{
		//prompt user with instructions
		cout << "Please enter an alphanumeric string and press CTRL + D: ";
		//read from keyboard and build tree
		ptr = tree.buildTree();
	}

	//P0 somefile
	else if (argc == 2)
	{
	    string input;
            int i = 0;

		//assign user input to open file (if it exists)
		fileName = argv[1];
		file.open((fileName).c_str(), fstream::in);
		if (!file)
		{
		        //print error msg and exit if file DNE
			cout << "The given file does not exist." << endl;
			return 1;
    	}
		file.close();
		ptr = tree.buildTree(fileName);
	}

	//outlier case error msg
	else
	{
		cout << "Invalid input. Try again." << endl;
		return 1;
	}

	//check if this statement is needed or not
	if (!file)
	{
		cout << "File does not exist, try again." << endl;
	}

	//Output files: xxx.inorder xxx.preorder xxx.postorder
	//Output files: ouput.inorder output.preorder output.postorder
	//creating output files with given filename
	string finalName1 = (fileName + ".inorder");
	string finalName2 = (fileName + ".preorder");
	string finalName3 = (fileName + ".postorder");
	ofstream inorderFile(finalName1.c_str(), ios::out);
	ofstream preorderFile(finalName2.c_str(), ios::out);
	ofstream postorderFile(finalName3.c_str(), ios::out);

	//printing traversals to files with indents
	tree.printInorder(ptr, depth, inorderFile);
	tree.printPreorder(ptr, depth, preorderFile);
	tree.printPostorder(ptr, depth, postorderFile);
	cout << "The trees have been printed in the following files: " + (fileName + ".inorder" + ", " + fileName + ".preorder" + ", " + fileName + ".postorder") << endl;

	//close all files to prevent conflicts
	file.close();
	inorderFile.close();
	preorderFile.close();
	postorderFile.close();
	tree.deleteTree(ptr);

    return 0;
}
