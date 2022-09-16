#include "empty.h"

//checking if the user entered an empty file
void emptyCheck(ifstream& file, string fileName)
{
	string input;
	int i = 0;
	while (getline(file, input))
	{
		i++;
	}
	//if nothing detected, print error msg
	if (i == 0)
	{
		cout << "The file that you entered is empty." << endl;
	}
	file.close();
}

