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

class App
{
public:
	int choice;
	App():choice(0) {}
	void run() {
		int choice;
		do {
			displayMenu();
			cout << "Enter your choice: ";
			cin >> choice;
			cin.ignore();

			switch (choice)
			{
			case 1:
				countItems();
				break;
			case 2:
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
			}
		} while (choice != 2);
	}
	private:

		void displayMenu()
		{	cout << "__________MENU________" << endl;
			cout << "1. Number of items in the document" << endl;
			cout << "2. Exit" << endl;
		}

		void countItems()
		{
			int numberOfItemsInDocument = 0;
			string filename = "myfile.xml";
			XMLParser<string> parser(filename);
			parser.load();
			//TreeIterator<string> iteratowROTEr(parser.hasRoot());
			//while (iterator.childValid())
			{
				numberOfItemsInDocument++;
				//iterator.childForth();
			}
			cout << "Number of items in the document: " << numberOfItemsInDocument << endl;
			}
	};


template <class T>
void displayTree(TreeIterator<T> iter, string indent)
{
	cout << indent << iter.node->data;
	if (iter.childValid())
	{
		cout << "(" << endl;
		while (iter.childValid())
		{
			TreeIterator<T> iter2(iter.childIter.item());
			displayTree(iter2, "\t" + indent);
			iter.childForth();
		}
		cout << indent << ")" << endl;
	}
	cout << endl;

}

void part1()
{
	XMLParser<string> parser("myfile.xml");
	bool result = parser.load();
	if (result)
	{
		cout << "File loaded successfully" << endl;

		if (parser.hasRoot())
		{

			parser.buildTree();
		//	Tree<string>* root = parser.getRoot();
			//TreeIterator<string> iter(root);
			//displayTree(iter, "");
			App myApp;
			myApp.run();
			//delete root;

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
}

int main()
{
 part1();

return 0;
}

