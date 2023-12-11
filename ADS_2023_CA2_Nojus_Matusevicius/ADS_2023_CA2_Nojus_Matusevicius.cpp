// ADS_2023_CA2_Nojus_Matusevicius.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://medium.com/lightning-strikes-a-developers-journey/breaking-down-std-string-npos-understanding-the-not-found-constant-a785b58313d7  - reading a line from xml file 
// https://cplusplus.com/reference/string/string/string/

#include <iostream>
#include "XMLParser.h"
#include "TreeIterator.h"
#include "Tree.h"
#include "DListNode.h"
#include "DListIterator.h"
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	XMLParser<string> parser("myfile.xml");
	bool result = parser.load();
if (result)
	{
		cout << "File loaded successfully" << endl;

		if(parser.hasRoot())
		{
			cout << "File has root" << endl;
			Tree<string>root("Root");
			TreeIterator<string>iterator(&root);
		}
		else
		{
			cout << "File does not have root" << endl;
		}
		
	}
	else
	{
		cout << "File not loaded" << endl;
	}

return 0;
}

